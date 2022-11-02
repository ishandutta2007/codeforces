#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

bool ok(vector<int> a){
    int n = a.size();
    for (int i = 0; i < n; i++){
        if (a[i] != a[n - i - 1]) return 0;
    }
    return 1;
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> b;
        for (int i = 0; i < n; i++){
            if (a[i] != a[n - i - 1]){
                b.pb(a[i]);
                b.pb(a[n - i - 1]);
                break;
            }
        }
        if (b.size() == 0){
            cout << "YES\n";
            continue;
        }
        bool f = 0;
        for (auto to : b){
            vector<int> c;
            for (int i = 0; i < n; i++){
                if (a[i] != to) c.pb(a[i]);
            }
            if (ok(c)) f = 1;
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}