#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7, mod = 1e9 + 7;
 
bool f(int s, int x, bool win, bool chan) {
    int new_x = x / 2;
 
    if (new_x < s) {
        if (chan) return ((x - s) % 2) ^ win;
        return win;
    }
 
    if (chan) {
        if ((x - new_x * 2) ^ win) {
            return f(s, new_x, ((x - new_x) % 2) ^ win, true);
        }   
        return f(s, new_x, true, false);
    }
    if (win) return f(s, new_x, false, true);
    return f(s, new_x, true, false);
}
 
bool one(int s, int e) {
    return f(s, e + 1, true, true);
}
 
bool two(int s, int e) {
    return f(s, e, true, false);
}
 
void solve() {

    //cout << f(1, 9, true, false) << endl;

    int n;
    cin >> n;
    vector<int> s(n), e(n);
    for(int i = 0;i < n;i++) {
        cin >> s[i] >> e[i];
    }
 
    bool o1 = true, o2 = false;
 
    for(int i = n - 1;i >= 0;i--) {
        if (o1) {
            o1 = !one(s[i], e[i]);
        }else {
            o1 = !two(s[i], e[i]);
        }
 
        if (o2) {
            o2 = !one(s[i], e[i]);
        }else {
            o2 = !two(s[i], e[i]);
        }
 
        //cout << o1 << " " << o2 << endl;
    }
    cout << !o1 << " " << !o2 << endl;
}
 
signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    solve();
}