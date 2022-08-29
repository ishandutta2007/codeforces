#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 2);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (long long p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (long long i = p * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

int get_prime_index(int p) {
    auto it = lower_bound(primes.begin(), primes.end(), p);
    assert(it != primes.end() && *it == p);
    return it - primes.begin();
}

vector<int> transform(int a) {
    vector<int> v;

    while (a > 1) {
        int p = smallest_factor[a];
        int exponent = 0;

        do {
            a /= p;
            exponent++;
        } while (a % p == 0);

        if (exponent % 2 != 0)
            v.push_back(get_prime_index(p) + 1);
    }

    while (v.size() < 2)
        v.push_back(0);

    return v;
}

const int INF = 1e9 + 5;

struct BFS {
    struct edge {
        int node = -1, weight = -1;

        edge() {}

        edge(int _node, int _weight) : node(_node), weight(_weight) {}
    };

    int n;
    vector<vector<edge>> adj;
    vector<int> dist;
    vector<int> parent;

    BFS(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
    }

    void add_directional_edge(int a, int b, int weight) {
        adj[a].emplace_back(b, weight);
    }

    void add_bidirectional_edge(int a, int b, int weight) {
        add_directional_edge(a, b, weight);
        add_directional_edge(b, a, weight);
    }

    void bfs_check(queue<int> &q, queue<int> &next_q, int node, int from, int new_dist, int add) {
        assert(0 <= add && add <= 1);

        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            parent[node] = from;
            (add == 0 ? q : next_q).push(node);
        }
    }

    void bfs(const vector<int> &source) {
        if (n == 0) return;

        // Two queues are needed for 0-1 BFS.
        queue<int> q, next_q;
        dist.assign(n, INF);
        parent.assign(n, -1);

        for (int src : source)
            bfs_check(q, next_q, src, -1, 0, 0);

        int level = 0;

        while (!q.empty() || !next_q.empty()) {
            while (!q.empty()) {
                int top = q.front(); q.pop();

                if (level > dist[top])
                    continue;

                for (edge &e : adj[top])
                    bfs_check(q, next_q, e.node, top, dist[top] + e.weight, e.weight);
            }

            swap(q, next_q);
            level++;
        }
    }
};


const int A_MAX = 1e6 + 5;
int P;

int N;
vector<int> A;
vector<vector<int>> values;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(A_MAX);
    P = primes.size();

    cin >> N;
    A.resize(N);
    values.resize(N);
    set<vector<int>> seen;
    bool two = false;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        values[i] = transform(A[i]);

        if (values[i][0] == values[i][1]) {
            cout << 1 << '\n';
            return 0;
        }

        if (!seen.insert(values[i]).second)
            two = true;
    }

    if (two) {
        cout << 2 << '\n';
        return 0;
    }

    BFS bfs(P);

    for (int i = 0; i < N; i++)
        bfs.add_bidirectional_edge(values[i][0], values[i][1], 1);

    auto &&shortest_cycle = [&](int p) {
        bfs.bfs({p});
        int shortest = INF;

        for (int i = 0; i < N; i++)
            if (values[i].size() == 2) {
                int a = values[i][0], b = values[i][1];

                if (bfs.parent[a] != b && bfs.parent[b] != a)
                    shortest = min(shortest, bfs.dist[a] + bfs.dist[b] + 1);
            }

        return shortest;
    };

    int answer = shortest_cycle(0);

    for (long long p : primes)
        if (p * p <= A_MAX)
            answer = min(answer, shortest_cycle(get_prime_index(p) + 1));

    cout << (answer < INF ? answer : -1) << '\n';
}