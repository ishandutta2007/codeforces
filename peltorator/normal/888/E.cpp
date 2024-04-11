#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 100001, M = 37;

ll q[N];

int v[M][N];

vector<ll> a;

vector<ll> b;

int main()
{
   //freopen("in.txt", "r", stdin);
 //   cout.precision(100);
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    /*if (m < N - 10)
    {
        dp[0][0] = 1;
        dp[0][q[0]] = 1;
        for (int i = 0; i + 1 < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (!dp[i][j])
                    continue;
                dp[i + 1][j] = 1;
                dp[i + 1][(j + a[i]) % m] = 1;
            }
        for (int j = m - 1; j >= 0; j--)
            if (dp[n - 1][j])
            {
                cout << j;
                return 0;
            }
    }*/
    int k = n / 2;
    int l = n - k;
    int B = (1 << k);
    for (int i = 0; i < B; i++)
    {
        ll ans = 0;
        for (int j = 0; j < k; j++)
            if ((i & (1 << j)))
                ans += q[j];
        ans %= m;
        a.push_back(ans);
    }
    sort(a.begin(), a.end());
    B = (1 << l);
    for (int i = 0; i < B; i++)
    {
        ll ans = 0;
        for (int j = 0; j < l; j++)
            if ((i & (1 << (j))))
                ans += q[j + k];
        ans %= m;
        b.push_back(ans);
    }
    ll ans = (a.back() + b.back()) % m;
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++)
    {
        int l = -1, r = b.size();
        while (r - l > 1)
        {
            int mid = (r + l) / 2;
            if (a[i] + b[mid] >= m)
                r = mid;
            else
                l = mid;
        }
        if (l != -1)
            ans = max(ans, b[l] + a[i]);
    }
    cout << ans;
    return 0;
}