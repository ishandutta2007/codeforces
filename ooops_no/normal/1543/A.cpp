#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
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
        if (a == b){
            cout << 0 << " " << 0 << endl;
        }
        else{
            if (a < b) swap(a, b);
            int val = a - b;
            if (((val - b % val) % val) < b % val){
                cout << val << ' ' << ((val - b % val) % val) << endl;
            }
            else{
                cout << val << ' ' <<  b % val << endl;
            }
        }
    }
    return 0;
}