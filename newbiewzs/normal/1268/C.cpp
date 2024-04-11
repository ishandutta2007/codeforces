#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=2e5+55;
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
int n,pos[N],a[N],summ[N*4],suma[N*4],sumb[N*4];
void add(int u,int l,int r,int x,int id){
	if(l==r){
		summ[u]++;
		suma[u]-=x;
		sumb[u]+=x;
		return ;
	}
	if(x<=mid)add(ls,l,mid,x,id);
	else add(rs,mid+1,r,x,id);
	summ[u]=summ[ls]+summ[rs];
	suma[u]=suma[ls]+suma[rs];
	sumb[u]=sumb[ls]+sumb[rs];
}
int query(int u,int l,int r,int L,int R){
	if(L<=l and R>=r){
		return summ[u];
	}
	int tmp=0;
	if(L<=mid)tmp=query(ls,l,mid,L,R);
	if(R>mid)tmp=tmp+query(rs,mid+1,r,L,R);
	return tmp; 
}
int ask(int u,int l,int r,int x){
	if(l==r)return l;
	if(summ[ls]>=x)return ask(ls,l,mid,x);
	else return ask(rs,mid+1,r,x-summ[ls]);
}
int querya(int u,int l,int r,int L,int R){
	if(L>R)return 0;
	if(L<=l and R>=r){
		return suma[u];
	}
	int tmp=0;
	if(L<=mid)tmp=querya(ls,l,mid,L,R);
	if(R>mid)tmp=tmp+querya(rs,mid+1,r,L,R);
	return tmp; 
}
int queryb(int u,int l,int r,int L,int R){
	if(L>R)return 0;
	if(L<=l and R>=r){
		return sumb[u];
	}
	int tmp=0;
	if(L<=mid)tmp=queryb(ls,l,mid,L,R);
	if(R>mid)tmp=tmp+queryb(rs,mid+1,r,L,R);
	return tmp; 
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),pos[a[i]]=i;
	int nx=0;
	for(int i=1;i<=n;i++){
		nx+=query(1,1,n,pos[i],n);add(1,1,n,pos[i],i);
		int wz=(i-1)/2+1;
		wz=ask(1,1,n,wz);
		int ans=nx;
		int zuo=queryb(1,1,n,1,wz-1);
		int gs=(i-1)/2;
		int tmp=wz*gs-(gs*(gs+1)/2)-zuo;
		ans+=tmp;tmp=0;
		int you=queryb(1,1,n,wz+1,n);
		gs=i-(i-1)/2-1;
		tmp=you-(wz*gs+(gs*(gs+1)/2));
		ans+=tmp;
		cout<<ans<<" ";
	}
	return 0;
}