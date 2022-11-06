#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
                vec.push_back(i);
        }
        if (vec.empty() || vec.size() == 1)
        {
            cout << "0\n";
            continue;
        }
        int m = (int) vec.size();
        int mid = vec[m / 2];
        long long ans = 0;
        int cnt = 1;
        for (int i = m / 2 + 1; i < m; i++)
        {
            ans += vec[i] - mid - cnt;
            cnt++;
        }
        cnt = 1;
        for (int i = m / 2 - 1; i >= 0; i--)
        {
            ans += mid - vec[i] - cnt;
            cnt++;
        }
        cout << ans << "\n";
    }
    return 0;
}