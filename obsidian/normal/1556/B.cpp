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
int _m, n, a[V], _;

int cal(int x) {
    vector<int> p;
    for (int i = 0; i < n; ++i) if (a[i] == x) p.PB(i);
    vector<int> d;
    for (int i = 0; i < n; i += 2) d.PB(i);
    if (p.size() != d.size()) return -1;
    int ans = 0;
    for (int i = 0; i <p.size(); ++i) ans += abs(p[i] - d[i]);
    return ans;
}

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) a[i] %= 2;
        int ans = cal(0);
        int a1 = cal(1);
        if (ans == -1 || (a1 != -1 && ans > a1)) ans = a1;
        printf("%d\n", ans);
    }
    return 0;
}

/*
5
3
6 6 1
1
9
6
1 1 1 2 2 2
2
8 6
6
6 2 3 4 5 1
*/