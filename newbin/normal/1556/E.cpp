#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
#define all(vec) vec.begin(),vec.end()
using namespace std;
const int maxn = 1e5+5;
ll mx[maxn<<2], mi[maxn<<2];
ll d[maxn], a[maxn], b[maxn], s[maxn];
int n, m;
void up(int rt){
    mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
    mi[rt] = min(mi[rt<<1], mi[rt<<1|1]);
}
void build(int rt, int l, int r){
    if(l == r){
        mi[rt] = mx[rt] = s[l]; return;
    }
    build(lson); build(rson); up(rt);
}
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll qry_mi(int rt, int l, int r, int L, int R){
    if(L <= l && r <= R) return mi[rt];
    ll res = inf;
    if(L <= mid) res = min(res, qry_mi(lson, L, R));
    if(R > mid) res = min(res, qry_mi(rson, L, R));
    return res;
}
ll qry_mx(int rt, int l, int r, int L, int R){
    if(L <= l && r <= R) return mx[rt];
    ll res = -inf;
    if(L <= mid) res = max(res, qry_mx(lson, L, R));
    if(R > mid) res = max(res, qry_mx(rson, L, R));
    return res;
}
int main()
{
    scanf("%d%d", &n, &m);
    fors(i,1,n+1) scanf("%lld", &a[i]);
    fors(i,1,n+1) scanf("%lld", &b[i]), d[i] = b[i]-a[i], s[i] = s[i-1]+d[i];
    build(1,1,n);
    while(m--){
        int l, r; scanf("%d%d", &l, &r);
        ll t1 = qry_mi(1,1,n,l, r);
        ll t2 = qry_mx(1,1,n,l,r);
        //cout<<"t1:"<<t1<<" t2:"<<t2<<endl;
        if(t1 < s[l-1] || s[l-1] != s[r]){
            puts("-1"); continue;
        }
        printf("%lld\n", t2-s[l-1]);
    }
	return 0;
}