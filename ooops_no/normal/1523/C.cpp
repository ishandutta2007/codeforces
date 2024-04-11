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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> now;
        for (int i = 0; i < n; i++){
            if (a[i] == 1){
                now.pb(1);
            }
            else{
                while(now.size() > 0){
                    if (now.back() + 1 == a[i]){
                        now.back()++;
                        break;
                    }
                    now.pop_back();
                }
                if (now.size() == 0) now.pb(a[i]);
            }
            for (int j = 0; j < now.size(); j++){
                if (j > 0) cout << '.';
                cout << now[j];
            }
            cout << endl;
        }
    }
    return 0;
}