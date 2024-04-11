#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int n;
string s, t;
struct Seg{
    pair<int, int> tree[200200];
    int sz;
    pair<int, int> combine(pair<int, int> x, pair<int, int> y){
        return {min(x.first, y.first), x.second+y.second};
    }
    void init(int n){
        sz = n;
        for (int i=sz;i<sz*2;i++) tree[i] = {s[i-sz], 1};
        for (int i=sz-1;i;i--) tree[i] = combine(tree[i<<1], tree[i<<1|1]);
    }
    void update(int p){
        p += sz;
        tree[p].first = 100100;
        tree[p].second = 0;
        for (p>>=1;p;p>>=1) tree[p] = combine(tree[p<<1], tree[p<<1|1]);
    }
    pair<int, int> query(int l, int r){
        pair<int, int> ret = {100100, 0};
        for (l+=sz, r+=sz;l<r;l>>=1, r>>=1){
            if (l&1) ret = combine(ret, tree[l++]);
            if (r&1) ret = combine(ret, tree[--r]);
        }
        return ret;
    }
}tree;
vector<int> pos[100];

void solve(){
    cin >> n >> s >> t;
    for (int i=n-1;i>=0;i--) pos[s[i]-'a'].push_back(i);
    tree.init(n);

    //if (n==3) printf("%d %d\n", tree.query(0, 2).first-'a', tree.query(0, 2).second);

    ll ans = 1e18, cur = 0;
    for (int i=0;i<n;i++){
        int l = 0, r = n-1, idx = -1;
        while(l<=r){
            int m = (l+r)>>1;
            if (tree.query(0, m+1).first<t[i]) idx = m, r = m-1;
            else l = m+1;
        }
        if (idx!=-1) ans = min(ans, cur + tree.query(0, idx+1).second - 1);

        if (pos[t[i]-'a'].empty()) break;
        cur += tree.query(0, pos[t[i]-'a'].back()+1).second - 1;
        tree.update(pos[t[i]-'a'].back());
        pos[t[i]-'a'].pop_back();
        //printf("cur: %lld\n", cur);
    }
    //printf("%lld\n", ans);
    printf("%lld\n", ans==1e18?-1:ans);
    for (int i=0;i<26;i++) pos[i].clear();
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}