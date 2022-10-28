#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

int n, k;

int mex(vector<int> a) {
    set<int> s(a.begin(), a.end());
    int c = 0; while (s.count(c)) c++;
    return c;
}
void solve(){
    cin >> n >> k; k %= 2;

    const int MAX = 50;
    vector<int> seq(MAX, 0);
    for (int i = 1; i < MAX; i++) {
        vector<int> nxt{seq[i-1]};
        if (i&1^1) {
            if (k&1^1) nxt.push_back(seq[0]);
            else nxt.push_back(seq[i/2]);
        }
        seq[i] = mex(nxt);
    }
    auto nimber = [&](int x) {
        if (x < MAX) return seq[x];
        if (k%2 == 0) {
            return x&1^1;
        } else {
            if (x == 0 || x == 2 || (x >= 5 && x%2 == 1)) return 0;
            for (int k = 0; k < 32; k += 2) {
                ll p = (1ll<<k)*3;
                if (x == p) return 1;
            }
            for (int k = 1; k < 32; k += 2) if (x%(1ll<<k) == 0) {
                ll v = x/(1ll<<k);
                if (v >= 5 && (v&1)) return 1;
            }
            return 2;
        }
    };

    int ans = 0;
    while (n--) {
        int c; cin >> c;
        ans ^= nimber(c);
    }
    if (ans) cout << "Kevin\n";
    else cout << "Nicky\n";
    //x -> x-1
    //x -> 0
    //or
    //x -> x/2
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}