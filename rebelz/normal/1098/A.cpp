#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot;
ll ans;
int v[200005],nxt[200005],h[100005];
ll s[100005],mina[100005],a[100005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	mina[u]=1ll<<60;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		if(s[v[p]]>=0) mina[u]=min(mina[u],s[v[p]]);
		mina[u]=min(mina[u],mina[v[p]]);
	}
}

void dfs1(int u,int fa){
	if(s[u]==-1){
		if(s[fa]>mina[u]){
			printf("-1\n");
			exit(0);
		}
		if(mina[u]==1ll<<60) a[u]=0;
		else a[u]=mina[u]-s[fa],s[u]=mina[u];
	}
	else if(u!=1){
		if(s[fa]>s[u]){
			printf("-1\n");
			exit(0);
		}
		a[u]=s[u]-s[fa];
	}
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs1(v[p],u);
	}
}

int main(){
	n=readint();
	for(int i=2;i<=n;i++) addedge(readint(),i);
	for(int i=1;i<=n;i++) s[i]=readint();
	dfs(1,-1);
	a[1]=s[1];
	dfs1(1,-1);
	for(int i=1;i<=n;i++) ans+=a[i];
	cout<<ans<<endl;
	return 0;
}