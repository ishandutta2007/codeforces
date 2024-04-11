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
const int MAXN = 2e5+10, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 21, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    string s; cin >> s;
    int n = sz(s);

    int fp[26]={}, np[26]={};

    auto repl = [&](int v, int mx_r) {
        for (int i = 0; i < mx_r; i++)
            if (s[i]-'a' == v) s[i] = '?';
    };

    while (1) {
        fill(fp, fp+26, n), fill(np, np+26, -1);

        for (int i = 0; i < n; i++) if (s[i]!='?') fp[s[i]-'a'] = min(fp[s[i]-'a'], i);
        for (int i = 0; i < n; i++) if (s[i]!='?') np[s[i]-'a'] = max(np[s[i]-'a'], i);

        int c=-1;
        for (int i = 25; i >= 0; i--) {
            if (fp[i] == n) continue;

            bool bad=0;
            for (int j = 0; j < 26; j++) if (i != j && np[j] != -1 && np[j] < fp[i]) {
                bad=1;
            }

            if (!bad){ 
                c=i;
                break;
            }
        }
        if (c == -1) break;

        cout << char(c+'a');

        repl(c, n);
        for (int i = 0; i < 26; i++) repl(i, fp[c]);
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}