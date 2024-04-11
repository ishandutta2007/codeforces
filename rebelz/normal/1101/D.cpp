#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot,num,ans;
int a[200005],v[1000005],nxt[1000005],h[200005],h2[200005];
int max1[200005],max2[200005],prime[200005];
bool flag[200005],vis[200005],nop[200005];
vector<int> d[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void addedge2(int x,int y){
//	cout<<"TEST "<<x<<' '<<y<<endl;
	v[++tot]=y; nxt[tot]=h2[x]; h2[x]=tot;
	v[++tot]=x; nxt[tot]=h2[y]; h2[y]=tot;
}

void dfs(int u,int fa){
	for(int p=h2[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		vis[v[p]]=true;
		dfs(v[p],u);
		if(max1[v[p]]+1>max1[u]) max2[u]=max1[u],max1[u]=max1[v[p]]+1;
		else if(max1[v[p]]+1>max2[u]) max2[u]=max1[v[p]]+1;
	}
	ans=max(ans,max1[u]+max2[u]+1);
}

void getprime(int k){
	nop[1]=true;
	for(int i=2;i<=k;i++){
		if(!nop[i]) prime[++num]=i;
		for(int j=1;j<=num&&i*prime[j]<=k;j++){
			nop[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}

int main(){
	getprime(200000);
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	bool fl=false;
	for(int i=1;i<=n;i++){
		if(a[i]!=1) fl=true;
		for(int j=1;j<=num&&prime[j]<=sqrt(a[i]);j++){
			if(a[i]%prime[j]==0){
				d[prime[j]].push_back(i);
				while(a[i]%prime[j]==0) a[i]/=prime[j];
			}
		}
		if(a[i]>1) d[a[i]].push_back(i);
	}
	if(!fl) return printf("0\n"),0;
	int x,y;
	for(int i=1;i<=n-1;i++){
		x=readint(); y=readint();
		addedge(x,y);
	}
	for(int i=1;i<=num;i++){
		int l=prime[i];
		for(int j=0;j<d[l].size();j++) h2[d[l][j]]=max1[d[l][j]]=max2[d[l][j]]=0,vis[d[l][j]]=false;
		tot=2*n;
		for(int j=0;j<d[l].size();j++){
			for(int p=h[d[l][j]];p;p=nxt[p]) if(flag[v[p]]) addedge2(d[l][j],v[p]);
			flag[d[l][j]]=true;
		}
		for(int j=0;j<d[l].size();j++){
			if(!vis[d[l][j]]){
				vis[d[l][j]]=true;
				dfs(d[l][j],-1);
			}
		}
		for(int j=0;j<d[l].size();j++) flag[d[l][j]]=false;
	}
	cout<<ans<<endl;
	return 0;
}