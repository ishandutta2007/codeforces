#include <bits/stdc++.h>
using namespace std;

int N, M, S, T, K, d[500005], fr[500005], par[500005];
bool ranger[500005];
vector<int> V[500005];
vector< pair< int, pair<int, int> > > edgelist;
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > PQ;

int fp(int x) {
    if (par[x] == x) return x;
    else return par[x] = fp(par[x]);
}

void merge(int x, int y) {
    x = fp(x);
    y = fp(y);
    par[x] = y;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < K; i++) {
        int x;
        scanf("%d", &x);
        x--;
        ranger[x] = 1;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    scanf("%d%d", &S, &T);
    S--;
    T--;
    memset(d, 63, sizeof(d));
    ranger[T] = 1;
    d[S] = 0;
    int maxi = 0;
    PQ.push(make_pair(0, S));
    while (!PQ.empty()) {
        int node = PQ.top().second, dist = PQ.top().first;
        PQ.pop();
        if (dist > d[node]) continue;
        if (node == T) {
            printf("%d\n", maxi);
            return 0;
        }
        for (int i = 0; i < V[node].size(); i++) {
            int newnode = V[node][i], newdist = dist + 1;
            if (ranger[newnode]) newdist = 0;
            if (d[newnode] > newdist) {
                maxi = max(maxi, dist + 1);
                d[newnode] = newdist;
                PQ.push(make_pair(newdist, newnode));
            }
        }
    }
    printf("-1\n");
}