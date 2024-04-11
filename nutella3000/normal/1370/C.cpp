#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7, mod = 1e9 + 7;
 
 
 
 
signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "FastestFinger" << endl;
            continue;
        }
        bool good = false;
        if (n % 2 == 1) {
            good = true;
        }else{
            int cnt1 = 1, cnt2 = 0;
            if (n % 4 == 0) cnt1 = 2;
            for(int i = 2;i * i <= n;i++) {
                while(n % i == 0) {
                    n /= i;
                    if (i != 2) cnt2++;
                }
            }
            if (n > 2) cnt2++;
            if (cnt1 == 1 && cnt2 != 1) good = true;
            if (cnt1 == 2 && cnt2 >= 1) good = true;
        }
        if (good) cout << "Ashishgup" << endl;
        else cout << "FastestFinger" << endl;
    }   
}