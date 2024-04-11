#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
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
        int n;
        cin >> n;
        cout << -(n - 1) << ' ' << n << endl;
    }
    return 0;
}