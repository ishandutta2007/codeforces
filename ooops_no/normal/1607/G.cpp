#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb emplace_back
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
        int n, m, bal = 0;
        cin >> n >> m;
        vector<int> a(n), b(n), cola(n), colb(n);
        for (int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
            cola[i] = min(a[i], m);
            colb[i] = m - cola[i];
            bal -= (a[i] - cola[i]);
            bal += (b[i] - colb[i]);
        }
        if (bal > 0){
            for (int i = 0; i < n; i++){
                int can = min(b[i] - colb[i], cola[i]);
                if (bal > 2 * can){
                    cola[i] -= can, colb[i] += can;
                    bal -= 2 * can;
                }
                else{
                    cola[i] -= bal / 2, colb[i] += bal / 2;
                    break;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) sum += (a[i] - cola[i]) - (b[i] - colb[i]);
        cout << abs(sum) << endl;
        for (int i = 0; i < n; i++){
            cout << cola[i] << ' ' << colb[i] << endl;
        }
    }
    return 0;
}