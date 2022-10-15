
// Problem : E. Cubes
// Contest : Codeforces - Codeforces Round #116 (Div. 2, ACM-ICPC Rules)
// URL : https://codeforces.com/problemset/problem/180/E
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
typedef long long ll;
//---------END-------//
int n,m,k,c[501],col[300001],pos[300001],t,t1,i,j;
vector<int> lis[100001];
int check (int x)
{
	for (int i=1;i<=n;i++)
	{
		if ((lis[col[i]].size()-1>=pos[i]+x-1)and(lis[col[i]][pos[i]+x-1]-i+1<=x+k)) return 1;
	}
	return 0;
}
int bs (int l, int r)
{
	if (l==r) return l;
	int mid=(l+r)/2+1;
	if (check(mid)) return bs(mid,r); else return bs(l,mid-1);
}
int main()
{
//  ofile;
    fio;
    cin>>n>>m>>k;
    for (i=1;i<=n;i++)
    {
    	cin>>col[i];
    	lis[col[i]].push_back(i);
    	pos[i]=lis[col[i]].size()-1;
    }
    cout<<bs(1,n);
}