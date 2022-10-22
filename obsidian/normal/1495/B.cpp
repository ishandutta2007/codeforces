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
int l[V], r[V], a[V], mx[V], n;

bool check() {
    for (int i = 1; i <= n; ++i) mx[i] = max(l[i], r[i]);
    int id = -1;
    for (int i = 1; i <= n; ++i) {
        if (id == -1 || mx[id] < mx[i]) id = i;
    }
    for (int i = 1; i <= n; ++i) {
        if (i != id && mx[i] == mx[id]) return false;
    }
    if (l[id] == r[id] && l[id] % 2 == 1) return true;
    /*
    int use = (mx[id] - 1) / 2 + 1;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (l[i] >= use) cnt++;
        if (r[i] >= use) cnt++;
    }
    if (cnt > 1) return false;
    return true;
    */
    return false;
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        l[1] = 1, r[n] = 1;
        for (int i = 2; i <= n; ++i) {
            if (a[i] > a[i - 1]) l[i] = l[i - 1] + 1;
            else l[i] = 1;
        }
        for (int i = n - 1; i > 0; --i) {
            if (a[i] > a[i + 1]) r[i] = r[i + 1] + 1;
            else r[i] = 1;
        }
        if (check()) puts("1");
        else puts("0");
    }
    return 0;
}

/*
5
1 2 5 4 3

7
1 2 4 6 5 3 7
*/