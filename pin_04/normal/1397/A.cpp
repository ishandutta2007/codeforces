#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int cnt[26];

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (char c : s)
        {
            cnt[c - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % n)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}