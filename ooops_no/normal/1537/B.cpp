#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
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
        int n, m, i, j;
        cin >> n >> m >> i >> j;
        vector<pair<int,int>> v{{1, 1}, {n, 1}, {1, m}, {n, m}};
        int anss = -1;
        pair<int,int> p, pp;
        for (int ii = 0; ii < 4; ii++){
            for (int jj = 0; jj < 4; jj++){
                vector<pair<int,int>> a{v[ii], v[jj], {i, j}};
                sort(a.begin(), a.end());
                int ans = 1e18;
                do{
                    ans = min(ans, abs(a[0].first - a[1].first) + abs(a[1].first - a[2].first) + abs(a[2].first - a[0].first) + abs(a[0].second - a[1].second) + abs(a[1].second - a[2].second) + abs(a[2].second - a[0].second));
                }while(next_permutation(a.begin(), a.end()));
                if (ans > anss){
                    anss = ans;
                    p = v[ii], pp = v[jj];
                }
            }
        }
        cout << p.first << ' ' << p.second << ' ' << ' ' << pp.first << ' ' << pp.second << endl;
    }
    return 0;
}