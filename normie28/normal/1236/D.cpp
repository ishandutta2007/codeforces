
// Problem : G. Running in Pairs
// Contest : Codeforces - Codeforces Round #592 (Div. 2)
// URL : https://codeforces.com/contest/1244/problem/G
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
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//

const int maxn = 1e5 + 5;
 
int n, m, k;
set<int> o1[maxn], o2[maxn];
 
int main()
{
    cin >> n >> m >> k;
    long long sm = 1ll * n * m - k;
 
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        o1[x].insert(y);
        o2[y].insert(x);
    }
 
    for (int i = 1; i <= n; i++)
    {
        o1[i].insert(0);
        o1[i].insert(m + 1);
    }
 
    for (int i = 1; i <= m; i++)
    {
        o2[i].insert(0);
        o2[i].insert(n + 1);
    }
 
    int cx = 1, cy = 0, lb = 0, rb = m + 1, ub = 1, db = n + 1, typ = 0;
    while (1)
    {
        if (typ % 4 == 0)
        {
            rb = min(rb, *o1[cx].upper_bound(cy));
            if (rb == cy + 1)
                break;
            rb--;
            sm -= rb - cy;
            cy = rb;
        }
        else if (typ % 4 == 1)
        {
            db = min(db, *o2[cy].upper_bound(cx));
            if (db == cx + 1)
                break;
            db--;
            sm -= db - cx;
            cx = db;
        }
        else if (typ % 4 == 2)
        {
            lb=max(lb,*--o1[cx].lower_bound(cy));
            if(lb==cy-1)break;
            lb++;
            sm-=cy-lb;
            cy=lb;
        }
        else if (typ % 4 == 3)
        {
            ub=max(ub,*--o2[cy].lower_bound(cx));
            if(ub==cx-1)break;
            ub++;
            sm-=cx-ub;
            cx=ub;
        }
        typ++;
    }
 
    // cerr<<sm<<endl;
    cout<<(sm?"No":"Yes");
}