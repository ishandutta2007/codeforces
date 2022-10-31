#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define ld long double

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if (n % 2 == 0){
            cout << n / 2 << ' ' << n / 2 - 1 << ' ' << 1 << endl;
        }
        else{
            int val = 3;
            while(gcd(n - val, val - 1) != 1){
                val++;
            }
            cout << n - val << ' ' << val - 1 << ' ' << 1 << endl;
        }
    }
    return 0;
}