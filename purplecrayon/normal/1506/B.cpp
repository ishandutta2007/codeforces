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
const int MAXN = 6e2+10, MAXQ = MAXN*MAXN, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;
 
void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int fp=-1, lp=-1;
    for (int i = 0; i < n; i++) if (s[i] == '*') {
        s[i] = 'X'; 
        fp = lp = i;
        break;
    }
    for (int i = n-1; i >= 0; i--) if (s[i] == '*') {
        s[i] = 'X';
        lp = i;
        break;
    }
    int pos = fp;
    for (int i = pos; i < n; i = pos) {
        for (int j = i; j < n; j++) if (j-i <= k && (s[j] == '*' || s[j] == 'X')) {
            pos = j;
        }
        if (pos == i) break;
        s[pos] = 'X';
    }
    cout << count(s.begin(), s.end(), 'X') << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}