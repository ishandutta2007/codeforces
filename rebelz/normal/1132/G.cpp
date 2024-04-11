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
	int lazy,maxa;
}t[3000000],t2[3000000];

int n,k,cnt;
vector<int> v[1000005];
int a[1000005],siz[1000005],dfn[1000005];

void pushdown(int id){
	if(t[id].lazy){
		t[id<<1].lazy+=t[id].lazy,t[id<<1].maxa+=t[id].lazy;
		t[id<<1|1].lazy+=t[id].lazy,t[id<<1|1].maxa+=t[id].lazy;
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr){
		t[id].lazy+=c,t[id].maxa+=c;
		return;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	t[id].maxa=max(t[id<<1].maxa,t[id<<1|1].maxa);
}

void build2(int id,int l,int r){
	t2[id].maxa=1<<30;
	if(l==r) return;
	int mid=(l+r)/2;
	build2(id<<1,l,mid);
	build2(id<<1|1,mid+1,r);
}

void change2(int id,int l,int r,int p,int c){
	if(l==p&&r==p) return (void)(t2[id].maxa=c);
	int mid=(l+r)/2;
	if(p<=mid) change2(id<<1,l,mid,p,c);
	else change2(id<<1|1,mid+1,r,p,c);
	t2[id].maxa=min(t2[id<<1].maxa,t2[id<<1|1].maxa);
}

int query2(int id,int l,int r,int ql,int qr){
	if(ql>qr) return 0;
	if(l==ql&&r==qr) return t2[id].maxa;
	int mid=(l+r)/2;
	if(qr<=mid) return query2(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query2(id<<1|1,mid+1,r,ql,qr);
	else return min(query2(id<<1,l,mid,ql,mid),query2(id<<1|1,mid+1,r,mid+1,qr));
}

void dfs(int u){
	siz[u]=1,dfn[u]=++cnt;
	for(int i=0;i<v[u].size();i++){
		dfs(v[u][i]);
		siz[u]+=siz[v[u][i]];
	}
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	build2(1,1,n);
	for(int i=n;i>=1;i--){
		int tmp=query2(1,1,n,a[i]+1,n);
		if(tmp<=n) v[tmp].push_back(i);
		change2(1,1,n,a[i],i);
	}
	for(int i=n;i>=1;i--) if(!dfn[i]) dfs(i);
	for(int i=1;i<=k;i++) change(1,1,n,dfn[i],dfn[i]+siz[i]-1,1);
	printf("%d ",t[1].maxa);
	for(int i=k+1;i<=n;i++){
		change(1,1,n,dfn[i],dfn[i]+siz[i]-1,1);
		change(1,1,n,dfn[i-k],dfn[i-k]+siz[i-k]-1,-1);
		printf("%d ",t[1].maxa);
	}
	printf("\n");
	return 0;
}