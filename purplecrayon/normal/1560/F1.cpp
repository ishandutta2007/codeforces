#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

bool bad(int n, int k) {
    set<int> s;
    while (n) {
        s.insert(n%10);
        n /= 10;
    }
    return sz(s) > k;
}
void solve(){
    int n, k; cin >> n >> k;
    if (!bad(n, k)) {
        cout << n << '\n';
        return;
    }
    string s = to_string(n);
    for (int i = sz(s)-1; i >= 0; i--) {
        //first different digit
        bool vis[10]={};
        for (int j = 0; j < i; j++) vis[s[j]-'0']=1;
        int cnt = 0;
        for (int x = 0; x < 10; x++) cnt += vis[x];

        auto add = [&](int x) {
            if (vis[x]) return cnt;
            return cnt+1;
        };

        if (cnt > k) continue;
        for (int x = s[i]-'0'+1; x < 10; x++) if (add(x) <= k) {

            memset(vis, 0, sizeof(vis));
            for (int j = 0; j < i; j++) vis[s[j]-'0']=1;

            string ans = s;
            ans[i] = char('0'+x);

            cnt = add(x);
            vis[x] = 1;

            for (int j = i+1; j < sz(s); j++) {
                for (int y = 0; y < 10; y++) if (add(y) <= k) {
                    ans[j] = char('0'+y);

                    cnt = add(y);
                    vis[y] = 1;
                    break;
                }
            }
            cout << ans << '\n';
            return;
        }
    }
    assert(false);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}