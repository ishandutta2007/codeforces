#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;
    int cnt[2][2];
    int c[N];
    int n, m;
    ll ans_a;
    ll ans_b;
 
    char s[N];
    char t[N];
 
void input() {
    cin >> t; n = strlen(t);
    for(int i = 0; i < n; ) {
        int j = i;
        for(; j < n && t[i] == t[j]; ++j);
        s[m] = t[i];
        c[m] = j - i;
        i = j, m++;
    }
}
 
void solve() {
    int ind = 0;
    for(int i = 0; i < m; ++i) {
        int j = s[i] - 'a';
        int a = c[i] / 2;
        int b = c[i] - a;
        ll dif = c[i] + 1 >> 1;
        ll all = c[i] * 1ll * (c[i] + 1) >> 1;
        if(ind & 1) {
            ans_a += 1ll * cnt[j][1] * b + 1ll * cnt[j][0] * a;
            ans_b += 1ll * cnt[j][1] * a + 1ll * cnt[j][0] * b;
            cnt[j][0] += a;
            cnt[j][1] += b;
        }
        else {
            ans_a += 1ll * cnt[j][0] * b + 1ll * cnt[j][1] * a;
            ans_b += 1ll * cnt[j][0] * a + 1ll * cnt[j][1] * b;
            cnt[j][0] += b;
            cnt[j][1] += a;
        }
        ans_a += all + dif >> 1;
        ans_b += all - dif >> 1;
        ind += c[i];
    }
    cout << ans_b << " " << ans_a << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    input();
    solve();
}