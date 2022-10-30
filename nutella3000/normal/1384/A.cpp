#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
const int inf = 1e15 + 7;
const int max_n = 1e5 + 1;
 
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++) cin >> a[i];

        vector<char> b(51, 'a');
        for(char i : b) cout << i;
        cout << endl;
        for(int i = 0;i < n;i++) {
            b[a[i]] = 'b' - b[a[i]] + 'a';
            for(char j : b) cout << j;
            cout << endl;
        }

    }
}