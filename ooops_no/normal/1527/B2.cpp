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
        string s;
        cin >> s;
        bool x = 1;
        int cnt = 0, cntt = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '0') cnt++;
            if (s[i] != s[n - i - 1]){
                x = 0;
                cntt++;
            }
        }
        cntt /= 2;
        if (x){
            if (cnt % 2 == 0 || cnt == 1) cout << "BOB" << endl;
            else cout << "ALICE" << endl;
        }
        else{
            if (cnt == 2 && cntt == 1){
                cout << "DRAW" << endl;
            }
            else{
                cout << "ALICE" << endl;
            }
        }
    }
    return 0;
}