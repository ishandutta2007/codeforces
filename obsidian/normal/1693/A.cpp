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
int a[V], _, n;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        if (a[1] == 0) {
            bool all_0 = true;
            for (int i = 1; i <= n; ++i) if (a[i] != 0) all_0 = false;
            if (all_0) puts("Yes");
            else puts("No");
            continue;
        }
        LL s = 0;
        bool ok = true;
        if (a[1] > 0) --a[1];
        else ok = false;
        int last = 0;
        for (int i = 1; i <= n; ++i) if (a[i] < 0) last = i;
        if (last == 0) ok = false;
        else ++a[last];
        for (int i = 1; i <= n; ++i) {
            s += a[i];
            if (s < 0) ok = false;
        }
        if (s != 0) ok = false;
        if (ok) puts("Yes");
        else puts("No");
    }
    return 0;
}

/*
7
2
1 0
4
2 -1 -1 0
4
1 -4 3 0
4
1 -1 1 -1
5
1 2 3 4 -10
7
2 -1 1 -2 0 0 0
1
0
*/