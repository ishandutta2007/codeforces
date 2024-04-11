#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,q,blo;
int lf[505],rg[505],bl[100005],a[100005],b[100005],tag[505],vis[505];

void init(){
	blo=sqrt(n);
	for(int i=1;i<=n;i+=blo) lf[++m]=i,rg[m]=min(n,i+blo-1);
	for(int i=1;i<=m;i++) for(int j=lf[i];j<=rg[i];j++) bl[j]=i;
	for(int i=1;i<=n;i++){
		if(bl[a[i]]!=bl[i]) b[i]=a[i];
		else b[i]=b[a[i]];
	}
}

void change(int l,int r,int x){
	int lb=bl[l],rb=bl[r];
	if(lb==rb){
		for(int i=l;i<=r;i++) a[i]=max(a[i]-x,tag[lb]);
		for(int i=lf[lb];i<=rg[lb];i++){
			if(bl[max(a[i]-tag[lb],0)]!=bl[i]) b[i]=max(a[i]-tag[lb],0);
			else b[i]=b[max(a[i]-tag[lb],0)];
		}
		return;
	}
	for(int i=l;i<=rg[lb];i++) a[i]=max(a[i]-x,tag[lb]);
	for(int i=lf[rb];i<=r;i++) a[i]=max(a[i]-x,tag[rb]);
	for(int i=lf[lb];i<=rg[lb];i++){
		if(bl[max(a[i]-tag[lb],0)]!=bl[i]) b[i]=max(a[i]-tag[lb],0);
		else b[i]=b[max(a[i]-tag[lb],0)];
	}
	for(int i=lf[rb];i<=rg[rb];i++){
		if(bl[max(a[i]-tag[rb],0)]!=bl[i]) b[i]=max(a[i]-tag[rb],0);
		else b[i]=b[max(a[i]-tag[rb],0)];
	}
	for(int i=lb+1;i<=rb-1;i++){
		tag[i]+=x;
		chkmin(tag[i],n);
		if(tag[i]<=blo){
			for(int j=lf[i];j<=rg[i];j++){
				if(bl[max(a[j]-tag[i],0)]!=bl[j]) b[j]=max(a[j]-tag[i],0);
				else b[j]=b[max(a[j]-tag[i],0)];
			}
		}
		else vis[i]=1;
	}
}

int query(int x,int y){
	int lstx=x,lsty=y;
	while(x!=y){
		if(x<y) swap(x,y),swap(lstx,lsty);
		if(vis[bl[x]]) lstx=x,x=max(a[x]-tag[bl[x]],0);
		else lstx=x,x=b[x];
	}
	x=lstx,y=lsty;
	while(x!=y){
		if(x<y) swap(x,y);
		x=max(a[x]-tag[bl[x]],0);
	}
	return x;
}

int main(){
	n=readint()-1; q=readint();
	for(int i=1;i<=n;i++) a[i]=readint()-1;
	init();
	int opt,l,r,x;
	while(q--){
		opt=readint();
		if(opt==1){
			l=readint()-1; r=readint()-1; x=readint();
			change(l,r,x);
		}
		else{
			l=readint()-1; r=readint()-1;
			printf("%d\n",query(l,r)+1);
		}
	}
	return 0;
}