#include<bits/stdc++.h>

using namespace std;

bool cmp(string s, string t)
{
    return s.size() < t.size();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << "? " << 1 << " " << n << endl;
    if (n == 1)
    {
        string s;
        cin >> s;
        cout << "! " << s << endl;
        return 0;
    }
    unordered_map<string, int> cnt;
    for (int i = 0; i < (n * (n + 1)) / 2; ++i)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        cnt[s]++;
    }
    cout << "? " << 2 << " " << n << endl;
    for (int i = 0; i < n * (n - 1) / 2; ++i)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        cnt[s]--;
    }
    vector<string> cur;
    for (auto el : cnt)
    {
        if (el.second == 1)
        {
            cur.push_back(el.first);
        }
    }
    sort(cur.begin(), cur.end(), cmp);
    string ans;
    ans.push_back(cur[0][0]);
    for (int i = 1; i < cur.size(); ++i)
    {
        unordered_map<char, int> cc;
        for (auto el : cur[i])
        {
            cc[el]++;
        }
        for (auto el : cur[i - 1])
        {
            cc[el]--;
        }
        for (auto el : cc)
        {
            if (el.second == 1)
            {
                ans.push_back(el.first);
            }
        }
    }
    cout << "! " << ans << endl;
    return 0;
}