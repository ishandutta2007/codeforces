#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 1e9 + 7;

void solve(){
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    bool x = 1;
    for (auto to : s) x &= to == c;
    if (x){
        cout << 0 << endl;
        return;
    }
    for (int i = n / 2 + 1; i <= n; i++){
        if (s[i - 1] == c){
            cout << 1 << endl << i << endl;
            return;
        }
    }
    cout << 2 << endl << n / 2 + 1 << ' ' << n / 2 + 2 << endl;
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