#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

const int MAXA = 8e5+10;

int n, m = 1;
string s[MAXN], t[MAXN];

int nxt[MAXA][26], cnt[MAXA][2];
vector<int> leaf[MAXA];
int match[MAXN];

void ins(string s, int b, int ind) {
    int c = 0;

    cnt[c][b]++;
    for (int i = 0; i < sz(s); i++) {
        int me = s[i]-'a';
        if (nxt[c][me] == -1) nxt[c][me] = m++;
        c = nxt[c][me], cnt[c][b]++;
    }
    leaf[c].push_back(ind);
}
void merge(vector<int>& a, vector<int>& b) {
    if (sz(a) < sz(b)) swap(a, b);
    for (auto c : b) a.push_back(c);
    b.clear();
}
pair<ll, pair<vector<int>, vector<int>>> dfs(int c = 0, int d = 0) {
    ll ans = 0;
    vector<int> left_a, left_b;
    for (int i = 0; i < 26; i++) if (nxt[c][i] != -1) {
        auto he = dfs(nxt[c][i], d+1);
        ans += he.first;
        merge(left_a, he.second.first);
        merge(left_b, he.second.second);
    }
    for (auto x : leaf[c]) {
        if (x < n) left_a.push_back(x);
        else left_b.push_back(x-n);
    }
    while (sz(left_a) && sz(left_b)) {
        int a = left_a.back(), b = left_b.back();
        match[a] = b;

        left_a.pop_back(), left_b.pop_back();
        ans += d;
    }
    return {ans, {left_a, left_b}};
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> t[i];

    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < n; i++) ins(s[i], 0, i), s[i] = "";
    for (int i = 0; i < n; i++) ins(t[i], 1, n+i), t[i] = "";

    cout << dfs().first << '\n';
    for (int i = 0; i < n; i++) {
        cout << i+1 << ' ' << match[i]+1 << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}