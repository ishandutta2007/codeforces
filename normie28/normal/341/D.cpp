
// Problem : D. Iahub and Xors
// Contest : Codeforces - Codeforces Round #198 (Div. 1)
// URL : https://codeforces.com/problemset/problem/341/D
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
#define y1 yyy1
#define int ll
typedef long long ll;
//---------END-------//
int n,m,x1,y1,x2,y2;
int op, val;
int multree[1010][1010][2];
int addtree[1010][1010][2];
 
int query2(int tree[1010][1010][2], int x, int y) {
    int mul = 0, add = 0;
    for (int j = y; j > 0; j -= j&-j) {
        mul ^= tree[x][j][0];
        add ^= tree[x][j][1];
    }
 
    return (mul * (y%2)) ^ add;
}
 
int query1(int x, int y) {
    int mul = 0, add = 0;
 
    for (int i = x; i > 0; i -= i&-i) {
        mul ^= query2(multree, i, y);
        add ^= query2(addtree, i, y);
    }
 
    return (mul * (x%2)) ^ add;
}
 
 
int query(int x1, int x2, int y1, int y2) {
    return query1(x2, y2) ^ query1(x1-1, y2) ^ query1(x2, y1-1) ^ query1(x1-1, y1-1);
}
 
int ev(int x) { return x%2; }
 
void update2(int tree[1010][1010][2], int x, int y, int mul, int add) {
    for (int i = x; i <= n; i += i&-i) {
        for (int j = y; j <= n; j += j&-j) {
            tree[i][j][0] ^= mul;
            tree[i][j][1] ^= add;
        }
    }
}
 
void update1(int x, int y1, int y2, int mul, int add) {
    update2(multree, x, y1, mul, mul * ev(y1 - 1));
    update2(multree, x, y2, mul, mul * ev(y2));
 
    update2(addtree, x, y1, add, add * ev(y1 - 1));
    update2(addtree, x, y2, add, add * ev(y2));
}
 
void update(int x1, int x2, int y1, int y2, int by) {
    update1(x1, y1, y2, by, by * ev(x1 - 1));
    update1(x2, y1, y2, by, by * ev(x2));
}
 signed main() {
	fio;
	cin>>n>>m;
    for (int i = 0; i < m; i++) {
    	cin>>op>>x1>>y1>>x2>>y2;
        if (op == 2) {
        	cin>>val;
            update(x1,x2,y1,y2,val);
        }
        else {
            cout<<query(x1,x2,y1,y2)<<endl;
        }
    }
}