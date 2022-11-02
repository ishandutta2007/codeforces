#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int num = n;
        while(true) {
            bool bad = false;
            for(int i = 2;i * i <= num;i++) {
                if (num % i == 0) {
                    bad = true;
                }
            }
            bool good = false;
            for(int i = 2;i * i <= num - (n - 1);i++) {
                if ((num - (n - 1)) % i == 0) {
                    good = true;
                }
            }
            
            if (bad || !good) num++;
            else break;
        }

        num -= n - 1;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                cout << ((i == j) ? num : 1) << " ";
            }
            cout << endl;
        }
    }
}