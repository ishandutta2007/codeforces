#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e3 + 27;

int dist[MAXN][MAXN];
int cnt[MAXN];

int is_prime[MAXN];

int cc[MAXN][MAXN];

int sm[MAXN];

int gt[MAXN];

const int INF = 1e18 + 118;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            x = 1;
        }
        ++cnt[x];
    }
    vector<int> primes;
    for (int i = 2; i < MAXN; ++i)
    {
        is_prime[i] = true;
        for (int j = 2; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                is_prime[i] = false;
                break;
            }
        }
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
    reverse(primes.begin(), primes.end());
    int cr = 0;
    for (int i = MAXN - 1; i >= 1; --i)
    {
        gt[i] = cr;
        if (is_prime[i])
        {
            ++cr;
        }
    }
    for (int i = 1; i < MAXN; ++i)
    {
        int ind = 0;
        for (auto el : primes)
        {
            int cr = 0;
            int t = 1;
            while (i % (t * el) == 0)
            {
                t *= el;
                ++cr;
            }
            cc[i][ind] = cc[i - 1][ind] + cr;
            sm[i] += cc[i][ind];
            ++ind;
        }
    }
    for (int i = 1; i < MAXN; ++i)
    {
        for (int j = i + 1; j < MAXN; ++j)
        {
            int lcp = 0;
            int ind = gt[j];
            while (ind < primes.size())
            {
                lcp += min(cc[i][ind], cc[j][ind]);
                if (cc[i][ind] != cc[j][ind])
                {
                    break;
                }
                ++ind;
            }
            dist[i][j] = sm[i] + sm[j] - 2 * lcp;
            dist[j][i] = dist[i][j];
        }
    }
    int ans = INF;
    for (int i = 1; i < MAXN; ++i)
    {
        int cur = 0;
        for (int j = 1; j < MAXN; ++j)
        {
            cur += cnt[j] * dist[i][j];
        }
        if (cur < ans)
        {
            ans = cur;
        }
    }
    cout << ans << endl;
    return 0;
}