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
        int n, m;
        cin >> n >> m;
        vector<int> a(m), b(m), c(m);
        vector<bool> used(n + 1);
        for (int i = 0; i < m; i++){
            cin >> a[i] >> b[i] >> c[i];
            used[b[i]] = 1;
        }
        int v = -1;
        for (int i = 1; i <= n; i++){
            if (!used[i]){
                v = i;
            }
        }
        for (int i = 1; i <= n; i++){
            if (v != i){
                cout << v << ' ' << i << endl;
            }
        }
    }
    return 0;
}