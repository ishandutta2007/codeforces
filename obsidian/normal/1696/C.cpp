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
const int V = 50010;
int _, n, m, K, a[V], b[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
        vector<int> c, d;
        vector<LL> cc, dd;
        int pre = -1;
        LL cnt = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = 1;
            while (a[i] % K == 0) {
                a[i] /= K;
                tmp *= K;
            }
            if (a[i] == pre) cnt += tmp;
            else {
                c.PB(pre);
                cc.PB(cnt);
                pre = a[i];
                cnt = tmp;
            }
        }
        c.PB(pre);
        cc.PB(cnt);

        pre = -1;
        cnt = 0;
        for (int i = 0; i < m; ++i) {
            int tmp = 1;
            while (b[i] % K == 0) {
                b[i] /= K;
                tmp *= K;
            }
            if (b[i] == pre) cnt += tmp;
            else {
                d.PB(pre);
                dd.PB(cnt);
                pre = b[i];
                cnt = tmp;
            }
        }
        d.PB(pre);
        dd.PB(cnt);
        bool ok = true;
        if (c.size() != d.size()) ok = false;
        for (int i = 0; i < min(c.size(), d.size()); ++i) {
            if (c[i] != d[i]) ok = false;
            if (cc[i] != dd[i]) ok = false;
        }
        if (ok) puts("Yes");
        else puts("No");
    }
    return 0;
}

/*
5
5 2
1 2 2 4 2
4
1 4 4 2
6 2
1 2 2 8 2 2
2
1 16
8 3
3 3 3 3 3 3 3 3
4
6 6 6 6
8 3
3 9 6 3 12 12 36 12
16
9 3 2 2 2 3 4 12 4 12 4 12 4 12 4 4
8 3
3 9 6 3 12 12 36 12
7
12 2 4 3 4 12 56
*/