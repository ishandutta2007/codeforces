#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e6+10, ALP = 26, MAXL = 20, INF = 1e9+10, MOD = 1e9+7;


void solve(){
    int n; cin >> n;
    vector<pair<int, int>> s[2];
    for (int i = 0; i < 2*n; i++){
        int c; cin >> c;
        s[c&1].push_back({c, i});
    }
    if ((int)s[0].size()%2==1) s[0].pop_back(), s[1].pop_back();
    else {
        int idx = 0; if (s[1].size() > s[0].size()) idx = 1;
        s[idx].pop_back(); s[idx].pop_back();
    }
    while (s[0].size()) cout << s[0].back().second+1, s[0].pop_back(), cout << " " << s[0].back().second+1 << "\n", s[0].pop_back();
    while (s[1].size()) cout << s[1].back().second+1, s[1].pop_back(), cout << " " << s[1].back().second+1 << "\n", s[1].pop_back();
}
int main(){
    int t=1; cin >> t;
    while (t--) solve();
}