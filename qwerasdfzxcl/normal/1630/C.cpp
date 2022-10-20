#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int INF = 1e9;
struct Seg{
    int tree[400400], sz;
    void init(int n){
        sz = n;
        fill(tree, tree+sz*2, -INF);
    }
    void update(int p, int x){
        for (tree[p+=sz]=x;p>1;p>>=1) tree[p>>1] = max(tree[p], tree[p^1]);
    }
    int query(int l, int r){
        int ret = -INF;
        for (l+=sz, r+=sz;l<r;l>>=1, r>>=1){
            if (l&1) ret = max(ret, tree[l++]);
            if (r&1) ret = max(ret, tree[--r]);
        }
        return ret;
    }
}tree;
int dp[200200], a[200200], idx[200200];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++){
        scanf("%d", a+i);
        if (!idx[a[i]]) idx[a[i]] = i;
    }

    tree.init(n+1);
    tree.update(0, n);
    dp[0] = 0;
    for (int i=1;i<=n;i++){
        if (idx[a[i]]==i){
            //printf("YES %d\n", i);
            dp[i] = dp[i-1];
            tree.update(i, dp[i] + (n-i));
            continue;
        }

        int tmp = tree.query(idx[a[i]], i) - (n-i+1);
        dp[i] = tmp;
        tree.update(i, tmp + (n-i));
    }

    //for (int i=1;i<=n;i++) printf("%d ", dp[i]);
    //printf("\n");

    printf("%d\n", dp[n]);
    return 0;
}