#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ++ii)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        int fl = true;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % n)
        {
            cout << -1 << endl;
            continue;
        }
        int med = sum / n;
        int num = 0;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] > i)
            {
                num = i;
            }
        }
        vector<int> ans1;
        vector<int> ans2;
        vector<int> ans3;
        if (num > 0)
        {
            ans1.push_back(num + 1);
            ans2.push_back(1);
            ans3.push_back(1);
            a[0] += (num + 1);
            a[num] -= (num + 1);
        }
        vector<pair<int, int>> b;
        for (int i = 1; i < n; ++i)
        {
            b.push_back({((i + 1) - a[i] % (i + 1)) % (i + 1), i});
        }
        sort(b.begin(), b.end());
        for (auto el : b)
        {
            if (a[0] >= el.first)
            {
                int j = el.second;
                ans1.push_back(1);
                ans2.push_back(j + 1);
                ans3.push_back(el.first);
                ans1.push_back(j + 1);
                ans2.push_back(1);
                ans3.push_back((a[j] + j) / (j + 1));
                a[0] += a[el.second];
            }
            else
            {
                cout << -1 << endl;
                fl = false;
                break;
            }
        }
        if (!fl)
        {
            continue;
        }
        for (int i = 1; i < n; ++i)
        {
            ans1.push_back(1);
            ans2.push_back(i + 1);
            ans3.push_back(med);
        }
        cout << ans1.size() << endl;
        for (int i = 0; i < ans1.size(); ++i)
        {
            cout << ans1[i] << " " << ans2[i] << " " << ans3[i] << endl;
        }
    }
    return 0;
}