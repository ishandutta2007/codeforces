#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,q,tot;
int f[300005],max1[300005],max2[300005],v[600005],nxt[600005],h[300005],d[300005];
bool vis[300005];

int getf(int v){if(v==f[v])return v;return f[v]=getf(f[v]);}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int k){
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]) continue;
		vis[v[p]]=true; dfs(v[p],k);
		if(max1[v[p]]+1>max1[u]) max2[u]=max1[u],max1[u]=max1[v[p]]+1;
		else if(max1[v[p]]+1>max2[u]) max2[u]=max1[v[p]]+1;
	}
	d[k]=max(d[k],max1[u]+max2[u]);
}

int main(){
	n=readint(); m=readint(); q=readint();
	for(int i=1;i<=n;i++) f[i]=i;
	int opt,x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		addedge(x,y);
		x=getf(x),y=getf(y);
		if(x==y) continue;
		f[x]=y;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(i,getf(i));
		}
	}
	for(int i=1;i<=q;i++){
		opt=readint(); x=readint();
		if(opt==1) printf("%d\n",d[getf(x)]);
		else{
			y=readint();
			x=getf(x),y=getf(y);
			if(x==y) continue;
			f[x]=y;
			d[y]=max(max(d[x],d[y]),(d[x]+1)/2+(d[y]+1)/2+1);
		}
	}
	return 0;
}