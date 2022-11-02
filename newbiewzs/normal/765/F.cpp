#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#include<math.h>
#include<unordered_map>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read(){
	char c=getchar();
	ll x=1,s=0;
	while(c<'0'||c>'9'){
	   if(c=='-')x=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
	   s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
const int N=3e5+5;
int n,m,a[N],l,r,ans[N],minn[N*4];
vi s[N];
vector<pii>q[N];
void build(int u,int l,int r){
	for(int i=l;i<=r;i++)s[u].pb(a[i]);
	sort(s[u].begin(),s[u].end());
	minn[u]=2e9+7;
	if(l==r)return ;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
int maxx=0,ne;
void modify(int u,int l,int r,int x){
	//if(x<=r){
		int tmp=2e9+7;
		int pre=upper_bound(s[u].begin(),s[u].end(),ne)-s[u].begin()-1;
		int prv=upper_bound(s[u].begin(),s[u].end(),ne)-s[u].begin();
		if(pre>=0)tmp=min(tmp,abs(ne-s[u][pre]));
		if(prv!=s[u].size())tmp=min(tmp,abs(ne-s[u][prv]));
		if(tmp>=maxx)return ;
	//}
	if(l==r){
		minn[u]=min(minn[u],abs(a[l]-ne));
	//	maxx=min(maxx,abs(a[l]-ne));
		maxx=min(maxx,minn[u]);
		return ;
	}
	if(x>mid)modify(rs,mid+1,r,x);
	maxx=min(maxx,minn[rs]);
	modify(ls,l,mid,x);
	minn[u]=min(minn[ls],minn[rs]);
}
int query(int u,int l,int r,int L,int R){
	if(L<=l and R>=r){
		return minn[u];
	}
	int maa=2e9+7;
	if(L<=mid)maa=min(maa,query(ls,l,mid,L,R));
	if(R>mid)maa=min(maa,query(rs,mid+1,r,L,R));
	return maa;
}
int main(){
//	freopen("pp.in","r",stdin);
//	freopen("ss.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	m=read();
	for(int i=1;i<=m;i++){
		l=read();r=read();
		q[r].pb(mp(l,i));
	}
	for(int i=2;i<=n;i++){
		maxx=2e9+7;ne=a[i];
		modify(1,1,n,i-1);
		for(int k=0;k<q[i].size();k++){
			ans[q[i][k].se]=query(1,1,n,q[i][k].fi,i-1);
		}
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}