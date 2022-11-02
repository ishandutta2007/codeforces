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

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n), b(n);

        int num = 0, cnt = 0;
        for(int i = 0;i < n;i++) {
            if (s[i] == '1') cnt++;
        }

        cnt /= 2;

        int n1 = 0, n2 = 0;

        bool bad = false;
        for(int i = 0;i < n;i++) {
            if (s[i] == '1') {
                if (cnt > 0) {
                    a[i] = b[i] = 1;
                }else a[i] = b[i] = -1;
                cnt--;
            }else {
                if (num) {
                    a[i] = 1;
                    b[i] = -1;
                }else {
                    a[i] = -1;
                    b[i] = 1;
                }
                num ^= 1;
            }

            n1 += a[i], n2 += b[i];
            if (n1 < 0 || n2 < 0) bad = true;
        }

        if (n1 != 0 || n2 != 0) bad = true;

        if (bad) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for(int i : a)
                cout << (i == 1 ? '(' : ')');
            cout << endl;
            for(int i : b)
                cout << (i == 1 ? '(' : ')');
            cout << endl;
        }
    }
}