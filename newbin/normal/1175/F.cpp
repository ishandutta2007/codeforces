#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 3e5 + 5;
const int inf = 0x3f3f3f3f;
int lz[maxn*4], val[maxn*4], mi[maxn<<2], mx[maxn<<2], cnt[maxn<<2];
void up(int rt){
    val[rt] = min(val[rt<<1], val[rt<<1|1]);
    cnt[rt] = 0;
    if(val[rt] == val[rt<<1]) cnt[rt] += cnt[rt<<1];
    if(val[rt] == val[rt<<1|1]) cnt[rt] += cnt[rt<<1|1];

    mi[rt] = min(mi[rt<<1], mi[rt<<1|1]);
    mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
    return;
}
void down(int rt, int l, int r){
    if(lz[rt] != -1){
        lz[rt<<1] = mi[rt<<1] = mx[rt<<1] = lz[rt];
        val[rt<<1] = l-lz[rt]+1; cnt[rt<<1] = 1;

        lz[rt<<1|1] = mi[rt<<1|1] = mx[rt<<1|1] = lz[rt];
        val[rt<<1|1] = (mid+1)-lz[rt]+1; cnt[rt<<1|1] = 1;
        lz[rt] = -1;
        return;
    }
}
void build(int rt, int l, int r){
    lz[rt] = -1;
    if(l == r){
        val[rt] = 1; mi[rt] = mx[rt] = l; cnt[rt] = 1;
        return;
    }
    build(lson); build(rson); up(rt);
}
void update(int rt, int l, int r, int L, int R, int x){
    if(mx[rt] <= x) return;
    if(L <= l && r <= R){
        if(mi[rt] > x){
            //cout<<"L:"<<l<<" R:"<<r;
            lz[rt] = mi[rt] = mx[rt] = x;
            val[rt] = l - x + 1;
            cnt[rt] = 1;
            //cout<<" val:"<<val[rt]<<endl;
            return;
        }else{
            down(rt, l, r);
            update(lson, L,R,x);
            update(rson, L,R,x);
            up(rt);
            return;
        }
    }
    down(rt, l, r);
    if(L <= mid) update(lson, L, R, x);
    if(R > mid) update(rson, L, R, x);
    up(rt);
    //cout<<"l:"<<l<<" r:"<<r<< " val:"<<val[rt]<<endl;
    return;
}
int a[maxn];
int n;
vector<int> p[maxn];
int main()
{
    scanf("%d", &n);
    fors(i,1,n+1) scanf("%d", &a[i]), p[a[i]].pb(i);
    ll ans = 0;
    build(1, 1, n);
    for(int x = 1; x <= n; ++x){
        if(p[x].size() == 0) break;
        int d = p[x][0];
        if(d > 1) update(1, 1, n, 1, d-1, -inf);
        for(int i = 0; i < p[x].size(); ++i){
            int l = p[x][i];
            int r;
            if(i+1 == p[x].size()) r = n;
            else r = p[x][i+1]-1;
            //cout<<"x:"<<x<<" l:"<<l<<" r:"<<r<<endl;
            update(1, 1, n, l, r, l);
            //cout<<"val:"<<val[1]<<" cnt:"<<cnt[1]<<endl;
        }
        //cout<<"val:"<<val[1]<<" cnt:"<<cnt[1]<<endl;
        if(val[1] == x) {
            ans += cnt[1];
            //cout<<"x:"<<x<<endl;
        }
    }
    cout<<ans<<endl;
}