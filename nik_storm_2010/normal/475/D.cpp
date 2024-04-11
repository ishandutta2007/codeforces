#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 2e5;
const int LOG = 18;

int a[N], f[N][LOG], step[N];
map <int, ll> base;

int gcd(int x, int y) {
    if (y == 0) return x; else return gcd(y, x % y);
}

void make(int n) {
    for (int i = 1; i <= n; i++) f[i][0] = a[i];
    for (int j = 1; j < LOG; j++) for (int i = 1; i <= n; i++) {
        int to = i + (1 << (j - 1));
        if (to <= n) f[i][j] = gcd(f[i][j - 1], f[to][j - 1]);
    }
}

int get(int l, int r) {
    int le = r - l + 1;
    return gcd(f[l][step[le]], f[r - (1 << step[le]) + 1][step[le]]);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    make(n);
    step[1] = 0;
    int have = 1, cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (have * 2 < i) have *= 2, cnt++;
        step[i] = cnt;
    }
    for (int i = 1; i <= n; i++) {
        int x = i;
        while (x <= n) {
            int was = get(i, x);
            int l = x, r = n + 1;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (get(i, m) == was) l = m; else r = m;
            }
            base[was] += (l - x + 1);
            x = l + 1;
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int x;
        scanf("%d", &x);
        printf("%I64d\n", base[x]);
    }
    return 0;
}