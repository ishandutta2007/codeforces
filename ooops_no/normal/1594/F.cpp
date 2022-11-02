#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
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
        int s, n, k;
        cin >> s >> n >> k;
        cout << ((n > k || s != k) && s >= 2 * n - n % k ? "NO\n" : "YES\n");
    }
    return 0;
}