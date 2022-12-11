#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 1e5 + 50;
int sz[maxn];
void add(int i, int x){while(i < maxn) sz[i] += x, i += lowbit(i);}
int qry(int i){int res = 0; while(i) res += sz[i], i -= lowbit(i); return res;}
int n;
int cc[maxn];
int num ;
int op[maxn], val[maxn];
int lz[maxn*4];
ll sum[maxn*4][5];
void init()
{
    scanf("%d", &n);
    num = 0;
    for(int i = 0; i < n; ++i){
        //cout<<"i:"<<i<<endl;
        char cmd[10];
        scanf("%s", cmd);
        if(cmd[0] == 'a'){
            op[i] = 0; scanf("%d", &val[i]);
            cc[++num] = val[i];
        }
        else if(cmd[0] == 'd'){
            op[i] = 1; scanf("%d", &val[i]);
            cc[++num] = val[i];
        }
        else op[i] = 2;
        //cout<<"?"<<endl;
    }
    sort(cc+1,cc+1+num);
    num = unique(cc+1,cc+1+num) - cc - 1;
}
void go(int rt){//1
    ll temp = sum[rt][4];
    for(int i = 4; i > 0; --i) sum[rt][i] = sum[rt][i-1];
    sum[rt][0] = temp;
}
void down(int rt)
{
    if(lz[rt] == 0) return;
    int  t = (lz[rt]%5 + 5)%5;
    for(int i = 0; i < t; ++i) go(rt<<1), go(rt<<1|1);
    lz[rt<<1] += t;
    lz[rt<<1|1] += t;
    lz[rt] = 0;
}
void up(int rt)
{
    for(int i = 0; i < 5; ++i) sum[rt][i] = (sum[rt<<1][i] + sum[rt<<1|1][i]);
}
void update(int rt, int l, int r, int pos, int op){//pos
    if(l > pos){
        if(op == 0) {
            lz[rt]++;
            go(rt);
        }
        else{
            lz[rt]--;
            for(int i = 0; i < 4; ++i) go(rt);
        }
        return;
    }
    if(r <= pos) return;
    down(rt);
    update(rson, pos, op);
    update(lson, pos, op);
    up(rt);
}
void change(int rt, int l, int r, int pos, int res, int v){
    if(l == r){
        sum[rt][res] += v;
        return;
    }
    down(rt);
    if(pos <= mid) change(lson, pos, res, v);
    else change(rson, pos, res, v);
    up(rt);
    return ;
}
void sol()
{
    for(int i = 0; i < n; ++i){
        if(op[i] == 0){
            int pos = lower_bound(cc+1,cc+1+num, val[i]) - cc;
            int res = (qry(pos)+1)%5;
            change(1, 1, num, pos, res, val[i]);
            update(1, 1, num, pos, op[i]);
            add(pos, 1);
        }
        else if(op[i] == 1){
            int pos = lower_bound(cc+1,cc+1+num, val[i]) - cc;
            int res = qry(pos)%5;
            change(1, 1, num, pos, res, -val[i]);
            update(1, 1, num, pos, op[i]);
            add(pos, -1);
        }
        else{
//            if(op[i] == 0) cout<<"add: ";
//            else if(op[i] == 1) cout<<"del: ";
//            else cout<<"sum: ";
//            cout<<val[i]<<endl;
//            cout<<"ans:";
            printf("%I64d\n", sum[1][3]);
        }
    }
}
int main()
{
    init();
    sol();
}
/*
14
add 1
add 7
add 2
add 5
sum
add 6
add 8
add 9
add 3
add 4
add 10
sum
del 1
sum
*/