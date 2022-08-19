#include<bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k,tot,cnt;
ll dis[300005],v[600005],c[600005],id[600005],nxt[600005],h[300005],ans[300005],pre[300005];
bool vis[300005];
priority_queue<pii,vector<pii>,greater<pii> > q;

void addedge(int x,int y,int z,int i){
	v[++tot]=y; c[tot]=z; id[tot]=i; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; id[tot]=i; nxt[tot]=h[y]; h[y]=tot;
}

void dij(){
	memset(dis,0x3f,sizeof(dis));
	q.push(mp(0,1)); dis[1]=0;
	while(!q.empty()){
		int t=q.top().second; q.pop();
//		cout<<t<<endl;
		if(vis[t]) continue;
		if(t!=1) ans[++cnt]=pre[t];
		if(cnt==k) return;
		vis[t]=true;
		for(int p=h[t];p;p=nxt[p]){
			if(vis[v[p]]) continue;
			if(dis[t]+c[p]<dis[v[p]]){
				dis[v[p]]=dis[t]+c[p];
				pre[v[p]]=id[p];
				q.push(mp(dis[v[p]],v[p]));
			}
		}
	}
}

int main(){
	n=readint(); m=readint(); k=readint();
	int x,y,z;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint();
		addedge(x,y,z,i);
	}
	dij();
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) printf("%d ",ans[i]);
	return 0;
}