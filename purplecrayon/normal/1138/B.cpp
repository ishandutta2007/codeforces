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
const int MAXN = 1e5+10, MAXM = 1e2+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    string c, a; cin >> c >> a;
    int tb=0;
    for (auto& it : a) tb += it-'0';

    //sum of top == sum of bottom in complement
    //bottom == t_b - bottom_vals_of_top
    //top_vals_of_top == t_b-bottom_vals_of_top
    //top_vals_of_top+bottom_vals_of_top == tb

    int cnt[3]={};
    for (int i = 0; i < n; i++) cnt[c[i]-'0'+a[i]-'0']++;
    ar<int, 3> ans{-1, -1, -1};
    for (int i = 0; i <= cnt[2]; i++) for (int j = 0; j <= cnt[1]; j++){
        int k=n/2-i-j;
        if (k < 0 || k > cnt[0]) continue;
        if (2*i + 1*j + 0*k == tb){
            ans = {k, j, i};
            break;
        }
    }
    if (ans == ar<int, 3>{-1, -1, -1}){ cout << "-1\n"; return; }
    for (int i = 0; i < n; i++){
        int v=c[i]-'0'+a[i]-'0';
        if (ans[v]){ cout << (i+1) << ' '; ans[v]--; }
    }

    assert(*min_element(ans.begin(), ans.end()) == 0 && *max_element(ans.begin(), ans.end()) == 0);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}