#include <bits/stdc++.h>
    
using namespace std;
    
mt19937 rnd(time(0));
    
//        //\\      ||||||  ||||          //\\        ||||||
//       //  \\       ||    ||  ||       //  \\       ||   ||
//      //    \\      ||    ||   ||     //    \\      ||   ||
//     //------\\     ||    ||   ||    //------\\     ||||||
//    //        \\    ||    ||   ||   //        \\    ||  \\
//   //          \\ ||||||  |||||    //          \\   ||   \\
    
#define AvAR ASADULLIN
    
#define int long long
#define mp make_pair
#define all(a) a.begin(), a.end()
#define pii pair<int, int>
#define fi first
#define se second
#define ld long double
#define size(a) (int)(a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
    
const int inf = 1e10 + 2;

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(15);
    
#ifdef technocum
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<pii> a(n);
    for(int i = 0;i < n;i++)
        cin >> a[i].fi >> a[i].se;
    sort(all(a));

    int res = 0;
    int v = 0;
    while(v != n - 1) {
        int id = v + 1;
        while(true) {
            if (id == n - 1 || (a[id].fi + a[id].se > a[v].fi + a[v].se)) {
                res += max(0ll, a[id].fi - a[v].fi - a[v].se);
                v = id;
                break;
            }
            id++;
        }
    }
    for(int i = 0;i < n;i++)
        res += a[i].se;

    cout << res << endl;
}