#include <bits/stdc++.h>

using namespace std;


struct edge {
    int from;
    int to;
    int w;
};

std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());

int MOD = rnd() % 500000000 + 500000000;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}

void add(int & a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int mul(int a, int b) {
    return (int) ((long long) a * b % MOD);
}

long long const INF = 1LL << 60;

int n;

int const N = 123456;

vector<edge> edges[N], redges[N];
long long d1[N], d2[N];
int ways1[N], ways2[N];
edge alledges[N];

void shortest(int start, long long * d, int * ways) {
    for (int i = 0; i < n; i++) d[i] = INF;
    d[start] = 0;
    ways[start] = 1;
    set<pair<long long, int> > q;
    q.insert({d[start], start});
    while (!q.empty()) {
        auto e = *q.begin();
        q.erase(q.begin());
        int v = e.second;
        for (edge & e : edges[v]) {
            if (d[e.to] > d[e.from] + e.w) {
                q.erase({d[e.to], e.to});
                ways[e.to] = ways[e.from];
                d[e.to] = d[e.from] + e.w;
                q.insert({d[e.to], e.to});
            } else if (d[e.to] == d[e.from] + e.w) {
                add(ways[e.to], ways[e.from]);
            }
        }
    }
}

int main() {
    while (!isPrime(MOD)) ++MOD;
    int m, st, fin;
    scanf("%d%d%d%d", &n, &m, &st, &fin);
    --st;
    --fin;
    for (int i = 0; i < m; i++) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w);
        --from;
        --to;
        edges[from].push_back({from, to, w});
        redges[to].push_back({to, from, w});
        alledges[i] = {from, to, w};
    }
    shortest(st, d1, ways1);
    for (int i = 0; i < n; i++) edges[i].swap(redges[i]);
    shortest(fin, d2, ways2);
    for (int i = 0; i < n; i++) edges[i].swap(redges[i]);
    long long best = d1[fin];
    long long ways = ways1[fin];
    for (int i = 0; i < m; i++) {
        edge & e = alledges[i];
        if (d1[e.from] + d2[e.to] + e.w == best && mul(ways1[e.from], ways2[e.to]) == ways) {
            puts("YES");
        } else {
            long long need = (best - 1) - d1[e.from] - d2[e.to];
            if (need >= 1) {
                printf("CAN %I64d\n", e.w - need);
            } else puts("NO");
        }
    }
}