#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
using namespace std;

const int AB_MAX = 1e6 + 5;
const int INF = 1e9 + 5;
const int MAX_SUM = 22, MAX_DIVISORS = 288;

vector<int> smallest_factor;
vector<bool> prime;

int N;
map<vector<int>, int> exp_index;
vector<vector<int>> exp_list;
vector<vector<int>> dist;
vector<vector<int>> same_cost;

void sieve(int maximum) {
    assert(maximum > 0);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p <= maximum; p += 2) {
        prime[p] = p == 2;
        smallest_factor[p] = 2;
    }

    for (int p = 3; p * p <= maximum; p += 2)
        if (prime[p])
            for (int i = p * p; i <= maximum; i += 2 * p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }

    for (int p = 3; p <= maximum; p += 2)
        if (prime[p])
            smallest_factor[p] = p;
}

int get_or_create_index(const vector<int> &exponents) {
    if (exp_index.count(exponents) == 0) {
        exp_index[exponents] = exp_list.size();
        exp_list.push_back(exponents);

        for (auto &v : dist)
            if (v.size() < exp_list.size()) {
                v.push_back(INF);
                assert(v.size() >= exp_list.size());
            }
    }

    return exp_index[exponents];
}

int divisor_count(const vector<int> &exponents) {
    int divisors = 1;

    for (int e : exponents)
        divisors *= e + 1;

    return divisors;
}

void iterate_neighbors(vector<int> exponents, auto &&func) {
    int n = exponents.size();

    for (int i = 0; i < n; i++)
        if (i == 0 || exponents[i] != exponents[i - 1]) {
            exponents[i]++;
            func(exponents);
            exponents[i]--;
        }

    exponents.push_back(1);
    func(exponents);
    exponents.pop_back();

    for (int i = 0; i < n; i++)
        if (i == n - 1 || exponents[i] != exponents[i + 1]) {
            bool remove = exponents[i] == 1;

            if (remove)
                exponents.pop_back();
            else
                exponents[i]--;

            func(exponents);

            if (remove)
                exponents.push_back(1);
            else
                exponents[i]++;
        }
}

void bfs(int start) {
    vector<int> queue;
    int q_front = 0;
    dist[start][start] = 0;
    queue.push_back(start);
    int N_seen = 1;

    while (q_front < (int) queue.size() && N_seen < N) {
        int current = queue[q_front++];
        vector<int> exponents = exp_list[current];

        iterate_neighbors(exponents, [&](const vector<int> &neighbor) {
            int sum = accumulate(neighbor.begin(), neighbor.end(), 0);
            int divisors = divisor_count(neighbor);

            if (sum > MAX_SUM || divisors > MAX_DIVISORS)
                return;

            int index = get_or_create_index(neighbor);

            if (dist[start][current] + 1 < dist[start][index]) {
                dist[start][index] = dist[start][current] + 1;
                queue.push_back(index);

                if (index < N)
                    N_seen++;
            }
        });
    }
}

vector<int> number_to_exponents(int n) {
    vector<int> exponents;

    while (n > 1) {
        int p = smallest_factor[n], e = 0;

        do {
            n /= p;
            e++;
        } while (n % p == 0);

        exponents.push_back(e);
    }

    sort(exponents.rbegin(), exponents.rend());
    return exponents;
}

void precompute() {
    sieve(AB_MAX);

    for (int i = 1; i <= AB_MAX; i++) {
        vector<int> exponents = number_to_exponents(i);
        get_or_create_index(exponents);
    }

    N = exp_list.size();
    dist.assign(N, vector<int>(N, INF));
    cerr << N << " exp lists\n";

    for (int i = 0; i < N; i++)
        bfs(i);

    same_cost.assign(N, vector<int>(N, INF));
    map<int, vector<int>> div_count_map;

    for (int i = 0; i < (int) exp_list.size(); i++)
        div_count_map[divisor_count(exp_list[i])].push_back(i);

    cerr << div_count_map.size() << " div counts\n";

    for (auto &p : div_count_map) {
        auto &vec = p.second;
        vector<int> costs(N, INF);

        for (int index : vec)
            for (int i = 0; i < N; i++)
                costs[i] = min(costs[i], dist[i][index]);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                same_cost[i][j] = min(same_cost[i][j], costs[i] + costs[j]);
    }

    uint64_t hash = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            hash = 37 * hash + same_cost[i][j];

    cerr << "hash: " << hash << endl;
}

int query(int a, int b) {
    a = exp_index[number_to_exponents(a)];
    b = exp_index[number_to_exponents(b)];
    return same_cost[a][b];
}

int main() {
    precompute();

    int T;

    for (scanf("%d", &T); T > 0; T--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", query(a, b));
    }
}