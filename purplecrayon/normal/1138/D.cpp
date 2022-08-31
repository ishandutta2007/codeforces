#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi[n-1];
}
void solve(){
    string s, t; cin >> s >> t;
    if (sz(t) > sz(s)) { cout << s << '\n'; return; }
    else if (sz(t) == sz(s)){
        if (std::count(s.begin(), s.end(), '1') == std::count(t.begin(), t.end(), '1')) cout << t << '\n';
        else cout << s << '\n';
        return;
    }
    assert(sz(t) < sz(s));
    int t_0=std::count(t.begin(), t.end(), '0'), t_1=std::count(t.begin(), t.end(), '1');
    int s_0=std::count(s.begin(), s.end(), '0'), s_1=std::count(s.begin(), s.end(), '1');

    if (s_0 < t_0 || s_1 < t_1){
        cout << s;
        return;
    }

    cout << t; s_0 -= t_0, s_1 -= t_1;
    int v=prefix_function(t);
    int n_0=0, n_1=0;
    for (int i = v; i < sz(t); i++) n_0 += t[i]=='0', n_1 += t[i]=='1';

    while (s_0 >= n_0 && s_1 >= n_1){
        for (int i = v; i < sz(t); i++) cout << t[i];
        s_0 -= n_0, s_1 -= n_1;
    }
    for (int i = 0; i < s_0; i++) cout << 0;
    for (int i = 0; i < s_1; i++) cout << 1;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}