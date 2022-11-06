#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> comps;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            comps.push_back(cnt);
            cnt = 1;
        }
        else
            cnt++;
    }
    comps.push_back(cnt);
    long long ans = 0;
    for (int i = 0; i < comps.size(); i++)
    {
        if (i == 0 || i == comps.size() - 1)
            ans += comps[i];
        else
            ans += 2 * comps[i];
    }
    ans -= comps.size() - 1;
    if (comps.size() == 1)
        ans = 0;
    ans = (long long) n * (n - 1) / 2 - ans;
    cout << ans << endl;
    return 0;
}