#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define ll long long

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
        int l = -1, r = 1e9 + 10, a, b;
        cin >> a >> b;
        while(r - l > 1){
            int mid = (r + l) / 2;
            if (mid <= a && mid <= b && mid * 4 <= a + b){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        cout << l << endl;
    }
    return 0;
}