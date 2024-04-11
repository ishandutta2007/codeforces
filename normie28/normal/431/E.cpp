
// Problem : B. Game with modulo
// Contest : Codeforces - Codeforces Round #534 (Div. 1)
// URL : https://codeforces.com/contest/1103/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define all(a) (a).begin(),(a).end()
#define REP(i,n) for (int i = 0; i < (n); i++)
#define fornn(i, q, n) for(ll i = (ll)q; i < (ll)n; i++)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define bi BigInt
typedef long long ll;
typedef double db;
 
//---------END-------//
struct node
{
    int ch[2], v, fix, sz;
    ll su;
}t[1000005];
int ndtot = 0;
void pu(int x){
    t[x].su = t[t[x].ch[0]].su + t[t[x].ch[1]].su + t[x].v;
    t[x].sz = t[t[x].ch[0]].sz + t[t[x].ch[1]].sz + 1;
}
int root = 0;
void rot(int &x, int f){
    int y = t[x].ch[!f];
    t[x].ch[!f] = t[y].ch[f];
    t[y].ch[f] = x;
    pu(x);
    pu(y);
    x = y;
}
void ins(int &x, int v){
    if(x == 0){
        x =++ndtot;
        t[x].ch[0] = t[x].ch[1] = 0;
        t[x].sz = 1;
        t[x].fix = rand();
        t[x].v = t[x].su = v;
    }else{
        int f = v>= t[x].v;
        ins(t[x].ch[f],v);
        pu(x);
        if(t[t[x].ch[f]].fix < t[x].fix)rot(x,!f);
    }
}
void del(int &x){
    if(!t[x].ch[0] && !t[x].ch[1])
        x = 0;
    else{
        int f = !t[x].ch[0] || t[x].ch[1] && t[t[x].ch[1]].fix < t[t[x].ch[0]].fix;
        rot(x,!f);
        del(t[x].ch[!f]);
        pu(x);
    }
}
void del_num(int &x, int v){
    if(t[x].v == v)
        del(x);
    else{
        int f = v>= t[x].v;
        del_num(t[x].ch[f],v);
        pu(x);
    }
}
int n;
int cur[100005];
db queryans(db v){
    int p = root,q;
    ll presum = 0;
    int presz = 0;
    while(p){
        ll su = presum + t[t[p].ch[0]].su + t[p].v;
        int sz = presz + t[t[p].ch[0]].sz + 1;
        if(v >= 1ll * t[p].v * sz - su){
            presum = su;
            presz = sz;
            p=t[p].ch[1];
        }else p = t[p].ch[0];
    }
    return 1.0 * (presum + v) / presz;
}
int main()
{
    fio;
    t[0] = (node){{0,0},0,0,0,0};
    int que;
    scanf("%d%d", &n, &que);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &cur[i]);
    for (int i = 1; i <= n; ++i)
    ins(root, cur[i]);
    while(que--){
        int opt;
    scanf("%d", &opt);
        if(opt == 1){
            int x, y;
            scanf("%d%d", &x, &y);
            del_num(root, cur[x]);
            ins(root,cur[x] = y);
        }else{
            ll v;
            scanf("%I64d", &v);
            printf("%.5lf\n", queryans(v));
        }
    }
    return 0;
}