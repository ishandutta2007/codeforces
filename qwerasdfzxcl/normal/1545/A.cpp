#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct Seg{
    ll tree[200200];
    int sz;
    void init(int n){
        sz = n;
        fill(tree, tree+(sz<<1), 0);
    }
    void update(int x){
        for (tree[x+=sz]+=1;x>1;x>>=1) tree[x>>1] = tree[x]+tree[x^1];
    }
    ll query(int l, int r){
        ll ret = 0;
        for (l += sz, r += sz;l<r;l>>=1, r>>=1){
            if (l&1) ret += tree[l++];
            if (r&1) ret += tree[--r];
        }
        return ret;
    }
}tree;
int a[100100], b[100100], val[100100][2];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        val[a[i]][i%2]++;
    }
    for (int i=0;i<n;i++) b[i] = a[i];
    sort(b, b+n);
    int r = 0;
    bool ans = 1;
    for (int i=0;i<n;i=r){
        while(r<n){
            if (b[i]!=b[r]) break;
            r++;
        }
        int cnt = r-i;
        int odd = cnt/2;
        if ((i%2==1) && ((r-1)%2==1)) odd++;
        if (val[b[i]][1]!=odd || val[b[i]][0]!=cnt-odd) ans = 0;
    }
    if (ans) printf("YES\n");
    else printf("NO\n");

    for (int i=0;i<n;i++){
        val[a[i]][i%2]--;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}