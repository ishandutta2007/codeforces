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
const int N=8e5+55;
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
int n,k,d,maxx[N*4],minn[N*4],pm[N*4],pi[N*4],s[N*4],a[N],b[N],c[N],mo[N],tong[N],st[N],pre[N],f[N],qm[N],qi[N],you,top;
void update(int u){
	maxx[u]=min(maxx[ls],maxx[rs]);
	minn[u]=min(minn[ls],minn[rs]);
	s[u]=min(s[ls],s[rs]);
}
void pushdown(int u,int l,int r){
	if(pm[u]!=2929810){
		maxx[ls]=pm[u]+l;
		maxx[rs]=pm[u]+mid+1;
		s[ls]=pm[u]+minn[ls];
		s[rs]=pm[u]+minn[rs];
		pm[ls]=pm[rs]=pm[u];
		pm[u]=2929810;
	}
	if(pi[u]!=1919810){
		minn[ls]=pi[u]+l;
		minn[rs]=pi[u]+mid+1;
		s[ls]=pi[u]+maxx[ls];
		s[rs]=pi[u]+maxx[rs];
		pi[ls]=pi[rs]=pi[u];
		pi[u]=1919810;
	}
}
void clear(int u,int l,int r,int x){
	if(l==r){
		s[u]=2e9;
		return ;
	}
	pushdown(u,l,r);
	if(x<=mid)clear(ls,l,mid,x);
	else clear(rs,mid+1,r,x);
	update(u);
}
void modify(int u,int l,int r,int L,int R,int x){ // maxx
	if(r<=you)return ;
	if(L<=l and R>=r and you<l){
		maxx[u]=x+l;
		s[u]=x+minn[u];
		pm[u]=x;
		return ;
	}
	pushdown(u,l,r);
	if(L<=mid)modify(ls,l,mid,L,R,x);
	if(R>mid)modify(rs,mid+1,r,L,R,x);
	update(u);
}
void change(int u,int l,int r,int L,int R,int x){ // minn
	if(r<=you)return ;
	if(L<=l and R>=r and you<l){
		minn[u]=-x+l;
		s[u]=-x+maxx[u];
		pi[u]=-x;
		return ;
	}
	pushdown(u,l,r);
	if(L<=mid)change(ls,l,mid,L,R,x);
	if(R>mid)change(rs,mid+1,r,L,R,x);
	update(u);
}
int ask(int u,int l,int r,int v){
	if(l==r){
		return l;
	}
	pushdown(u,l,r);
	if(s[ls]+v<=0 and you<mid)return ask(ls,l,mid,v);
	else return ask(rs,mid+1,r,v);
}
int main(){
//	freopen("data.in","r",stdin);
	n=read();k=read();d=read();
//	memset(maxx,10,sizeof(maxx));
//	memset(minn,10,sizeof(minn));
	for(int i=1;i<=n;i++)a[i]=b[i]=mo[i]=read();
	if(d==0){
		int qz=0;
		int maxx=0,l,r;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1])qz++;
			else qz=1;
			if(qz>maxx){
				l=i-qz+1;
				r=i;
				maxx=qz;
			}
		}
		cout<<l<<" "<<r<<endl;
		return 0;
	}
//	memset(s,10,sizeof(s));
//	memset(maxx,10,sizeof(maxx));
//	memset(minn,-10,sizeof(minn));
	for(int i=1;i<=n*4;i++)pm[i]=2929810,pi[i]=1919810;
	int top=n;
	sort(b+1,b+n+1);
	top=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)c[i]=lower_bound(b+1,b+top+1,a[i])-b,mo[i]=(a[i]%d+d)%d;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(tong[c[i]]){
			f[i]=max(f[i],tong[c[i]]);
		}
		tong[c[i]]=i;
		if(mo[i]==mo[i-1])pre[i]=pre[i-1];
		else{
			pre[i]=i;
			f[i]=i-1;
		}
	}
	for(int i=1;i<=n;i++){
		while(top and a[st[top]]<a[i])top--;
		qm[i]=st[top]+1;
		st[++top]=i;
	}
	top=0;
	for(int i=1;i<=n;i++){
		while(top and a[st[top]]>a[i])top--;
		qi[i]=st[top]+1;
		st[++top]=i;
	}
	int maxx=0,l,r;
	for(int i=1;i<=n;i++){
		for(int k=f[i-1]+1;k<=f[i];k++){
			clear(1,1,n,k);
		}
		if(i==9){
			new char;
		}
		you=f[i];
		modify(1,1,n,qm[i],i,a[i]/d);
		change(1,1,n,qi[i],i,a[i]/d);
		int val=ask(1,1,n,-i-k);
		if(maxx<i-val+1){
			maxx=i-val+1;
			l=val;
			r=i;
		}
	//	cout<<ask(1,1,n,-i-k)<<" "<<i<<endl;
	}
	cout<<l<<" "<<r;
	return 0;
}
/*
10 0 1
-1 1 2 4 5 7 8 10 11 13
*/