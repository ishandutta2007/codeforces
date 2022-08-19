#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int st,ed,v,w;
	node(int ss=0,int ee=0,int vv=0,int ww=0):st(ss),ed(ee),v(vv),w(ww){}
}a[50005];

const int cys=1000000007,jkp=10000019;
int n,m,k,top,ttm=1;
int d[20][1005],pw[1005];
vector<int> occ[100005];

int mod(int x){return x>=cys?x-cys:x;}

void add(int pl,int x){
	for(int i=k;i>=a[x].w;i--) d[pl][i]=max(d[pl][i],d[pl][i-a[x].w]+a[x].v);
}

void solve(int id,int l,int r){
	if(l==r){
		top++;
		for(int i=1;i<=k;i++) d[top][i]=d[top-1][i];
		for(auto x:occ[id]) add(top,x);
		int ans=0;
		for(int i=1;i<=k;i++) ans=mod(ans+1ll*pw[i-1]*d[top][i]%cys);
		printf("%d\n",ans);
		top--;
		return;
	}
	int mid=(l+r)/2;
	top++;
	for(int i=1;i<=k;i++) d[top][i]=d[top-1][i];
	for(auto x:occ[id]) add(top,x);
	solve(id<<1,l,mid); solve(id<<1|1,mid+1,r);
	top--;
}

void ins(int id,int l,int r,int ql,int qr,int c){
	if(ql>qr) return;
	if(l==ql&&r==qr){
		occ[id].push_back(c);
		return;
	}
	int mid=(l+r)/2;
	if(qr<=mid) ins(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) ins(id<<1|1,mid+1,r,ql,qr,c);
	else ins(id<<1,l,mid,ql,mid,c),ins(id<<1|1,mid+1,r,mid+1,qr,c);
}

int main(){
	n=readint(); k=readint();
	pw[0]=1;
	for(int i=1;i<=k;i++) pw[i]=1ll*pw[i-1]*jkp%cys;
	int opt,x,y;
	for(int i=1;i<=n;i++){
		x=readint(); y=readint();
		a[i]=node(1,-1,x,y);
	}
	m=readint();
	for(int i=1;i<=m;i++){
		opt=readint();
		if(opt==1){
			x=readint(); y=readint();
			a[++n]=node(ttm,-1,x,y);
		}
		else if(opt==2) a[readint()].ed=ttm-1;
		else ttm++;
	}
	for(int i=1;i<=n;i++) if(a[i].ed<0) a[i].ed=ttm;
	for(int i=1;i<=n;i++) if(a[i].st<=ttm-1) ins(1,1,ttm-1,a[i].st,min(a[i].ed,ttm-1),i);
	solve(1,1,ttm-1);
	return 0;
}