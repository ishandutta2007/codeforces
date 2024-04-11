#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int ec[50010],et[50010];
struct edge{int t,w,i;};
std::unordered_map<int,int>col;
std::unordered_map<int,std::vector<edge>>G[50010];
std::vector<int>v[50010];
std::unordered_map<int,int>du[50010];
int C,ans,Path[50010],Edge[50010],len;bool vis[50010];
void dfs(int x,int i,int fa=-1){
	Path[++len]=x;vis[x]=1;int t=len;Edge[len]=0;vis[x]=1;
	for(edge o:G[i][x])
		if(o.i!=fa){
			Edge[len]=o.i;
			if(!vis[o.t])dfs(o.t,i,o.i);
		}
}
std::vector<int>out,res,Out;
int conf,ca[50010],cb[50010],co[50010],cat[50010],cbt[50010];
std::vector<int>cao[50010],cbo[50010],cdo[50010];
int stm[50010],tm[50010];
int tot,pos;
int numA[50010],numB[50010],cnt;
int fir[200010],dis[10000010],nxt[10000010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
std::vector<int>vec[50010];
int dfn[200010],low[200010],stk[200010],tp,SCC[200010],ins[200010];
void tarjan(int x){
	dfn[x]=low[x]=++dfn[0];stk[++tp]=x;ins[x]=tp;
	for(int i=fir[x];i;i=nxt[i])
		if(!dfn[dis[i]])tarjan(dis[i]),low[x]=std::min(low[x],low[dis[i]]);
		else if(ins[dis[i]])low[x]=std::min(low[x],dfn[dis[i]]);
	if(dfn[x]==low[x]){
		++SCC[0];
		while(ins[x])ins[stk[tp]]=0,SCC[stk[tp]]=SCC[0],--tp;
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=1;i<=m;++i){
		int a=gi(),b=gi(),c=gi(),t=gi();
		if(!col.count(c))col[c]=++C;c=col[c];
		G[c][a].push_back({b,t,i});
		G[c][b].push_back({a,t,i});
		v[c].push_back(a),v[c].push_back(b);
		++du[c][a],++du[c][b];
		et[i]=t,ec[i]=c;
	}
	for(int i=1;i<=C;++i)for(auto j:du[i])if(j.second>2)return puts("No"),0;
	for(int i=1;i<=C;++i){
		std::sort(v[i].begin(),v[i].end());
		v[i].erase(std::unique(v[i].begin(),v[i].end()),v[i].end());
		std::sort(v[i].begin(),v[i].end(),[&](int a,int b){return du[i][a]<du[i][b];});
		for(int x:v[i])vis[x]=0;
		for(int x:v[i]){
			if(vis[x])continue;
			len=0;dfs(x,i);
			int M[2]={0};
			for(int i=1;i<=len;++i)M[i&1]=std::max(M[i&1],et[Edge[i]]);
			if(!Edge[len]&&len==2)continue;
			ans=std::max(ans,std::min(M[0],M[1]));
			if(Edge[len]||len==2){
				if(Edge[len]&&(len&1))return puts("No"),0;
				if(Edge[len]){
					for(int j=(M[0]<M[1]?2:1);j<=len;j+=2)out.push_back(Edge[j]);
					for(int j=1;j<=len;++j)++stm[Path[j]];
				}
			}else{
				++conf;ca[conf]=Path[1],cb[conf]=Path[len];
				co[conf]=len&1;cat[conf]=M[0],cbt[conf]=M[1];
				for(int j=1;j<len;++j)((j&1)?cao:cbo)[conf].push_back(Edge[j]);
				for(int j=2;j<len;++j)cdo[conf].push_back(Path[j]);
			}
		}
	}
	for(int i=1;i<=n;++i)if(stm[i]>1)return puts("No"),0;
	for(int i=1;i<=n;++i)numA[i]=++cnt,numB[i]=++cnt;
	int l=ans,r=1000000001,mid;
	while(l<r){
		mid=(l+r)>>1;
		res.clear();
		for(int i=1;i<=n;++i)vec[i].clear(),tm[i]=stm[i];
		for(int i=1;i<=conf;++i){
			int c=(cat[i]<=mid)+(cbt[i]<=mid);
			for(int x:cdo[i])++tm[x];
			if(c==2){
				if(co[i])vec[ca[i]].push_back(i),vec[cb[i]].push_back(i);
				else for(int x:cbo[i])res.push_back(x);
			}else if(co[i]){
				++tm[cat[i]<=mid?cb[i]:ca[i]];
				for(int x:(cat[i]<=mid?cbo:cao)[i])res.push_back(x);
			}else if(cat[i]<=cbt[i])for(int x:cbo[i])res.push_back(x);
			else{
				++tm[ca[i]],++tm[cb[i]];
				for(int x:cao[i])res.push_back(x);
			}
		}
		for(int i=1;i<=n;++i)if(tm[i]>1){l=mid+1;goto gg;}
		cnt=2*n;
		memset(fir,0,sizeof fir);id=0;
		for(int i=1;i<=n;++i){
			static int ID[50010],nowA[50010],nowB[50010],o,newD[50010];
			o=0;
			for(int j:vec[i]){
				int a=numA[j],b=numB[j];
				if(i==cb[j])std::swap(a,b);
				ID[++o]=j;nowA[o]=a,nowB[o]=b;
			}
			if(tm[i])for(int j=1;j<=o;++j)link(nowA[j],nowB[j]);
			else{
				for(int j=2;j<=o;++j)newD[j]=++cnt;
				for(int j=2;j<o;++j)link(newD[j],newD[j+1]);
				for(int j=2;j<=o;++j)link(nowA[j-1],newD[j]);
				for(int j=2;j<=o;++j)link(newD[j],nowB[j]);
				for(int j=1;j<o;++j)newD[j]=++cnt;
				for(int j=1;j<o-1;++j)link(newD[j+1],newD[j]);
				for(int j=1;j<o;++j)link(nowA[j+1],newD[j]);
				for(int j=1;j<o;++j)link(newD[j],nowB[j]);
			}
		}
		memset(dfn,0,sizeof dfn);
		memset(SCC,0,sizeof SCC);
		for(int i=1;i<=cnt;++i)if(!dfn[i])tarjan(i);
		for(int i=1;i<=conf;++i){
			int c=(cat[i]<=mid)+(cbt[i]<=mid);if(c<2||!co[i])continue;
			if(SCC[numA[i]]==SCC[numB[i]]){l=mid+1;goto gg;}
			if(SCC[numA[i]]<SCC[numB[i]])for(int x:cao[i])res.push_back(x);
			else for(int x:cbo[i])res.push_back(x);
		}
		gg:
		if(l!=mid+1){
			r=mid;
			Out=res;
		}
	}
	if(r==1000000001)return puts("No"),0;
	puts("Yes");
	printf("%d %d\n",l,out.size()+Out.size());
	for(int i:out)printf("%d ",i);for(int i:Out)printf("%d ",i);
	return 0;
}