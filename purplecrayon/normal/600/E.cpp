#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+10;

ll n, cols[MAXN], ans[MAXN];
vector<int> adj[MAXN];
unordered_map<ll, ll> c1[MAXN];
map<ll, ll> sm[MAXN];

void merge(int c, int nxt){
    if (c1[c].size() < c1[nxt].size()) c1[c].swap(c1[nxt]), sm[c].swap(sm[nxt]);
    for (auto it : c1[nxt]){
        ll oldAmt = c1[c][it.first];
        if (oldAmt) sm[c][oldAmt]-=it.first;
        c1[c][it.first]+=it.second;
        ll newAmt = oldAmt+it.second;
        sm[c][newAmt]+=it.first;
    }
    c1[nxt].clear(); sm[nxt].clear();
}
void dfs(int c, int p){
    c1[c][cols[c]]++; sm[c][1]+=cols[c];
    for (auto nxt : adj[c]) if (nxt != p) {
        dfs(nxt, c); merge(c, nxt);
    }
    // cout << c << ": "; for (auto it : sm[c]) cout << "(" << it.first << ", " << it.second << ") ";
    // cout << endl;
    // cout << c << ": "; for (auto it : c1[c]) cout << "(" << it.first << ", " << it.second << ") ";
    // cout << endl;
    ans[c] = sm[c].rbegin()->second;
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cols[i];
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs(0, -1); for (int i = 0; i < n; i++) cout << ans[i] << " ";
}