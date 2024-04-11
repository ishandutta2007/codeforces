/********************************************************************************\
   |--\        ---       /\        |-----------| -----       /-------|           |
   |   \        |       /  \       |               |        /                    |
   |    \       |      /    \      |               |       |                     |
   |     \      |     /      \     |               |        \---\                |
   |      \     |    / ------ \    |-------|       |             \---\           |
   |       \    |   /          \   |               |                  |          |
   |        \   |  /            \  |               |                  /          |
  ---        \------            ------           -----     |---------/           |
                                                                                 |
                          _                                                      |
  **copyrighted by nfssdq(R) :) (:                                               |
                          ^                                                      |
    codeforces = nfssdq                                                          |
    topcoder = nafis007                                                          |
    uva = nfssdq                                                                 |
    spoj = nfssdq                                                                |
    usaco = nfssdq1                                                              |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                           |
    IIT,Jahangirnagar University(41)                                             |
    Sorry for badly written code.  :(                                            |
                                                                                 |
*********************************************************************************/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <locale>
#include <string>
#include <vector>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <functional>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000009ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

vector < int > vc[100001];
int st[100001],on[100001],en[100001];
int seg[400001], vis[100001];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[ idx ] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid)insert(idx*2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[ idx ] = max(seg[idx], v);
}
int query(int idx, int s, int e ,int st, int ed){
    if(st > ed)return 0;
    if(s == st && e == ed)return seg[idx];
    int mid = (s + e) / 2;
    if(ed <= mid)return query(idx*2+1, s, mid, st, ed);
    else if(st > mid)return query(idx*2+2, mid+1, e, st, ed);
    else return max( query(idx*2+1, s, mid, st, mid), query(idx*2+2, mid+1, e, mid+1, ed) );
}
int timer = 0;
int n, vv;
int height[100001];
void dfs1(int v, int hi){
    timer++;
    st[v] = timer;
    height[v] = hi;
    if( on[v] == 1 )insert(0, 1, n, timer, hi);
    REP(i, vc[v].size()){
        if(st[ vc[v][i] ] != 0)continue;
        dfs1(vc[v][i], hi+1);
        en[v] = en[ vc[v][i] ];
    }
    if(en[v] == 0)en[v] = st[v];
}
int cnt = 0;
void dfs2(int v, int mx){
    if(mx > vv)return;
    vis[v] = 1;
    if(query(0, 1, n, st[v], en[v]) - height[v] <= vv)cnt++;
    REP(i, vc[v].size()){
        int a = vc[v][i];
        if(vis[a] == 1)continue;
        int l = query(0, 1, n, st[v], st[a] - 1);
        int r = query(0, 1, n, en[a] + 1, en[v]);
        int m2 = mx + 1;
        if(mx == 0)m2 = 0;
        int m1 = max( m2, max(l, r) - height[v] + 1);
        dfs2(a, m1);
    }
}
main(){
    LL a,b,c,d,e,f,g,h,x,y,z;
    cin >> n >> a >> vv;
    REP(i, a){
        cin >> b;
        on[b] = 1;
    }
    REP(i, n-1){
        cin >> b >> c;
        vc[b].pb(c);
        vc[c].pb(b);
    }
    dfs1(1, 1);
    dfs2(1, 0);
    cout << cnt << endl;
}