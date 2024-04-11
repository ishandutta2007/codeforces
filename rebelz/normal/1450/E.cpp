#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot;
int v[4005],c[4005],nxt[4005],h[205],col[205],dis[205],cnt[205],ans[205],q[800005];
bool vis[205];

void addedge(int x,int y,int z){v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;}

bool dfs(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(col[v[p]]>=0){
			if(col[v[p]]!=(col[u]^1)) return false;
			continue;
		}
		col[v[p]]=col[u]^1;
		if(!dfs(v[p])) return false;
	}
	return true;
}

bool spfa(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	int front=0,rear=0;
	q[rear++]=s,dis[s]=0;
	while(front<rear){
		int t=q[front++];
		vis[t]=false;
		if(cnt[t]>=n) return false;
		else cnt[t]++;
		for(int p=h[t];p;p=nxt[p]){
			if(dis[v[p]]>dis[t]+c[p]){
				dis[v[p]]=dis[t]+c[p];
				if(!vis[v[p]]){
					vis[v[p]]=true;
					q[rear++]=v[p];
				}
			}
		}
	}
	return true;
}

int main(){
	n=readint(); m=readint();
	int x,y,z;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint();
		if(z==1) addedge(x,y,1),addedge(y,x,-1);
		else addedge(x,y,1),addedge(y,x,1);
	}
	memset(col,-1,sizeof(col));
	col[1]=0;
	if(!dfs(1)) return printf("NO\n"),0;
	int res=0;
	for(int i=1;i<=n;i++){
		if(!spfa(i)) return printf("NO\n"),0;
		bool fl=1;
		for(int j=1;j<=n;j++) if(dis[j]<0) fl=0;
		if(fl){
			int maxa=0;
			for(int j=1;j<=n;j++) chkmax(maxa,dis[j]);
			if(chkmax(res,maxa)){
				for(int j=1;j<=n;j++) ans[j]=dis[j];
			}
		}
	}
	printf("YES\n");
	printf("%d\n",res);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}