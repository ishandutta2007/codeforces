#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct Seg{
    pair<int, int> tree[800800];
    int lazy[800800];
    string str;
    void init(int i, int l, int r){
        tree[i] = make_pair(0, 0); lazy[i] = -1;
        if (l==r){
            if (str[l]=='0') tree[i].first=1;
            else tree[i].second=1;
            return;
        }
        int m = (l+r)>>1;
        init(i<<1, l, m); init(i<<1|1, m+1, r);
        tree[i] = make_pair(tree[i<<1].first+tree[i<<1|1].first, tree[i<<1].second+tree[i<<1|1].second);
    }
    void propagate(int i, int l, int r){
        if (lazy[i]==-1) return;
        if (lazy[i]==0) tree[i]=make_pair(r-l+1, 0);
        else tree[i]=make_pair(0, r-l+1);
        if (l!=r) lazy[i<<1] = lazy[i], lazy[i<<1|1] = lazy[i];
        lazy[i] = -1;
    }
    void update(int i, int l, int r, int s, int e, int val){
        propagate(i, l, r);
        if (r<s || e<l) return;
        if (s<=l && r<=e){
            lazy[i] = val; propagate(i, l, r);
            return;
        }
        int m = (l+r)>>1;
        update(i<<1, l, m, s, e, val); update(i<<1|1, m+1, r, s, e, val);
        tree[i] = make_pair(tree[i<<1].first+tree[i<<1|1].first, tree[i<<1].second+tree[i<<1|1].second);
    }
    pair<int, int> query(int i, int l, int r, int s, int e){
        propagate(i, l, r);
        if (r<s || e<l) return make_pair(0, 0);
        if (s<=l && r<=e) return tree[i];
        int m = (l+r)>>1;
        pair<int, int> tmp1=query(i<<1, l, m, s, e), tmp2 = query(i<<1|1, m+1, r, s, e);
        return make_pair(tmp1.first+tmp2.first, tmp1.second+tmp2.second);
    }
    void debug(int i, int l, int r){
        propagate(i, l, r);
        if (l==r){
            if (tree[i].first) str[l] = '0';
            else str[l] = '1';
            return;
        }
        int m = (l+r)>>1;
        debug(i<<1, l, m); debug(i<<1|1, m+1, r);
    }
}tree;

void solve(){
    int n, q;
    cin >> n >> q;
    string chk;
    cin >> chk >> tree.str;
    vector<pair<int, int>> query(q);
    for (int i=0;i<q;i++){
        cin >> query[i].first >> query[i].second;
    }
    bool ans=1;
    tree.init(1, 0, n-1);
    for (int i=q-1;i>=0;i--){
        pair<int, int> tmp = tree.query(1, 1, n, query[i].first, query[i].second);
        //printf(" %d %d\n", tmp.first, tmp.second);
        if (tmp.first==tmp.second){
            ans=0; break;
        }
        if (tmp.first<tmp.second) tree.update(1, 1, n, query[i].first, query[i].second, 1);
        else tree.update(1, 1, n, query[i].first, query[i].second, 0);
    }
    if (!ans){
        cout << "NO\n"; return;
    }
    tree.debug(1, 0, n-1);
    ans = (chk==tree.str);
    //cout << chk << '\n' << tree.str << '\n';
    if (ans) cout << "YES\n";
    else cout << "NO\n";
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