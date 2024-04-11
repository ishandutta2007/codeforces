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
const int max_n = 101;

int col[max_n][max_n];
int n;

void find(pii& po, int c) {
    col[po.fi][po.se] = c;
    cout << c << " " << po.fi + 1 << " " << po.se + 1 << endl;
    po.se += 2;
    if (po.se >= n) {
        po.fi++;
        po.se = 1 - po.se % 2;
    }
}


signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(15);
    
/*#ifdef technocum
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/

    cin >> n;
    pii t1(0, 0), t2(0, 1);
    for(int it = 0;it < n * n;it++) {
        int a;
        cin >> a;

        if (a != 1) {
            if (t1.fi >= n) find(t2, 6 - 1 - a);
            else find(t1, 1);
        }else {
            if (t2.fi >= n) find(t1, 3);
            else find(t2, 2);
        }
    }
}