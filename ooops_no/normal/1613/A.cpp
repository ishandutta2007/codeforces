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
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        int mn = min(p1, p2), val = to_string(x1).size() + p1, vall = to_string(x2).size() + p2;
        p1 -= mn, p2 -= mn;
        if (val > vall) cout << '>';
        else if (val < vall){
            cout << '<';
        }
        else{
            for (int i = 0; i < p1; i++) x1 *= 10;
            for (int i = 0; i < p2; i++) x2 *= 10;
            if (x1 > x2) cout << '>';
            else if (x1 < x2) cout << '<';
            else cout << '=';
        }
        cout << endl;
    }
    return 0;
}