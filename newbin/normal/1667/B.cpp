#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5e5+5;
struct tree{
    ll mx[maxn<<2];
    void up(int rt){
        mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
    }
    void build(int rt, int l, int r){
        mx[rt] = -inf;
        if(l == r) return;
        build(lson); build(rson); return;
    }
    void update(int rt, int l, int r, int pos, ll val){
        if(l == r){
            mx[rt] = max(mx[rt], val); return;
        }
        if(pos <= mid) update(lson, pos, val);
        else update(rson, pos, val);
        up(rt);
    }
    ll qry(int rt, int l, int r, int L, int R){
        if(L <= l && r <= R) return mx[rt];
        ll res = -inf;
        if(L <= mid) res = max(res, qry(lson, L, R));
        if(R > mid) res = max(res, qry(rson, L, R));
        return res;
    }
}t1, t2;
int n;
ll s[maxn], cc[maxn], a[maxn];
int num;
void init(){
    cin>>n;
    num = 0;
    s[0] = 0;
    fors(i,1,n+1) scanf("%lld", &a[i]), s[i] = a[i]+s[i-1], cc[++num] = s[i];

    cc[++num] = 0;
    sort(cc+1, cc+1+num);
    num = unique(cc+1, cc+1+num)-cc-1;

    fors(i,0,n+1) s[i] = lower_bound(cc+1,cc+1+num, s[i])-cc;
}
ll f[maxn];
void sol(){
    t1.build(1, 1, num); t2.build(1, 1, num);
    t1.update(1, 1, num, s[0], 0);//-i
    t2.update(1, 1, num, s[0], 0);//+i
    map<int, ll> v; v.clear();

    v[s[0]] = 0;

    for(int i = 1; i <= n; ++i){
        f[i] = -inf;
        if(s[i] > 1) f[i] = max(f[i], t1.qry(1, 1, num, 1, s[i]-1)+i);
        if(s[i] < num) f[i] = max(f[i], t2.qry(1, 1, num, s[i]+1, num)-i);
        if(v.count(s[i])) f[i] = max(f[i], v[s[i]]);

        if(v.count(s[i])) v[s[i]] = max(v[s[i]], f[i]);
        else v[s[i]] = f[i];
        t1.update(1, 1, num, s[i], f[i]-i);
        t2.update(1, 1, num, s[i], f[i]+i);
    }
    cout<<f[n]<<endl;
}
int main(){
    int T; cin>>T;
    while(T--){
        init() ;
        sol();
    }
    return 0;
}