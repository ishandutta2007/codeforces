#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5+10;

int a[MAXN], ans[MAXN], cnt;
set<int> l[2];

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; i++) a[i] = s[i]-'0';
    l[1].clear(); l[0].clear();
    for (int i = 0; i < n; i++){
        if (a[i]) l[1].insert(i);
        else l[0].insert(i);
    }
    // cout << endl;
    // for (int i = 0; i < n; i++) cout << nxt[i][0] << " " << nxt[i][1] << endl;
    // return;
    fill(ans, ans+n, 0); cnt = 1;
    for (int i = 0; i < n; i++){
        if (ans[i] == 0){
            int c = i;
            ans[c] = cnt;
            while (l[a[c]^1].upper_bound(c) != l[a[c]^1].end()){
                auto it = l[a[c]^1].upper_bound(c); int itv = *it;
                ans[itv] = cnt; l[a[c]^1].erase(it); c = itv;
            }
            cnt++;
        }
    }
    cout << cnt-1 << "\n";
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}