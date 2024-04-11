#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

map<char, int> mp;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    mp['I'] = mp['E'] = mp['A'] = mp['O'] = mp['U'] = mp['Y'] = 1;
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < s.size(); i++){
        a[i] = mp[s[i]] + (i > 0 ? a[i - 1] : 0);
    }
    ld ans = 0, cnt = a.back();
    for (int m = 1; m < n; m++){
        ans += cnt / (ld)m;
        if (m < n - m){
            cnt += a[n - m - 1] - a[m - 1];
        }
        else{
            cnt -= a[m - 1] - a[n - m - 1];
        }
    }
    ans += cnt / (ld)n;
    cout << setprecision(30) << fixed << ans << endl;
    return 0;
}