#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if (x == 1){
            cout << 1 << endl;
        }
        else if (x == 2){
            cout << 3 << endl;
        }
        else{
            int sum = 0, now = 1;
            while(sum < x){
                sum += now;
                now++;
            }
            if (sum == x + 1) cout << now << endl;
            else cout << now - 1 << endl;
        }
    }
    return 0;
}