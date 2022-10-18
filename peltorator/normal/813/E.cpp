#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <math.h>
#include <set>
#include <stdio.h>
#include <cstring>
#include <memory.h>
#include <map>
#include <complex>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef  double ld;

const int MAXN = 100001, T = 340;

int a[MAXN];
int res[MAXN];
int answ[T][T];
int b[MAXN], used[MAXN];
int c[MAXN], used1[MAXN];
int qq[T][MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);
    for (int i = 0; i < MAXN; i++)
        used1[i] = used[i] = -1;
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int t = min(max(1, (int)sqrt(n)), n);
    for (int i = t - 1, j = 0; i < n; i = min(i + t, n - 1), j++)
    {
        for (int l = i; l >= 0; l--)
        {
            qq[j][a[l]]++;
            if (qq[j][a[l]] <= k)
                res[j]++;
            if (l % t == 0)
                answ[l / t][j] = res[j];
        }
        if (i == n - 1)
        {
            break;
        }
    }
    int last = 0;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        int l = (x + last) % n, r = (y + last) % n;
        if (r < l)
            swap(r, l);
        //cout << l + 1 << " " << r + 1 << endl;
        if (r - l <= 3 * t)
        {
         //   b.clear();
            int ans = 0;
            for (int j = l; j <= r; j++)
            {
                if (used[a[j]] != i)
                    used[a[j]] = i, b[a[j]] = 0;
                b[a[j]]++;
                if (b[a[j]] <= k)
                    ans++;
            }
            cout << ans << "\n";
            last = ans;
            continue;
        }
        int ans = 0;
        int st = 0, l1 = 0;
        while (l1 < l)
            l1 += t, st++;
        int fin = -1, r1 = -1;
        while (r1 + t <= r)
            r1 += t, fin++;
        //cout << l1 << " " << st << " " << r1 << " " << fin << endl;
        if (fin >= st)
            ans = answ[st][fin];
      //  b.clear();
        for (int j = l; j < l1; j++)
        {
            if (used[a[j]] != i)
                    used[a[j]] = i, b[a[j]] = 0;
            if (b[a[j]] + qq[fin][a[j]] - (st == 0 ? 0 : qq[st - 1][a[j]]) < k)
                ans++;
            b[a[j]]++;
        }
        for (int j = r1 + 1; j <= r; j++)
        {
            if (used[a[j]] != i)
                    used[a[j]] = i, b[a[j]] = 0;
            if (b[a[j]] + qq[fin][a[j]] - (st == 0 ? 0 : qq[st - 1][a[j]]) < k)
                ans++;
            b[a[j]]++;
        }
        cout << ans << "\n";
        last = ans;
    }
    return 0;
}