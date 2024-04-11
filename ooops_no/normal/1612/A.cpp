#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

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
        int a, b;
        cin >> a >> b;
        if ((a + b) % 2 == 0){
            if (a >= b){
                cout << (a + b) / 2 << ' ' << 0 << endl;
            }
            else{
                cout << 0 << ' ' << (a + b) / 2 << endl;
            }
        }
        else{
            cout << -1 << " " << -1 << endl;
        }
    }
    return 0;
}