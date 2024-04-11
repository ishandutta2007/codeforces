#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 1e5+5;
struct node{
    int a[3][3];
    node(){
        memset(a,0,sizeof a);
    }
    node operator + (node  x) {
        node res; memset(res.a,0x3f,sizeof res.a);
        for(int i = 0; i < 3; ++i){
            for(int k = i; k < 3; ++k){
                for(int j = k; j < 3; ++j){
                    res.a[i][j] = min(a[i][k]+x.a[k][j], res.a[i][j]);
                }
            }
        }return res;
    }
}e[maxn<<2];
char s[maxn]; int n;
void build(int rt, int l, int r){
    if(l == r){
        if(s[l] == 'a'){
            e[rt].a[0][0] = 1;
        }else if(s[l] == 'b'){
            e[rt].a[1][1] = 1;
        }else if(s[l] == 'c'){
            e[rt].a[2][2] = 1;
        }
        return;
    }
    build(lson); build(rson);
    e[rt] = e[rt<<1]+e[rt<<1|1];
    return;
}
void update(int rt, int l, int r, int pos){
    if(l == r){
        memset(e[rt].a, 0, sizeof e[rt].a);
        if(s[l] == 'a'){
            e[rt].a[0][0] = 1;
        }else if(s[l] == 'b'){
            e[rt].a[1][1] = 1;
        }else if(s[l] == 'c'){
            e[rt].a[2][2] = 1;
        }
        return;
    }
    if(pos <= mid) update(lson, pos);
    else update(rson, pos);
    e[rt] = e[rt<<1]+e[rt<<1|1];
    return;
}
int main(){
    int q; cin>>n>>q;
    scanf("%s", s+1);
    build(1, 1, n);
    while(q--){
        int p; char cmd[5];
        scanf("%d%s",&p, cmd);
        s[p] = cmd[0];
        update(1, 1, n, p);
        int ans = 0x3f3f3f3f;
        fors(i,0,3) fors(j,0,3) ans = min(ans, e[1].a[i][j]);
        printf("%d\n", ans);
    }
    return 0;
}