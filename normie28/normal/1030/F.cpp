
// Problem : E. Magical Permutation
// Contest : Codeforces - Codeforces Round #558 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1163/E
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
#define maxn 800000
#define mod 1000000007
long long n,q,t1[maxn];
long long w[maxn],a[maxn],t2[maxn];
void build(int left,int right,int p)
{
	if(left==right)
	{
		t1[p]=w[left];
		t2[p]=w[left]*(left-a[left]);
		t2[p]%=mod;
		return;
	}
	int mid=(left+right)>>1;
	build(left,mid,p*2);
	build(mid+1,right,p*2+1);
	t1[p]=t1[p*2]+t1[p*2+1];
	t2[p]=t2[p*2]+t2[p*2+1];
	t2[p]%=mod;
}
void update1(int left,int right,int q,int p,long long c)
{	
	if(left>q||right<q)
	{
		return;
	}
	if(left==right)
	{
		t1[p]+=c;
//		t1[p]%=mod;
		return;
	}
	int mid=(left+right)>>1;
	update1(left,mid,q,p*2,c);
	update1(mid+1,right,q,p*2+1,c);
	t1[p]=t1[p*2]+t1[p*2+1];
//	t1[p]%=mod;
}
void update2(int left,int right,long long q,int p,long long c)
{
	if(left>q||right<q)
	{
		return;
	}
	if(left==right)
	{
		t2[p]+=c*(q-a[q]);
		t2[p]%=mod;
		return;
	}
	int mid=(left+right)>>1;
	update2(left,mid,q,p*2,c);
	update2(mid+1,right,q,p*2+1,c);
	t2[p]=t2[p*2]+t2[p*2+1];
	t2[p]%=mod;
}
long long query1(int left,int right,int ql,int qr,int p)
{
	if(left>=ql&&right<=qr)
	{
		return t1[p];
	}
	if(left>qr||right<ql)
	{
		return 0;
	}
	long long mid=(left+right)>>1;
	return query1(left,mid,ql,qr,p*2)+query1(mid+1,right,ql,qr,p*2+1);
}
long long query2(int left,int right,int ql,int qr,int p)
{
	if(left>=ql&&right<=qr)
	{
		return t2[p];
	}
	if(left>qr||right<ql)
	{
		return 0;
	}
	int mid=(left+right)>>1;
	return (query2(left,mid,ql,qr,p*2)+query2(mid+1,right,ql,qr,p*2+1))%mod;
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	build(1,n,1);
	while(q--)
	{
		long long x,y;
		scanf("%I64d%I64d",&x,&y);
		if(x<0)
		{
			x=-x;
			update1(1,n,x,1,y-w[x]);
			update2(1,n,x,1,y-w[x]);
			w[x]=y;
//			for(int i=1;i<=n;i++)
//			{
//				cout<<w[i]<<' ';
//			}
//			cout<<endl;
//			for(int i=1;i<=4*n;i++)
//			{
//				cout<<t1[i]<<' ';
//			}
//			cout<<endl;
		}
		else
		{
			long long l=1,r=n,res=0;
			while(l<=r)
			{
				long long mid=(l+r)>>1;
//				cout<<mid<<":"<<query1(1,n,x,mid,1)<<' '<<query1(1,n,mid+1,y,1)<<endl;
				if(query1(1,n,x,mid,1)<query1(1,n,mid+1,y,1))
				{
					l=mid+1;
				}
				else
				{
					res=mid;
					r=mid-1;
				}
			}
//			cout<<query1(1,n,1,n,1)<<endl;
//			cout<<query1(1,n,x,l-1,1)<<' '<<a[l]-l<<' '<<query2(1,n,x,l-1,1)<<' '<<query1(1,n,l+1,y,1)<<' '<<l-a[l]<<' '<<query2(1,n,l+1,y,1)<<endl;
			long long ans=(query1(1,n,x,res-1,1)%mod*(a[res]-res))%mod+query2(1,n,x,res-1,1)+(query1(1,n,res+1,y,1)%mod*(res-a[res]))%mod-query2(1,n,res+1,y,1);
			while(ans<0)ans+=mod;
			printf("%I64d\n",ans%mod);
		}
	}
	return 0;
}