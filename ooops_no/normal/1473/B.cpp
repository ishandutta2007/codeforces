#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        string s, t;
        cin >> s >> t;
        bool x = 0;
        for (int i = 1; i < 50; i++){
            string k = "";
            for (int j = 0; j < i; j++){
                k += s;
            }
            int now = 0;
            while(now < k.size()){
                if (k.substr(now, t.size()) != t){
                    break;
                }
                else{
                    now += t.size();
                }
            }
            if (now == k.size()){
                cout << k << endl;
                x = 1;
                break;
            }
        }
        if (!x) cout << -1 << endl;
    }
    return 0;
}