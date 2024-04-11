
// Problem : A. Diana and Liana
// Contest : Codeforces - Codeforces Round #543 (Div. 1, based on Technocup 2019 Final Round)
// URL : https://codeforces.com/contest/1120/problem/A
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
int n,m,k,c[501],maxx[500001],t,t1,i,j;
pair<int,int> dp[500001];
int arr[500001],req[500001],got[500001],satisfy;
vector<int> res,res2;
int main()
{
//  ofile;
    fio;
    cin>>m>>k>>n>>t;
    for (i=1;i<=m;i++) cin>>arr[i];
    for (i=1;i<=t;i++) 
    {
    	cin>>j;
    	req[j]++;
    	if (req[j]==1) satisfy++;
    }
    j=m;
    for (i=m;i>=1;i--)
    {
    	if (i<m)
    	{
    		got[arr[i+1]]--;
    		if (got[arr[i+1]]<req[arr[i+1]]) satisfy++;
    	}
    	while(true)
    	{
    		if (satisfy==0) break;
    		if (j==-1) break;
    		j--;
    		if (j==-1) break;
    		got[arr[j+1]]++;
    		if (got[arr[j+1]]==req[arr[j+1]]) satisfy--;
    		if (satisfy==0) break;
    	}
    	maxx[i]=j;
//    	cout<<i<<' '<<maxx[i]<<endl;
    }
    for (i=1;i<=500000;i++) got[i]=0;
    for (i=1;i<=m;i++)
    {
    	res.clear();
 //   	cout<<i<<' '<<maxx[i]<<endl;
    	if ((maxx[i]!=-1))
    	{
    		int cut0=max(i-maxx[i]-k,0);
    		int cut=cut0+(i-cut0)%k;
    		if (m-cut<n*k) continue;
    			int c1=maxx[i],c3=i-maxx[i];
    			for (int c2=c1+1;c2<=i;c2++)
    			{
    				got[arr[c2]]++;
    				if ((got[arr[c2]]>req[arr[c2]])) if (c3>k){ res2.push_back(c2); c3--;}
    				else res.push_back(c2);
    			}
    			for (int c2=1;c2<=maxx[i];c2++) res.push_back(c2);
    			for (int c2=i+1;c2<=m;c2++) res.push_back(c2);
    			sort(res.begin(),res.end(),[](int a, int b){return (a>b); });
    			for (j=0;j<(i-cut0)%k;j++) res2.push_back(res[res.size()-1-j]);
    			cout<<res2.size();
    			cout<<endl;
    			for (int g : res2) cout<<g<<' ';
    			return 0;
    	}
    }
    cout<<-1;
}