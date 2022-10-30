#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;




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
        string s;
        cin >> n >> s;
        int id = -1;
        for(int i = n - 1;i >= 0;i--) {
            if (s[i] == '0') {
                id = i;
                break;
            }
        }
        int id2 = n;
        for(int i = 0;i < n;i++) {
            if (s[i] == '1') {
                id2 = i;
                break;
            }
        }

        bool good = false;
        int cnt = 0;
        for(int i = id;i >= id2;i--) if (s[i] == '1') good = true;
        if (good) {
            for(int i = 0;i < id2;i++) cout << '0';
            cout << '0';
        }
        else {
            for(int i = 0;i <= id;i++) cout << '0';
        }
        for(int i = id + 1;i < n;i++) cout << '1';
        cout << endl;
    }
}