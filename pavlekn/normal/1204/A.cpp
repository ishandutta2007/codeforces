#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    string s;
    cin >> s;
    string t = "1";
    int ans = 0;
    while (t.size() < s.size() || (t.size() == s.size() && t < s))
    {
        ++ans;
        t.push_back('0');
        t.push_back('0');
    }
    cout << ans << endl;
    return 0;
}