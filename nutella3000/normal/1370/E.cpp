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
    
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> c(2);
    vector<int> pref(n);
    for(int i = 0;i < n;i++) {
        c[s[i] - '0']++;
        c[t[i] - '0']--;

        if (s[i] == t[i]) pref[i] = 0;
        else if (s[i] == '1') pref[i] = 1;
        else pref[i] = -1;
        if (i != 0) pref[i] += pref[i - 1];
    }

    int Min = 0, Max = 0;
    int res = 0;
    for(int i = 0;i < n;i++) {
        res = max(res, max(pref[i] - Min, Max - pref[i]));
        Min = min(pref[i], Min);
        Max = max(pref[i], Max);
    }


    if (c[0] || c[1]) cout << -1;
    else cout << res << endl;
}