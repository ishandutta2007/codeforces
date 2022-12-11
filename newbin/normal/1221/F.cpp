#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define P pair<int, ll>
using namespace std;
const int maxn = 1e6 + 50;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll mx[maxn<<2], lz[maxn<<2], mxid[maxn<<2];
int n;
int cc[maxn<<1], num;
int x[maxn], y[maxn];
ll a[maxn];
vector<P> q[maxn<<1];
void init(){
    num = 0;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        scanf("%d%d%I64d", &x[i], &y[i], &a[i]);
        cc[++num] = x[i]; cc[++num] = y[i];
    }
    sort(cc+1,cc+1+num); num = unique(cc+1,cc+1+num) - cc - 1;
    for(int i = 1; i <= n; ++i){
        x[i] = lower_bound(cc+1,cc+1+num,x[i])-cc;
        y[i] = lower_bound(cc+1,cc+1+num,y[i])-cc;
        if(x[i] > y[i]) swap(x[i], y[i]);
        //cout<<"x:"<<x[i]<<" y:"<<y[i]<<endl;
        q[x[i]].push_back(P(y[i], a[i]));
    }
}
void up(int rt){
    if(mx[rt<<1] >= mx[rt<<1|1]) mx[rt] = mx[rt<<1], mxid[rt] = mxid[rt<<1];
    else mx[rt] = mx[rt<<1|1], mxid[rt] = mxid[rt<<1|1];
}
void down(int rt){
    lz[rt<<1] += lz[rt]; lz[rt<<1|1] += lz[rt];
    mx[rt<<1] += lz[rt]; mx[rt<<1|1] += lz[rt];
    lz[rt] = 0; return;
}
void build(int rt, int l, int r){
    if(l == r) {
        mx[rt] = -cc[l]; mxid[rt] = l;return;
    }build(lson); build(rson); up(rt);
    return;
}
void update(int rt, int l, int r, int L, int R, ll k){
    if(L <= l && r <= R){
        lz[rt] += k; mx[rt] += k;return;
    }down(rt);
    if(L <= mid) update(lson, L, R, k);
    if(R > mid) update(rson, L, R, k);
    up(rt);
    return;
}
ll cmx, cid;//
void qry(int rt, int l, int r, int L, int R){
    if(L <= l && r <= R){
        if(mx[rt] > cmx) cmx = mx[rt], cid = mxid[rt];
        //cout<<"l:"<<l<<" r:"<<r<<" id:"<<mxid[rt]<<endl;
        return;
    }down(rt);
    if(L <= mid) qry(lson, L, R);
    if(R > mid) qry(rson, L, R);
}
void sol(){
    ll ans = 0;
    int cx = cc[num]+1, cy = cc[num]+1;
    build(1, 1, num);
    for(int i = num; i >= 1; --i){
        for(int j = 0; j < q[i].size(); ++j){
            int r = q[i][j].first;
            ll w = q[i][j].second;
            update(1, 1, num, r, num, w);
        }
        cmx = -inf; cid = -1;
        qry(1, 1, num, i, num);
        if(ans < cmx+cc[i]){
            ans = cmx+cc[i];
            cx = cc[i];
            cy = cc[cid];
        }
    }
    cout<<ans<<endl;
    cout<<cx<<" "<<cx<<" "<<cy<<" "<<cy<<endl;
}
int main()
{
	init();
	sol();
}