
// Problem : C. Drazil Likes Heap
// Contest : Codeforces - Codeforces Round #631 (Div. 1) - Thanks, Denis aramis Shitov!
// URL : https://codeforces.com/contest/1329/problem/C
// Memory Limit : 256 MB
// Time Limit : 1500 ms
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
int arr[(1<<21)+5],pos[(1<<20)+5],sor[(1<<20)+5];
int n,m;
 
int get(int x)
{
	int l=2*x,r=2*x+1;
	if(arr[l]==0&&arr[r]==0) return x;
	if(arr[l]>arr[r])
		return get(l);
	else
		return get(r);
}
 
void del(int x)
{
	int l=2*x,r=2*x+1;
	if(arr[l]==0&&arr[r]==0)
	{
		arr[x]=0;
		return;
	}
	if(arr[l]>arr[r])
	{
		pos[arr[l]]=x;
		arr[x]=arr[l];
		del(l);
	}
	else
	{
		pos[arr[r]]=x;
		arr[x]=arr[r];
		del(r);
	}
}
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		int nn=(1<<n)-1,mm=(1<<m)-1;
		long long ans=0;
		for(int i=1;i<=nn;i++)
		{
			scanf("%d",&arr[i]);
			sor[i]=arr[i];
			ans+=arr[i];
			pos[arr[i]]=i;
		}
		for(int i=nn+1;i<=2*nn+2;i++)
			arr[i]=0;
		sort(sor+1,sor+nn+1); reverse(sor+1,sor+nn+1);
		vector<int> anss;
		for(int i=1;i<=nn;i++)
		{
			int x=get(pos[sor[i]]);
			//cout << sor[i] << " " << pos[sor[i]] << " " << get(pos[sor[i]]) << endl;
			if(x<=mm) continue;
			ans-=sor[i];
			anss.push_back(pos[sor[i]]);
			del(pos[sor[i]]);
		}
		printf("%lld\n",ans);
		for(int i:anss)
			printf("%d ",i);
		puts("");
	}
}