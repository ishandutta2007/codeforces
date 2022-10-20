#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct Seg{
    ll tree[100100], sz;
    void init(int n){
        sz = n;
        fill(tree+1, tree+sz*2+1, -1e18);
    }
    void update(int p, ll x){
        for (tree[p+=sz]=x;p>1;p>>=1) tree[p>>1] = max(tree[p], tree[p^1]);
    }
    ll query(int l, int r){
        ll ret = -1e18;
        for (l+=sz, r+=sz;l<r;l>>=1, r>>=1){
            if (l&1) ret = max(ret, tree[l++]);
            if (r&1) ret = max(ret, tree[--r]);
        }
        return ret;
    }
}tree0, tree1, tree2;
int a[100100], L[100100], dp[100100];
ll S[100100];

void solve(){
    int n, x;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", a+i);
    scanf("%d", &x);

    for (int i=1;i<=n;i++) a[i] -= x;
    for (int i=1;i<=n;i++) S[i] = S[i-1] + a[i];

    tree0.init(n+2);
    for (int i=0;i<=n;i++) tree0.update(i, S[i]);

    for (int i=1;i<=n;i++){
        L[i] = i;
        int l = 1, r = i-1;
        while(l<=r){
            int m = (l+r)>>1;
            if (S[i] - tree0.query(m-1, i-1)>=0) L[i] = m, r = m-1;
            else l = m+1;
        }

        L[i] = max(L[i-1], L[i]);
    }

    tree1.init(n+2);
    tree2.init(n+2);

    tree1.update(0, 0);
    tree2.update(0, n-1);

    for (int i=1;i<=n;i++){
        int tmp = i - (L[i] - 1);
        dp[i] = max(tree1.query(0, L[i]-1), 0LL) + tmp;
        dp[i] = max((ll)dp[i], tree2.query(L[i]-1, (ll)i-1) - (n - i));

        tree1.update(i, dp[i]);
        tree2.update(i, dp[i] + (n - (i+1)));
    }

    printf("%lld\n", tree1.query(0, n+1));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}