#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 500100;
vector<int> Q[2];
int vis[V], _, n, x;
int main() {
    memset(vis, 0, sizeof(vis));
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        int cur = 0;
        Q[cur].clear();
        int zero = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            if (x == 0) ++zero;
            else Q[cur].PB(x);
        }
        if (zero == n) {puts("0"); continue;}
        while (true) {
            for (int i = 0; i < Q[cur].size(); ++i) vis[Q[cur][i]] = 0;
            //for (int i = 0; i < Q[cur].size(); ++i) printf("%d ", Q[cur][i]); printf("Z %d\n", zero);
            if (Q[cur].size() == 0) {
                printf("%d\n", 0);
                break;
            }
            if (Q[cur].size() == 1) {
                printf("%d\n", Q[cur][0]);
                break;
            }
            int nxt = 1 - cur;
            sort(Q[cur].begin(), Q[cur].end());
            Q[nxt].clear();
            if(zero > 0) { --zero; Q[nxt].PB(Q[cur][0]);}
            for (int i = 1; i < Q[cur].size(); ++i) {
                if (Q[cur][i] == Q[cur][i - 1]) {++zero; continue;}
                int d = Q[cur][i] - Q[cur][i - 1];
                Q[nxt].PB(d);
            }
            cur = nxt;
        }
    }
    return 0;
}

/*
5
3
1 10 100
4
4 8 9 13
5
0 0 0 8 13
6
2 4 8 16 32 64
7
0 0 0 0 0 0 0
*/