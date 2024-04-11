

    #include<bits/stdc++.h>

    using namespace std;

    #define int long long

    int32_t main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin >> n;
        int m = 0;
        for (int p = n; p < 2000; ++p)
        {
            int f = true;
            for (int i = 2; i < p; ++i)
            {
                if (p % i == 0)
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                m = p;
                break;
            }
        }
        if (n == 6)
        {
            cout << 7 << endl;
            cout << "1 2" << endl;
            cout << "2 3" << endl;
            cout << "3 4" << endl;
            cout << "1 4" << endl;
            cout << "1 5" << endl;
            cout << "5 6" << endl;
            cout << "6 3" << endl;
            return 0;
        }
        int cnt3 = 2 * (m - n);
        int cnt2 = n - cnt3;
        vector<pair<int, int>> ans;
        int cur = 1;
        while (cnt3 >= 4)
        {
            for (int i = 0; i < 4; ++i)
            {
                for (int j = i + 1; j < 4; ++j)
                {
                    ans.push_back({cur + i, cur + j});
                }
            }
            cnt3 -= 4;
            cur += 4;
        }
        if (cnt3 == 2)
        {
            for (int i = 0; i < 4; ++i)
            {
                for (int j = i + 1; j < 4; ++j)
                {
                    if (i + j > 1)
                    {
                        ans.push_back({cur + i, cur + j});
                    }
                }
            }
            cnt3 = 0;
            cnt2 -= 2;
            cur += 4;
        }
        if (cnt2 > 0)
        {
            for (int i = 0; i < cnt2 - 1; ++i)
            {
                ans.push_back({cur + i, cur + i + 1});
            }
            ans.push_back({cur, cur + cnt2 - 1});
        }
        cout << ans.size() << endl;
        for (auto el : ans)
        {
            cout << el.first << " " << el.second << endl;;
        }
        return 0;
    }