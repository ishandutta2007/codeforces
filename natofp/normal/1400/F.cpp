#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple

using namespace std;

const int K = 10;
const int inf = 1e9;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    int dp[1005];
    bool calculated;
    bool match;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
        fill(begin(dp), end(dp), inf);
        calculated = false;
        match = false;
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - '0';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - '0';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

set<string> bad;
int x;

void gene(string cur, int sum){
    if(sum > x) return;
    int sz = cur.size();
    int tot = 0;
    for(int i=sz-1;i>=0;i--){
        tot += cur[i] - '0';
        if(x % tot == 0 && tot != x) return;
    }
    if(sum == x){
        bad.insert(cur);
        return;
    }
    for(char i='1';i<='9';i++){
        cur += i;
        gene(cur, sum + i - '0');
        cur.pop_back();
    }
}

bool bad_state(int v){
    if(t[v].calculated) return t[v].match;
    t[v].calculated = true;
    t[v].match = t[v].leaf;
    if(v != 0) t[v].match |= bad_state(get_link(v));
    return t[v].match;
}

void upd(int &a, int b){
    a = min(a, b);
}

void solve(){
    string s; cin >> s;
    cin >> x;
    gene("", 0);
    for(auto cur : bad) add_string(cur);
    int sz = t.size();
    t[0].dp[0] = 0;
    int n = s.size();
    int ans = inf;
    for(int i=0;i<n;i++){
        char nxt = s[i];
        for(int j=0;j<sz;j++){
            int to = go(j, nxt);
            if(!bad_state(to)) upd(t[to].dp[i + 1], t[j].dp[i]);
            upd(t[j].dp[i + 1], t[j].dp[i] + 1);
        }
    }
    for(int j=0;j<sz;j++){
        ans = min(ans, t[j].dp[n]);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}