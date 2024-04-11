#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const string f = "abacaba";


bool check(string s) {
    int cnt = 0;
    for(int i = 0;i <= s.size() - f.size();i++) {
        bool good = true;
        for(int j = 0;j < f.size();j++) {
            if (f[j] != s[i + j]) good = false;
        }
        if (good) cnt++;
    }
    return cnt == 1;
}

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
        string s;
        cin >> s;
        bool good = false;
        string res;
        for(int i = 0;i <= n - f.size();i++) {
            string temp;
            for(int j = 0;j < n;j++) temp += s[j];
            for(int j = 0;j < f.size();j++) {
                if (temp[i + j] == '?') temp[i + j] = f[j];
            }
            for(int j = 0;j < n;j++) if (temp[j] == '?') temp[j] = 'z';

            if (check(temp)) {
                good = true;
                res = temp;
            }
        }

        if (!good) cout << "No" << endl;
        else {
            cout << "Yes" << endl;
            cout << res << endl;
        }
    }
}