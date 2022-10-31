#include<bits/stdc++.h>

using namespace std;

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
        vector<int> v(3);
        for (int i = 0; i < 3; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        cout << (v[0] + v[1] == v[2] || (v[0] == v[1] && v[2] % 2 == 0) || (v[0] % 2 == 0 && v[1] == v[2]) ? "YES" : "NO") << endl;
    }
    return 0;
}