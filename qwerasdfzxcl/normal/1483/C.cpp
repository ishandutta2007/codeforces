#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct seg{
    ll tree[600600];
    int sz;
    void build(){
        for (int i=0;i<2*sz;i++) tree[i]=-1e18;
    }
    void update(int idx, ll val){
        idx += sz;
        for (tree[idx]=val;idx>1;idx>>=1) tree[idx>>1] = max(tree[idx], tree[idx^1]);
    }
    ll query(int l, int r){
        ll ret = -1e18;
        for (l += sz, r += sz;l<r;l>>=1, r>>=1){
            if (l&1) ret = max(ret, tree[l++]);
            if (r&1) ret = max(ret, tree[--r]);
        }
        return ret;
    }
}tree1, tree2;
int h[300300], n;
ll b[300300], dp[300300], dp2[300300];
vector<ll> curh;

int main(){
    scanf("%d", &n);
    tree1.sz=n, tree2.sz=n;
    tree1.build(); tree2.build();
    for (int i=1;i<=n;i++) scanf("%d", h+i);
    for (int i=1;i<=n;i++) scanf("%lld", b+i);
    for (int i=1;i<=n;i++){
        tree2.update((int)curh.size(), dp[i-1]);
        int tmp1 = lower_bound(curh.begin(), curh.end(), h[i])-curh.begin();
        ll mx1 = tree2.query(tmp1, (int)curh.size()+1) + b[i];
        ll mx2 = tree1.query(0, tmp1);
        dp[i] = max(mx1, mx2);
        //printf("%d %d(sz %d): %lld %lld %lld\n", i, tmp1, (int)curh.size(), dp[i], mx1, mx2);
        tree2.update((int)curh.size(), -1e18);
        for (int j=(int)curh.size()-1;j>=tmp1;j--){
            curh.pop_back();
            tree2.update(j, -1e18);
            tree1.update(j, -1e18);
        }
        tree2.update(tmp1, mx1-b[i]);
        tree1.update(tmp1, mx1);
        curh.push_back(h[i]);
    }
    printf("%lld\n", dp[n]);
    //printf("NLOGN: ");
    //for (int i=1;i<=n;i++) printf("%lld ", dp[i]);
    //printf("\n");
    /*printf("NAIVE: ");
    for (int i=1;i<=n;i++){
        dp2[i] = dp2[i-1]+b[i];
        int cur = h[i];
        ll cur2 = b[i];
        for (int j=i-1;j>0;j--){
            if (cur>h[j]){
                cur2=b[j]; cur=h[j];
            }
            dp2[i] = max(dp2[i], dp2[j-1]+cur2);
        }
        printf("%lld ", dp2[i]);
    }*/
    return 0;
}