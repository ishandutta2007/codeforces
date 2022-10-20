#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
const double eps = 1e-10;
int a[maxn], dp[maxn][3];
int bit[maxn], n;
void add(int x) {
    while(x <= n) {
        bit[x]++;
        x += (x&(-x));
    }
}
int query(int x) {
    int ans = 0;
    while(x) {
        ans += bit[x];
        x -= (x&(-x));
    }
    return ans;
}
queue<int> pos[30];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i <= n; i++) bit[i] = 0;
        for(int i = 0; i < 30; i++) while(!pos[i].empty()) pos[i].pop();
        string s, t;
        cin >> s >> t;
        s = "#" + s;
        t = "#" + t;
        for(int i = 1; i <= n; i++) {
            pos[s[i]-'a'].push(i);
        }
        int ans = 1e18, cur = 0;
        for(int i = 1; i <= n; i++) {
            int x = t[i] - 'a';
            for(int j = 0; j < x; j++) {
                if(pos[j].empty()) continue;
                int k = pos[j].front();
                ans = min(ans, cur + k-query(k)-1);
            }
            if(pos[x].empty()) break;
            int k = pos[x].front();
            pos[x].pop();
            cur += k-query(k)-1;
            add(k);
        }
        if(ans > 5e17) ans = -1;
        cout << ans << endl;
    }
    return 0;
}