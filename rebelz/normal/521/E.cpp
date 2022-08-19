#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot,ccnt,ncnt,scnt;
int siz[200005],v[400005],nxt[400005],id[400005],h[200005],rt[200005],col[200005],dfn[200005],low[200005],x[200005],y[200005],db[200005];
bool ins[200005],vis[200005],lab[200005],cir[200005];
stack<int> s;
vector<int> ans[5];

void addedge(int x,int y,int z){
	v[++tot]=y; nxt[tot]=h[x]; id[tot]=z; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; id[tot]=z; h[y]=tot;
}

void tarjan(int u,int fa){
	dfn[u]=low[u]=++ncnt;
	s.push(u); ins[u]=true;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		if(!dfn[v[p]]){
			tarjan(v[p],u);
			chkmin(low[u],low[v[p]]);
			if(low[v[p]]>=dfn[u]){
				scnt++;
				siz[scnt]++;
				while(!s.empty()){
					int t=s.top(); s.pop();
					ins[t]=false;
					siz[scnt]++,col[t]=scnt;
					if(t==v[p]) break;
				}
				rt[scnt]=u;
			}
		}
		else if(ins[v[p]]) chkmin(low[u],dfn[v[p]]);
	}
}

bool dfs1(int u,int fa,int rs,int co){
	if(u==rs&&vis[u]) return true;
	if(vis[u]) return false;
	vis[u]=true;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		if(col[v[p]]!=co&&rt[co]!=v[p]) continue;
		if(dfs1(v[p],u,rs,co)){
			cir[u]=1;
			lab[id[p]]=1;
			return true;
		}
	}
	return false;
}

int dfs2(int u,int fa,int co){
	vis[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		if(lab[id[p]]) continue;
		if(col[v[p]]!=co&&rt[co]!=v[p]) continue;
		if(vis[v[p]]) continue;
		if(cir[v[p]]){
			ans[3].push_back(u);
			return v[p];
		}
		else{
			int tmp=dfs2(v[p],u,co);
			if(tmp) ans[3].push_back(u);
			if(tmp) return tmp;
		}
	}
	return 0;
}

void getans(int u,int fa,int ed,int ct,int co){
	if(u==ed){
		ans[ct].push_back(ed);
		return;
	}
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		if(col[v[p]]!=co&&rt[co]!=v[p]) continue;
		if(!lab[id[p]]) continue;
		ans[ct].push_back(u);
		getans(v[p],u,ed,ct,co);
		ct++;
	}
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++){
		x[i]=readint(); y[i]=readint();
		addedge(x[i],y[i],i);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,-1),col[i]=++scnt;
	for(int i=1;i<=m;i++){
		if(col[x[i]]==col[y[i]]) db[col[x[i]]]++;
		else if(rt[col[x[i]]]==y[i]) db[col[x[i]]]++;
		else if(rt[col[y[i]]]==x[i]) db[col[y[i]]]++;
	}
	for(int i=1;i<=scnt;i++){
		if(db[i]>siz[i]){
			dfs1(rt[i],-1,rt[i],i);
			for(int j=1;j<=n;j++){
				if((col[j]==i||rt[i]==j)&&cir[j]){
					int cnt=0;
					for(int p=h[j];p;p=nxt[p]) if(col[v[p]]==i||rt[i]==v[p]) cnt++;
					if(cnt<=2) continue;
					printf("YES\n");
					memset(vis,0,sizeof(vis));
					int tmp=dfs2(j,-1,i);
					reverse(ans[3].begin(),ans[3].end());
					ans[3].push_back(tmp);
					getans(j,-1,tmp,1,i);
					for(int k=1;k<=3;k++){
						printf("%d ",ans[k].size());
						for(auto x:ans[k]) printf("%d ",x);
						printf("\n");
					}
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}