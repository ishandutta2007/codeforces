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

int a[12], n, _;

bool dfs(int id, int s, bool c) {
    if (id == n) {
        return s == 0 && c;
    }
    if (dfs(id + 1, s, c)) return true;
    if (dfs(id + 1, s + a[id], true)) return true;
    if (dfs(id + 1, s - a[id], true)) return true;
    return false;
}

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        bool ok = dfs(0, 0, false);
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
5
5
4 -7 -1 5 10
1
0
3
1 10 100
4
-3 2 10 2
9
25 -171 250 174 152 242 100 -205 -258
*/