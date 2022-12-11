#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 50;
ll mi[maxn<<2];
int id[maxn<<2];
ll a[maxn];
int n; ll p;
void up(int rt){
    mi[rt] = min(mi[rt<<1], mi[rt<<1|1]);
    if(mi[rt<<1] <= mi[rt<<1|1]) id[rt] = id[rt<<1];
    else id[rt] = id[rt<<1|1];
}
void build(int rt, int l, int r){
    if(l==r) {
        mi[rt] = a[l];
        id[rt] = l;
        return;
    }
    build(lson); build(rson); up(rt); return;
}
void update(int rt, int l, int r, int pos, ll x){
    if(l == r){
        mi[rt] = a[l] = x;
        return;
    }
    if(pos <= mid) update(lson, pos, x);
    else update(rson, pos, x);
    up(rt);
}
int qry(int rt, int l, int r, int L, int R, ll x){
    //cout<<"l:"<<l<<" r:"<<r<<endl;
    if(mi[rt] > x) return -1;
    if(l > R || r < L) return -1;
    if(l == r) return l;
    int ans = -1;
    if(L <= mid) ans = qry(lson, L, R, x);
    if(ans != -1) return ans;
    return qry(rson, L, R, x);
}
int qry2(int rt, int l, int r, int L, int R){
    if(L <= l && r <= R){
        return id[rt];
    }
    if(L <= mid && R > mid){
        int lid = qry2(lson, L, R);
        int rid = qry2(rson, L, R);
        if(a[lid] <= a[rid]) return lid; else return rid;
    }
    else if(L <= mid) return qry2(lson, L, R);
    else if(R > mid) return qry2(rson, L, R);
}
int q[maxn*2];
int head = 0, tail = 0;
ll ans[maxn];
int main()
{
	a[0] = inf;
	cin>>n>>p;
	for(int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
	build(1, 1, n);
	ll cur = 0;//
	for(int i = 0; i < n; ++i){
        if(head == tail){//
            int pos = qry(1, 1, n, 1, n, cur);
            if(pos != -1){
                q[tail++] = pos;
                update(1, 1, n, pos, inf);
                ans[pos] = cur + p;
            }
            else{
                pos = id[1];
                if(a[pos] == inf) break;
                q[tail++] = pos;
                ans[pos] = a[pos] + p;
                update(1, 1, n, pos, inf);
            }
        }//
        while(1){
            //cout<<"?"<<endl;
            int last = q[tail-1];
            int pos = qry2(1, 1, n, 1, last);
            //cout<<"last:"<<ans[last]<<endl;
            //cout<<"pos:"<<pos<<endl;
            if(a[pos] > ans[last]) break;
            //cout<<"pos:"<<pos<<endl;
            q[tail++] = pos;
            ans[pos] = ans[last] + p;
            update(1, 1, n, pos, inf);
        }
        //cout<<"!"<<endl;
        cur = ans[q[head]];
        head++;
	}
	for(int i = 1; i <= n; ++i){
        if(i > 1) printf(" ");
        printf("%I64d", ans[i]);
	}printf("\n");
}