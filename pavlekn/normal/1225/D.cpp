    #include<bits/stdc++.h>

    using namespace std;

    #define int long long

    #pragma GCC optimize("-O3")

    const int MAXN = 1e5 + 7;

    int32_t main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int ans = 0;
        vector<int> is_prime(MAXN);
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
        }
        vector<int> cnt(MAXN);
        for (int i = 0; i < n; ++i)
        {
            vector<int> pr;
            for (int j = 1; j * j <= a[i]; ++j)
            {
                if (a[i] % j == 0)
                {
                    if (is_prime[j])
                    {
                        pr.push_back(j);
                    }
                    if (j * j != a[i] && a[i] / j < MAXN && is_prime[a[i] / j])
                    {
                        pr.push_back(a[i] / j);
                    }
                }
            }
            int bb = 1;
            for (auto el : pr)
            {
                int cc = 1;
                int cur = el;
                while (a[i] % (cur * el) == 0)
                {
                    cur *= el;
                    ++cc;
                }
                int pp = (k - cc % k + k) % k;
                int q = 1ll;
                for (int _ = 0; _ < pp; ++_)
                {
                    q *= el;
                    if (q > MAXN)
                    {
                        q = MAXN + 1;
                    }
                }
                bb *= q;
                if (bb > MAXN)
                {
                    bb = MAXN + 1;
                }
            }
            for (int ii = 1; ii < MAXN; ++ii)
            {
                int p = 1ll;
                for (int j = 0; j < k; ++j)
                {
                    p *= ii;
                    if (p >= MAXN)
                    {
                        break;
                    }
                }
                if (p >= MAXN || p * bb >= MAXN)
                {
                    break;
                }
                ans += cnt[p * bb];
            }
            cnt[a[i]]++;
        }
        cout << ans << endl;
        return 0;
    }