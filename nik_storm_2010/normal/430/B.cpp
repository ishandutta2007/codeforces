#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 500;

int a[N];

int main()
{
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i + 1] || a[i] != x) continue;
        int l = i, r = i + 1, cur = 0;
        while (true)
        {
            if (l == 0 || r > n) break;
            if (a[l] != a[r]) break;
            int ql = l, qr = r;
            while (ql >= 1 && a[ql] == a[l]) ql--;
            while (qr <= n && a[qr] == a[r]) qr++;
            if (l - ql + qr - r < 3 && l != i) break;
            cur += l - ql + qr - r;
            l = ql, r = qr;
        }
        ans = max(ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}