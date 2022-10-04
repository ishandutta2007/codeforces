#include <bits/stdc++.h>
using namespace std;
const int N=201010;
const int B=1<<18;
const int LG=18;
int cnt[N],hv[N],srt[N],ord[N],orde[N],up[N],rnk[N],anc[N][LG],clk,go[N][LG];
pair<int,int> tr[B<<1];
vector<int> adj[N];
vector<pair<int,int>> rs;
vector<int> tr2[B<<1];
void dfs0(int u){
	cnt[u]=1;hv[u]=-1;
	for(auto &x:adj[u]){
		rnk[x]=rnk[u]+1;
		dfs0(x);
		if(hv[u]==-1 || cnt[hv[u]] < cnt[x])hv[u]=x;
		cnt[u]+=cnt[x];
	}
}
void dfs1(int u,bool h=false){
	ord[u]=clk++;
	srt[ord[u]]=u;
	if(h)up[u]=up[anc[u][0]];
	else up[u]=u;
	
	if(hv[u] >= 0)dfs1(hv[u],true);
	for(auto &x:adj[u]){
		if(x==hv[u])continue;
		dfs1(x);
	}
	orde[u]=clk;
}
int Go(int u,int d){
	for(int i=LG;i--;)if(d&1<<i)u=anc[u][i];
	return u;
}
int lca(int u,int v){
	if(rnk[u]<rnk[v])swap(u,v);
	u=Go(u,rnk[u]-rnk[v]);
	if(u==v)return u;
	for(int i=LG;i--;)if(anc[u][i]!=anc[v][i])u=anc[u][i],v=anc[v][i];
	return anc[u][0];
}
void add(int l,int r,pair<int,int> v){
	for(l+=B,r+=B;l/2!=r/2;l/=2,r/=2){
		if(!(l&1))tr[l+1]=min(tr[l+1],v);
		if(r&1)tr[r-1]=min(tr[r-1],v);
	}
}
bool check(int l,int r,int s,int e){
	for(l+=B-1,r+=B;l/2!=r/2;l/=2,r/=2){
		if(!(l&1)){
			auto it=lower_bound(tr2[l+1].begin(),tr2[l+1].end(),s);
			if(it!=tr2[l+1].end() && *it<e)return true;
		}
		if(r&1){
			auto it=lower_bound(tr2[r-1].begin(),tr2[r-1].end(),s);
			if(it!=tr2[r-1].end() && *it<e)return true;
		}
	}
	return false;
}
int main(){
	int n;scanf("%d",&n);
	anc[0][0]=-1;
	for(int i=1;i<n;i++){
		int x;scanf("%d",&x);
		x--;anc[i][0]=x;
		adj[x].push_back(i);
	}
	dfs0(0);dfs1(0);
	for(int i=1;i<LG;i++)for(int j=0;j<n;j++){
		int a=anc[j][i-1];
		if(a==-1)anc[j][i]=-1;
		else anc[j][i]=anc[a][i-1];
	}
	for(int i=1;i<B+B;i++)tr[i].first=2012345678;
	
	int m;scanf("%d",&m);
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		u--;v--;
		rs.emplace_back(ord[u],ord[v]);
		int L=lca(u,v);
		pair<int,int> p={rnk[L],L};
		while(up[u]!=up[L]){
			int uu=up[u];
			add(ord[uu]-1,ord[u]+1,p);
			u=anc[uu][0];
		}
		add(ord[L]-1,ord[u]+1,p);
		while(up[v]!=up[L]){
			int vv=up[v];
			add(ord[vv]-1,ord[v]+1,p);
			v=anc[vv][0];
		}
		add(ord[L]-1,ord[v]+1,p);
	}
	for(int i=2;i<B+B;i++){
		tr[i]=min(tr[i],tr[i>>1]);
	}
	for(int i=0;i<n;i++){
		go[i][0]=tr[B+ord[i]].first==2012345678?i:tr[B+ord[i]].second;
	}
	for(int j=1;j<LG;j++)for(int i=0;i<n;i++){
		go[i][j]=go[go[i][j-1]][j-1];
	}
	
	sort(rs.begin(),rs.end());
	for(auto &x:rs){
		tr2[B+x.first].push_back(x.second);
	}
	for(int i=B-1;i;i--)merge(tr2[i<<1].begin(),tr2[i<<1].end(),tr2[i<<1|1].begin(),tr2[i<<1|1].end(),back_inserter(tr2[i]));
	
	int q;scanf("%d",&q);
	for(int tt=0;tt<q;tt++){
		int u,v;scanf("%d%d",&u,&v);u--;v--;
		int L=lca(u,v);
		if(L==u)swap(u,v);
		int x=u;
		for(int i=LG;i--;)x=go[x][i];
		if(rnk[x]>rnk[L]){
			puts("-1");continue;
		}
		x=v;
		for(int i=LG;i--;)x=go[x][i];
		if(rnk[x]>rnk[L]){
			puts("-1");continue;
		}
		
		int ans=0;
		for(int i=LG;i--;){
			if(rnk[go[u][i]]>rnk[L]){
				ans+=1<<i;
				u=go[u][i];
			}
		}
		if(v==L){
			printf("%d\n",ans+1);continue;
		}
		for(int i=LG;i--;){
			if(rnk[go[v][i]]>rnk[L]){
				ans+=1<<i;
				v=go[v][i];
			}
		}
		if(check(ord[u],orde[u],ord[v],orde[v]) || check(ord[v],orde[v],ord[u],orde[u])){
			ans--;
		}
		printf("%d\n",ans+2);
	}
}