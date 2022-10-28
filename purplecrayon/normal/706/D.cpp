#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810, MAXC = MAXN*31;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

int q, nxt[MAXC][2], cnt[MAXC][2], cur;

void add(int x){
    int c = 0;
    for (int i = 31; i >= 0; i--){
        cnt[c][(x>>i)&1]++; if (nxt[c][(x>>i)&1] == -1) nxt[c][(x>>i)&1] = ++cur;
        c =  nxt[c][(x>>i)&1];
    }
}
void rem(int x){
    int c = 0;
    for (int i = 31; i >= 0; i--){
        cnt[c][(x>>i)&1]--; assert(nxt[c][(x>>i)&1] != -1);
        c = nxt[c][(x>>i)&1];
    }
}
int qry(int x){
    int c = 0, ans = 0;
    for (int i = 31; i >= 0; i--){
        if (cnt[c][((x>>i)&1)^1]) ans |= 1<<i, c = nxt[c][((x>>i)&1)^1];
        else c = nxt[c][(x>>i)&1];
    }
    return ans;
}
void solve(){
    cin >> q;
    memset(nxt, -1, sizeof(nxt)); memset(cnt, 0, sizeof(cnt)); cur = 0;
    add(0);
    while (q--){
        char t; int x; cin >> t >> x;
        if (t == '+') add(x);
        else if  (t == '-') rem(x);
        else if (t == '?') cout << qry(x) << "\n";
        else assert(false);
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}