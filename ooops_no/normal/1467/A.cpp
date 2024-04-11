#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long
#define ld long double

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if (n == 1){
            cout << 9 << endl;
        }
        else if (n == 2){
            cout << 98 << endl;
        }
        else{
            cout << 989;
            for (int i = 3; i < n; i++){
                cout << (i + 7) % 10;
            }
            cout << endl;
        }
    }
    return 0;
}