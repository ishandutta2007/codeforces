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
        int a, b, c;
        cin >> a >> b >> c;
        cout << max(0ll, max(b, c) - a + 1) << ' ' << max(0ll, max(a, c) - b + 1) << ' ' << max(0ll, max(a, b) - c + 1) << endl;
    }
    return 0;
}