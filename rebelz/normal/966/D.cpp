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

int n,m,tot,ans,vcnt,ecnt;
int v[600005],nxt[600005],h[300005],dis[300005],q[300005],fr[300005];
bool vis[300005],lab[300005],tag[300005];
vector<int> res;
map<int,int> c[300005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot; c[x][y]=1;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot; c[y][x]=1;
}

int bfs(){
	memset(dis,0x3f,sizeof(dis));
	int front=0,rear=0;
	q[rear++]=1,dis[1]=0;
	while(front<rear){
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p])
			if(chkmin(dis[v[p]],dis[t]+1))
				fr[v[p]]=t,q[rear++]=v[p];
	}
	return dis[n];
}

void dfs(int u){
	vcnt++;
	for(int p=h[u];p;p=nxt[p]){
		if(!tag[v[p]]) continue;
		ecnt++;
		if(vis[v[p]]) continue;
		vis[v[p]]=1;
		dfs(v[p]);
	}
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) addedge(readint(),readint());
	ans=bfs();
	if(ans!=0x3f3f3f3f){
		for(int i=n;i!=1;i=fr[i]) res.pb(i);
		res.pb(1);
		reverse(res.begin(),res.end());
	}
	for(int p=h[1];p;p=nxt[p]) tag[v[p]]=1;
	for(int p=h[1];p;p=nxt[p]){
		for(int q=h[v[p]];q;q=nxt[q]){
			if(v[q]!=1&&!tag[v[q]]){
				if(chkmin(ans,4)){
					res.clear();
					res.pb(1),res.pb(v[p]),res.pb(v[q]),res.pb(1),res.pb(n);
				}
			}
		}
	}
	for(int p=h[1];p;p=nxt[p]){
		if(vis[v[p]]) continue;
		vis[v[p]]=1,vcnt=ecnt=0;
		dfs(v[p]);
		ecnt/=2;
		if(ecnt!=1ll*vcnt*(vcnt-1)/2&&ans>5){
			for(int p1=h[v[p]];p1;p1=nxt[p1]){
				if(v[p1]==1) continue;
				for(int p2=nxt[p1];p2;p2=nxt[p2]){
					if(v[p2]==1) continue;
					if(!c[v[p1]].count(v[p2])){
						if(chkmin(ans,5)){
							res.clear();
							res.pb(1),res.pb(v[p1]),res.pb(v[p]),res.pb(v[p2]),res.pb(v[p1]),res.pb(n);
							break;
						}
					}
				}
				if(ans<=5) break;
			}
			if(ans<=5) break;
			for(int p1=h[v[p]];p1;p1=nxt[p1]) if(v[p1]!=1) lab[v[p1]]=1;
			for(int p1=h[v[p]];p1;p1=nxt[p1]){
				if(v[p1]==1) continue;
				for(int p2=h[v[p1]];p2;p2=nxt[p2]){
					if(v[p2]==1||v[p2]==v[p]) continue;
					if(!lab[v[p2]]){
						if(chkmin(ans,5)){
							res.clear();
							res.pb(1),res.pb(v[p]),res.pb(v[p1]),res.pb(v[p2]),res.pb(v[p]),res.pb(n);
							break;
						}
					}
				}
				if(ans<=5) break;
			}
		}
	}
	if(ans==0x3f3f3f3f) printf("-1\n");
	else{
		printf("%d\n",ans);
		for(auto r:res) printf("%d ",r);
		printf("\n");
	}
	return 0;
}