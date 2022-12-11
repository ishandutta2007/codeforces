#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e3 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s = "codeforces";
    vector<int> cnt(10, 1);
    int cur = 1;
    int ind = 0;
    while (cur < n)
    {
        cur /= cnt[ind];
        ++cnt[ind];
        cur *= cnt[ind];
        ind = (ind + 1) % 10;
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < cnt[i]; ++j)
        {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}