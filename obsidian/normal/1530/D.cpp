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
const int V = 200100;
int a[V], b[V], f[V], _, n;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) f[i] = -1;
        vector<int> from, to, same;
        for (int i = 1; i <= n; ++i) {
            if (f[a[i]] == -1) {
                f[a[i]] = i;
                b[i] = a[i];
            } else {
                from.PB(i);
            }
        }
        for (int i = 1; i <= n; ++i) if (f[i] == -1) to.PB(i);
        printf("%d\n", n - from.size());
        //sort(from.begin(), from.end());
        //sort(to.begin(), to.end());
        for (int i = 0; i < from.size(); ++i) {
            if (from[i] == to[i]) same.PB(from[i]);
            else b[from[i]] = to[i];
        }
        //for (int i = 0; i < from.size(); ++i) printf("%d ", from[i]); puts(" From");
        //for (int i = 0; i < to.size(); ++i) printf("%d ", to[i]); puts(" To");
        //for (int i = 0; i < same.size(); ++i) printf("%d ", same[i]); puts(" Same");
        if (same.size() == 1) {
            int u = same[0];
            int v = a[u];
            //printf("%d %d %d\n", u, v, f[v]);
            b[f[v]] = u;
            b[u] = a[u];
        } else if (same.size() > 1) {
            for (int i = 0; i < same.size(); ++i) {
                int u = same[i];
                int v = same[(i + 1) % same.size()];
                b[u] = v;
            }
        }
        for (int i = 1; i <= n; ++i) printf("%d ", b[i]); puts("");
    }
    return 0;
}

/*
2
3
2 1 2
7
6 4 6 2 4 5 6
*/