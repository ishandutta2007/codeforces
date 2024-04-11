#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] != s.back()){
        s[n - 1] = ((s[n - 1] - 'a') ^ 1) + 'a';
    }
    cout << s << endl;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}