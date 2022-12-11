#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define lson ls[rt], l, mid
#define rson rs[rt], mid+1, r
#define ll long long
using namespace std;
const int maxn = 1e3 + 50;
int n, m ,q;
struct node{
    int p[maxn];
    int r;
    int val;
}e[maxn*100];
int T[maxn*101];
int sum[2000*maxn], ls[maxn*2000], rs[maxn*2000];
int pos;
int tot = 0;
int cnt = 0;
void build(int pre, int cur, int l, int r, int op, int x){
    ls[cur] = ls[pre];
    rs[cur] = rs[pre];
    sum[cur] = sum[pre];
    if(l == r){
        sum[cur] = ++cnt;

        for(int i = 1; i <= m; ++i) e[sum[cur]].p[i] = e[sum[pre]].p[i];
        e[sum[cur]].r = e[sum[pre]].r;
        e[sum[cur]].val = e[sum[pre]].val;
        //cout<<"r:"<<e[cur].r<<" val:"<<e[sum[cur]].val<<endl;
        if(op == 1){//op1
            if(e[sum[cur]].r == 0){//
                if(e[sum[cur]].p[pos] == 0){
                    e[sum[cur]].p[pos] = 1;
                    e[sum[cur]].val++;
                }
            }
            else{//
                if(e[sum[cur]].p[pos] == 1){
                    e[sum[cur]].p[pos] = 0;
                    e[sum[cur]].val++;
                }
            }
        }
        else if(op == 2){
            if(e[sum[cur]].r == 0){//
                if(e[sum[cur]].p[pos] == 1){
                    e[sum[cur]].p[pos] = 0;
                    e[sum[cur]].val--;
                }
            }
            else{//
                if(e[sum[cur]].p[pos] == 0){
                    e[sum[cur]].p[pos] = 1;
                    e[sum[cur]].val--;
                }
            }
        }
        else{
            e[sum[cur]].r ^= 1;
            e[sum[cur]].val = m - e[sum[cur]].val;
        }
        return;
    }
    if(x <= mid) build(ls[pre], ls[cur] = ++tot, l, mid, op, x);
    else build(rs[pre], rs[cur] = ++tot, mid+1, r, op, x);

    int s1, s2;
    if(mid-l+1 == 1) s1 = e[sum[ls[cur]]].val;
    else s1 = sum[ls[cur]];
    if(r-mid == 1) s2 = e[sum[rs[cur]]].val;
    else s2 = sum[rs[cur]];

    sum[cur] = s1 + s2;
    return;
}
int main()
{
    scanf("%d%d%d",&n, &m, &q);
    for(int i = 1; i <= q; ++i){
        int op, x;
        scanf("%d%d",&op, &x);
        if(op < 3) scanf("%d", &pos);
        if(op < 4) build(T[i-1], T[i] = ++tot, 1, n, op, x);
        else T[i] = T[x];
        if(n > 1) printf("%d\n",sum[T[i]]);
        else printf("%d\n", e[sum[T[i]]].val);
    }
}