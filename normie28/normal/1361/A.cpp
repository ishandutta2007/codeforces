
// Problem : A. Johnny and Contribution
// Contest : Codeforces - Codeforces Round #647 (Div. 1) - Thanks, Algo Muse!
// URL : https://codeforces.com/contest/1361/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
int n,m,k,c[501],pred[500001],done[500001],t,t1,i,j;
vector<int> gt[500001],pq;
int main()
{
//  ofile;
    fio;
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	gt[a].push_back(b);
    	gt[b].push_back(a);
    }
    for (i=1;i<=n;i++)
    {
    	cin>>pred[i];
    	pq.push_back(i);
    	done[i]=1;
    }
    for (i=1;i<=n;i++) for (k=0;k<gt[i].size();k++)
    {
    	j=gt[i][k];
    	 if (pred[i]==pred[j]) {
    	cout<<-1;
    	return 0;
    }
    }
    sort(pq.begin(),pq.end(),[](int a, int b){return (pred[a]<pred[b]);});
    for (ll ii=0;ii<n;ii++)
    {
    	i=pq[ii];
    	sort(gt[i].begin(),gt[i].end(),[](int a, int b){return (pred[a]<pred[b]);});
    	int mex=1;
    	for (ll jj=0;jj<gt[i].size();jj++)
    	{
    		j=gt[i][jj];
    		if (pred[j]==mex) mex++;
    		else if (pred[j]>mex) break;
    	}
    	if (mex!=pred[i]) {cout<<-1; return 0;}
    }
    for (i=0;i<n;i++) cout<<pq[i]<<' ';
}