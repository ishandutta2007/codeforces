#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
string s;
/*struct Seg{
    ll tree[2002000], lazy[2002000], cur;
    void propagate(int i, int l, int r){
        tree[i] += lazy[i]*(r-l+1);
        if (l!=r){
            lazy[i<<1] += lazy[i];
            lazy[i<<1|1] += lazy[i];
        }
        lazy[i] = 0;
    }
    void update(int i, int l, int r, int s, int e, int val){
        propagate(i, l, r);
        if (r<s || e<l) return;
        if (s<=l && r<=e){
            lazy[i] += val; propagate(i, l, r); return;
        }
        int m = (l+r)>>1;
        update(i<<1, l, m, s, e, val); update(i<<1|1, m+1, r, s, e, val);
        tree[i] = tree[i<<1] + tree[i<<1|1];
    }
    ll query(int i, int l, int r, int s, int e){
        propagate(i, l, r);
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return tree[i];
        int m = (l+r)>>1;
        return query(i<<1, l, m, s, e)+query(i<<1|1, m+1, r, s, e);
    }
    int lower_bound(int x){
        int l = 1, r = cur+1;
        while(l<r){
            int m = (l+r)>>1;
            if (query(1, 0, n, m, m)>=x) l = m+1;
            else r = m;
        }
        return l-1;
    }

}tree;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    tree.cur=0;
    ll ans = 0;
    int cur = 0;
    for (int r=0;r<n;r++){
        if (s[r]=='0'){
            tree.cur++;
            ans += tree.query(1, 0, n, 1, r+1);
            cur = 0;
        }
        else{
            int tmp = tree.lower_bound(cur+1);
            tree.update(1, 0, n, tmp+1, r+1, 1);
            tree.cur++;
            ans += tree.query(1, 0, n, 1, r+1);
            cur++;
        }
        //printf("%lld\n", ans);
    }
    printf("%lld\n", ans);
    return 0;
}*/

int L[500500];

///sol2
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    ll ans = 0, cur = 0;
    fill(L, L+n+1, -1);
    for (int i=0;i<n;i++){
        if (s[i]=='0'){
            ans += cur; continue;
        }
        int l = i, r = i;
        for (;r<n && s[r]=='1';r++);
        for (int j=1;j<=r-i;j++){
            ans += cur+(l+j-1)-L[j];
            cur += (l+j-1)-L[j];
            L[j] = r-j;
        }
        i = r-1;
    }
    printf("%lld\n", ans);
}