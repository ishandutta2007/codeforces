#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        cout << 100 / __gcd(a, 100ll) << endl;
    }
    return 0;
}