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
const int V = 100100;
int _, n, u, v, w;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        int mi = P, mx = 0, mic = P, mxc = P;
        int one = 2 * P;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            if (u < mi) {
                mi = u, mic = w;
                one = 2 * P;
            } else if (u == mi) mic = min(mic, w);

            if (v > mx) {
                mx = v, mxc = w;
                one = 2 * P;
            } else if (v == mx) mxc = min(mxc, w);
            if (u == mi && v == mx) one = min(one, w);
            printf("%d\n", min(one, mic + mxc));
        }
    }
    return 0;
}

/*
3
2
2 4 20
7 8 22
2
5 11 42
5 11 42
6
1 4 4
5 8 9
7 8 7
2 10 252
1 11 271
1 10 1
*/