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
#define FILE_IN "ming.inp"
#define FILE_OUT "ming.out"
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
using namespace std;
int top,s[31000000];
struct ST
{
	int lc[31000000],rc[31000000],haha[31000000]; 
	int hhhh(int o,int l,int r,int lss,int rss)
	{
		if(!haha[o])return 0;
		////////
		if(lss<=l&&r<=rss)return haha[o];
		int ans=0,mid=(l+r)/2;
		if(lss<=mid)ans+=hhhh(lc[o],l,mid,lss,rss);
		if(rss>mid)ans+=hhhh(rc[o],mid+1,r,lss,rss);
		return ans;
	}
	void inse(int &o,int l,int r,int q,int num)
	{
		if(!o)o=s[top--];
		if(l==r){
			haha[o]+=num;
			if(!haha[o]){s[++top]=o;lc[o]=rc[o]=0;o=0;}
			return;
		}
		int mid=(l+r)/2;
		if(q<=mid)inse(lc[o],l,mid,q,num);
		else inse(rc[o],mid+1,r,q,num);
		haha[o]=haha[lc[o]]+haha[rc[o]];
		if(!haha[o]){s[++top]=o;lc[o]=rc[o]=0;o=0;}
	}
}T;
int n,m,root[500001];
void gggg(int x,int y,int k)
{
	for(;x<=n;x+=((x)&(-x)))T.inse(root[x],1,n,y,k);
}
int hhhh(int x,int l,int r)
{
	int ans=0;
	for(;x;x-=((x)&(-x)))ans+=T.hhhh(root[x],1,n,l,r);
	return ans;
}
int a[500001],b[500001],f[500001],i,flag,x,y,l,r;
int main()
{
    fio;
    cin>>n>>m;
	for(i=1;i<=3e7;i++)s[++top]=i;
	for(i=1;i<=n;i++) cin>>a[i],f[a[i]]=i;
	for(i=1;i<=n;i++) cin>>b[i],gggg(f[b[i]],i,+1);
	for(i=1;i<=m;i++)
	{
	    cin>>flag>>x>>y;
		if(flag==1){
		    cin>>l>>r;
			cout<<hhhh(y,l,r)-hhhh(x-1,l,r)<<endl;
		}
		else{
			gggg(f[b[x]],x,-1);gggg(f[b[x]],y,+1);
			gggg(f[b[y]],y,-1);gggg(f[b[y]],x,+1);
			swap(b[x],b[y]);	
		}
	}
}