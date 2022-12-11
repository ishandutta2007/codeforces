#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e5 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(clock());
    int m, k, n, s;
    cin >> m >> k >> n >> s;
    int c = m - (n * k) + k;
    vector<int> a(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
    }
    vector<int> b(s);
    vector<int> count(MAXN);
    vector<int> cur(MAXN);
    int cnt = 0;
    for (int i = 0; i < s; ++i)
    {
        cin >> b[i];
        if (count[b[i]] == 0)
        {
            ++cnt;
        }
        count[b[i]]++;
    }
    int ans = -1;
    int j = 0;
    int cur_cnt = 0;
    vector<int> cc(MAXN);
    for (int i = 0; i < m; ++i)
    {
        while (j < m && j - i < c)
        {
            cur[a[j]]++;
            if (count[a[j]] == cur[a[j]])
            {
                ++cur_cnt;
                if (cur_cnt == cnt)
                {
                    ++j;
                    break;
                }
            }
            ++j;
        }
        if (cur_cnt == cnt && i % k == 0 && j - i <= m - n * k + k)
        {
            ans = true;
            vector<int> res;
            int rr = 0;
            for (int k1 = i; k1 < j; ++k1)
            {
                ++cc[a[k1]];
                if (cc[a[k1]] > count[a[k1]] && rr < m - n * k)
                {
                    res.push_back(k1 + 1);
                    ++rr;
                }
            }
            cout << res.size() << endl;
            for (auto el : res)
            {
                cout << el << " ";
            }
            cout << endl;
            return 0;
        }
        cur[a[i]]--;
        if (cur[a[i]] + 1 == count[a[i]])
        {
            --cur_cnt;
        }
    }
    cout << -1 << endl;
    return 0;
}