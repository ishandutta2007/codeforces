#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ld long double
#define pb push_back

mt19937 rnd(51);

signed main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if (n == 1){
            cout << 0 << endl;
        }
        else{
            int ans = n - 1;
            if (n % 2 == 0){
                cout << min(ans, 2ll);
            }
            else{
                cout << min(ans, 3ll);
            }
            cout << endl;
        }
    }
    return 0;
}