
// Problem : F. Vicky's Delivery Service
// Contest : Codeforces - Codeforces Round #561 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1166/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int N = 1e5 + 5;
map<int, int> color[N];
set<int> S[N];
char tp[5];
int fa[N];
int _find(int x)
{
    if(x == fa[x]){
        return x;
    }
    else{
        return fa[x] = _find(fa[x]);
    }
}
void _union(int x, int y)
{
    int _x = _find(x), _y = _find(y);
    if(_x == _y){
        return ;
    } 
    if(S[_x].size() > S[_y].size()) swap(_x, _y);
    for(set<int>::iterator it = S[_x].begin(); it != S[_x].end(); it++){
        S[_y].insert(*it);
    }
    S[_x].clear();
    fa[_x] = _y;
}
void add(int x, int y, int z)
{
    int _x = _find(x), _y = _find(y);
    S[_x].insert(y);
    S[_y].insert(x);
    if(color[x].count(z)){
        _union(color[x][z], y);
    }
    else{
        color[x][z] = y;
    }
    if(color[y].count(z)){
        _union(color[y][z], x);
    }
    else{
        color[y][z] = x;
    }
}
int query(int x, int y)
{
    int _x = _find(x), _y = _find(y);
    if(_x == _y || S[_x].count(y)){
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    int n, m, c, q, x, y, z;
    scanf("%d %d %d %d", &n, &m, &c, &q);
    for(int i = 0; i < n; i++){
        fa[i] = i;
    }
    for(int i = 0; i < m; i++){
        
        scanf("%d %d %d", &x, &y, &z);
        add(x, y, z);
    }
    for(int i = 0; i < q; i++){
        scanf("%s", tp);
        if(tp[0] == '+'){
            scanf("%d %d %d", &x, &y, &z);
            add(x, y, z);
        }
        else{
            scanf("%d %d", &x, &y);
            printf("%s\n", query(x, y) ? "Yes" : "No");
        }
    }
    return 0;
}