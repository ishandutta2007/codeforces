#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
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
        int x, y;
        cin >> x >> y;
        if (x == y){
            cout << x << endl;
        }
        else if (x > y){
            cout << (x + 1) * y << endl;
        }
        else{
            cout << y - (y % x) / 2 << endl;
        }
    }
    return 0;
}