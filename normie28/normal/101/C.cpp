
// Problem : C. Vectors
// Contest : Codeforces - Codeforces Beta Round #79 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/101/C
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
typedef long long LL;
//---------END-------//
 
LL x[4], y[4];
LL ax, ay;
LL bx, by;
LL cx, cy;
 
int main()
{
	fio;
    cin>>x[0]>>y[0];
    cin>>bx>>by;
    cin>>cx>>cy;
    for(int i = 1; i < 4; i++)
    {
        x[i] = -y[i - 1];
        y[i] = x[i - 1];
    }
    int fl = 0;
    for(int i = 0; i < 4; i++)
    {
        x[i] = bx - x[i];
        y[i] = by - y[i];
        if(x[i] == 0 && y[i] == 0)
            fl = 1;
    }
    LL fm = cx * cx + cy * cy;
    if(fm != 0)
    {
        for(int i = 0; i < 4; i++)
        {
            LL fz1 = cx * x[i] + cy * y[i];
            LL fz2 = cy * x[i] - cx * y[i];
            if(fz1 % fm == 0 && fz2 % fm == 0)
                fl = 1;
        }
    }
    if(fl == 1)
    	cout<<"YES";
    else
    	cout<<"NO";
}