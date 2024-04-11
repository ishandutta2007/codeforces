#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int inf=1<<30;
int n,m,tot=0,src,sink,num;
int level[30005],q[30005],h[30005],v[60005],nxt[60005],c[60005],rev[60005],prime[30005],p[30005];
int a[30005],cnt[105][105],t[105][105],k[105],sum[105];
bool fl[40005];

void getprime(int g){
	fl[1]=true;
	for(int i=2;i<=g;i++){
		if(!fl[i]) prime[++num]=i;
		for(int j=1;j<=tot&&i*prime[j]<=g;j++){
			fl[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=0; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
}

bool bfs(){
	memset(level,-1,sizeof(level));
	int front=0,rear=0;
	q[rear++]=src; level[src]=0;
	while(front<rear){
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p]){
			if(c[p]&&level[v[p]]<0){
				level[v[p]]=level[t]+1;
				q[rear++]=v[p];
			}
		}
		if(level[sink]>0) return true;
	}
	return false;
}

int dfs(int u,int low){
	if(u==sink) return low;
	int res=0;
	for(int p=h[u];p;p=nxt[p]){
		if(c[p]&&level[v[p]]==level[u]+1){
			int flow=dfs(v[p],min(c[p],low));
			res+=flow,low-=flow,c[p]-=flow,c[rev[p]]+=flow;
		}
	}
	if(res==0) level[u]=-1;
	return res;
}

int main(){
	getprime(40000);
	n=readint(); m=readint();
	for(int i=1;i<=n;i++){
		a[i]=readint();
		for(int j=1;j<=num&&prime[j]<=sqrt(a[i]);j++){
			if(a[i]%prime[j]==0) t[i][++k[i]]=prime[j];
			while(a[i]%prime[j]==0) a[i]/=prime[j],cnt[i][k[i]]++;
		}
		if(a[i]>1){
			if(a[i]<=40000) t[i][++k[i]]=a[i],cnt[i][k[i]]++;
			else p[i]=a[i],t[i][++k[i]]=-1,cnt[i][k[i]]++;
		}
	}
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+k[i]+1;
	src=0,sink=sum[n]+1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			addedge(src,sum[i-1]+1,inf);
			for(int j=1;j<=k[i];j++) addedge(sum[i-1]+1,sum[i-1]+1+j,cnt[i][j]);
		}
		else{
			addedge(sum[i-1]+1,sink,inf);
			for(int j=1;j<=k[i];j++) addedge(sum[i-1]+1+j,sum[i-1]+1,cnt[i][j]);
		}
	}
	int x,y;
	while(m--){
		x=readint(); y=readint();
		if(x%2==0) swap(x,y);
		for(int i=1;i<=k[x];i++){
			for(int j=1;j<=k[y];j++){
				if(t[x][i]==t[y][j]&&t[x][i]>0) addedge(sum[x-1]+1+i,sum[y-1]+1+j,inf);
				else if(t[x][i]==t[y][j]&&p[x]==p[y]) addedge(sum[x-1]+1+i,sum[y-1]+1+j,inf);
			}
		}
	}
	int ans=0;
	while(bfs()) ans+=dfs(src,inf);
	printf("%d\n",ans);
	return 0;
}