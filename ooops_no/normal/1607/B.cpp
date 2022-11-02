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
    int t;
    cin >> t;
    while(t--){
        int x, n;
        cin >> x >> n;
        int val = 0;
        if (n % 4 == 1){
            val = -n;
        }
        else if (n % 4 == 0){
            val = 0;
        }
        else if (n % 4 == 2){
            val = 1;
        }
        else{
            val = (n + 1);
        }
        if (abs(x) % 2 == 1){
            val = -val;
        }
        cout << x + val << endl;
    }
    return 0;
}