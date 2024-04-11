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
	int p,c,l;
	bool operator<(const node comp)const{return l<comp.c;}
}a[105];

const int inf=1<<30;
int n,d,ans,src,sink,tot=0,cnt=0;
int level[400005],q[400005],v[100005],c[100005],nxt[100005],rev[100005],h[100005],prime[200005];
bool flag[200005],vis[105];

void addedge(int x,int y,int z){
//	cout<<x<<' '<<y<<' '<<z<<endl;
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; rev[tot]=tot+1; h[x]=tot;
	v[++tot]=x; c[tot]=0; nxt[tot]=h[y]; rev[tot]=tot-1; h[y]=tot;
}

bool bfs(){
	memset(level,-1,sizeof(level));
	int front=0,rear=0;
	level[src]=0,q[rear++]=src;
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
	int res=0,flow;
	for(int p=h[u];p;p=nxt[p]){
		if(level[v[p]]==level[u]+1&&c[p]){
			flow=dfs(v[p],min(low,c[p]));
			res+=flow,c[p]-=flow,c[rev[p]]+=flow,low-=flow;
			if(low<=0) break;
		}
	}
	if(res==0) level[u]=-1;
	return res;
}

int dinic(){
	int maxflow=0;
	while(bfs()) maxflow+=dfs(src,inf);
//	cout<<maxflow<<endl;
	return maxflow;
}

void getprime(int g){
	flag[1]=true;
	for(int i=2;i<=g;i++){
		if(!flag[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=g;j++){
			flag[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}

int main(){
	getprime(200000);
	n=readint(); d=readint();
	src=0,sink=n+1;
	for(int i=1;i<=n;i++) a[i].p=readint(),a[i].c=readint(),a[i].l=readint();
	int l=1,r=n,mid,sum,maxa; bool fl;
	while(l<=r){
		memset(h,0,sizeof(h)); tot=sum=maxa=fl=0;
		mid=(l+r)/2;
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++) if(a[i].c==1&&a[i].l<=mid) maxa=max(maxa,a[i].p);
		sum=maxa;
		for(int i=1;i<=n;i++){
			if(a[i].l<=mid&&a[i].c>1){
				sum+=a[i].p,vis[i]=true;
				if(a[i].c%2) addedge(src,i,a[i].p);
				else addedge(i,sink,a[i].p);
			}
			else if(a[i].c==1&&a[i].l<=mid&&a[i].p==maxa&&!fl) fl=true,vis[i]=true,addedge(src,i,a[i].p);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&vis[i]&&vis[j]&&!flag[a[i].c+a[j].c])
					if(a[i].c%2) addedge(i,j,inf);
					else addedge(j,i,inf);
//		cout<<"TEST "<<mid<<' '<<d<<' ';
		if(sum-dinic()>=d) ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(!ans) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}