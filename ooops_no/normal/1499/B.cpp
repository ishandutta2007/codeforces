#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size(), cnt = 0, cnt1 = 0;
        for (auto to : s){
            if (to == '0') cnt++;
            else cnt1++;
        }
        if (cnt == 0 || cnt1 == 0){
            cout << "YES\n";
            continue;
        }
        bool x = 1;
        for (int i = 0; i < n; i++){
            vector<int> a;
            for (int j = 0; j <= i; j++){
                if (s[j] == '1'){
                    a.pb(j);
                }
            }
            for (int j = i + 1; j < n; j++){
                if (s[j] == '0'){
                    a.pb(j);
                }
            }
            bool f = 0;
            if (a.size() == 0){
                cout << "YES\n";
                x = 0;
                break;
            }
            for (int j = 0; j < a.size() - 1; j++){
                if (a[j + 1] - a[j] == 1){
                    f = 1;
                }
            }
            if (!f){
                cout << "YES\n";
                x = 0;
                break;
            }
        }
        if (x){
            cout << "NO\n";
        }
    }
    return 0;
}