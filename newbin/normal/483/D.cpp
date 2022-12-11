#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 1e5 + 50;
int tree[31][maxn*4];
int n,m;
struct node{
    int l, r, x;
}e[maxn];
int ok = 1;
void update(int rt, int l, int r, int id, int L, int R){
    if(tree[id][rt] == r-l+1) return;
    if(L <= l && r <= R){
        tree[id][rt] = r-l+1;
        return;
    }
    if(L <= mid) update(lson, id, L, R);
    if(R > mid) update(rson, id, L, R);
    tree[id][rt] = tree[id][rt<<1] + tree[id][rt<<1|1];
    return;
}
bool check(int rt, int l, int r, int id, int L, int R){
    if(tree[id][rt] == r-l+1) {
        return false;
    }
    if(L <= l && r <= R){
        return true;
    }
    bool ans = false;
    if(L <= mid) ans |= check(lson, id, L, R);
    if(R > mid) ans |= check(rson, id, L, R);
    return ans;
}
int ans[31][maxn];
void dfs(int rt, int l, int r, int id){
    //cout<<"l:"<<l<<" r:"<<r<<endl;
    if(tree[id][rt] == r-l+1){
        for(int i = l; i <= r; ++i) ans[id][i] = 1;
        return;
    }
    else if(tree[id][rt] == 0) return;
    dfs(lson, id); dfs(rson, id);
}
int a[maxn];
int main(){
    scanf("%d%d",&n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d",&e[i].l, &e[i].r, &e[i].x);
        for(int j = 0; j < 30; ++j){
            if(e[i].x & (1<<j)) update(1, 1, n, j, e[i].l, e[i].r);
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < 30; ++j){
            if(!(e[i].x & (1<<j))) ok &= check(1, 1, n, j, e[i].l, e[i].r);
        }
    }
    if(!ok) printf("NO\n");
    else {
        printf("YES\n");
        for(int i = 0; i < 30; ++i) dfs(1, 1, n, i);
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < 30; ++j){
                a[i]|=(ans[j][i] << j);
            }
        }
        for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
    }
}