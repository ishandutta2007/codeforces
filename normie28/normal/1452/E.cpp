
/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
 
//---------END-------//
 
int n,m,i,j,k,t,u,v,a,b,res=0;
int cur[2001],diff[2001],maxx[2001];
int l[2001],r[2001];
int cnt[2001][2001];
vector<int> buc[2001][2001];
int main()
{
	fio;
	cin>>n>>m>>k;
	for (i=1;i<=m;i++)
	{
		cin>>l[i]>>r[i];
		for (j=1;j+k-1<=n;j++)
		{
			cnt[i][j]=max(0,min(j+k-1,r[i])-max(j,l[i])+1);
			buc[i][cnt[i][j]].push_back(j);
			maxx[i]=max(maxx[i],cnt[i][j]);
		}
		u+=cnt[i][1];
		for (j=1;j+k-1<=n;j++) cur[j]+=max(0,cnt[i][j]-cnt[i][1]);
	}
	for (i=1;i<=m;i++) 
	{
//	    for (j=1;j<=n-k+1;j++) cout<<cnt[i][j]<<' ';
//	    cout<<endl;
	     
	}
	for (i=1;i<=n-k+1;i++)
	{
//	    cout<<"now at: "<<i<<endl;
	    if (i>1)
	    {
	    for (j=1;j<=n-k+1;j++) diff[j]=0;
	    for (j=1;j<=m;j++)
	    {
//	    	cout<<"checking ";
//	        	cout<<j<<endl;
//	        	cout<<cnt[j][i]<<' '<<cnt[j][i-1]<<endl;
	        if (cnt[j][i]-cnt[j][i-1]==1)
	        {
//	        	cout<<"increase found\n";
//	        	cout<<cnt[j][i]<<endl;
//	        	cout<<buc[j][cnt[j][i]][0]<<endl;
//	        	cout<<buc[j][cnt[j][i]][buc[j][cnt[j][i]].size()-1]<<endl;
	            diff[buc[j][cnt[j][i]][0]]--;
	            if ((buc[j][cnt[j][i]].size()>1)or(cnt[j][i]==maxx[j]))
	            {
	            if (buc[j][cnt[j][i]][buc[j][cnt[j][i]].size()-1]+1<=n-k+1)
	            {
	                diff[buc[j][cnt[j][i]][buc[j][cnt[j][i]].size()-1]+1]++;
	            }
	        	}
	        }
	        else if (cnt[j][i]-cnt[j][i-1]==-1)
	        {
	            if ((buc[j][cnt[j][i-1]].size()>1)or(cnt[j][i-1]==maxx[j]))
	            {
	            diff[buc[j][cnt[j][i-1]][0]]++;
	        	}
	        	else diff[1]++;
	        	
	            if (buc[j][cnt[j][i-1]][buc[j][cnt[j][i-1]].size()-1]+1<=n-k+1)
	            {
	                diff[buc[j][cnt[j][i-1]][buc[j][cnt[j][i-1]].size()-1]+1]--;
	            }
	        }
	    }
	    
	//        cout<<"array diff : \n";
//	    for (j=1;j<=n-k+1;j++) cout<<diff[j]<<' '; cout<<endl;
	    a=0;
	    for (j=1;j<=n-k+1;j++) {
	        a+=diff[j];
	        cur[j]+=a;
	    }
	    }
	//    cout<<"array cur:\n";
	//    for (j=1;j<=n-k+1;j++) cout<<cur[j]<<' ';
	//    cout<<endl;
	    b=0;
	    for (j=1;j<=m;j++) b+=cnt[j][i];
	    for (j=1;j<=n-k+1;j++) res=max(res,b+cur[j]);
	}
	cout<<res;
}