#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m,fir[210],dis[2010],nxt[2010],w[2010],id;
void link(int a,int b,int c){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=c;
}
int eA[1010],eB[1010],eC[1010],ans;
int nA[1010],nB[1010],nC[1010],nm,S,T;
int dep[210],head[210];
bool BFS(){
	static int que[210],hd,tl;
	memset(dep,0,sizeof dep);
	hd=tl=0;que[tl++]=S;dep[S]=1;
	while(hd^tl){
		int x=que[hd++];
		for(int i=fir[x];i;i=nxt[i])
			if(w[i]&&!dep[dis[i]])dep[dis[i]]=dep[x]+1,que[tl++]=dis[i];
	}
	return dep[T];
}
int Dinic(int x,int maxflow){
	if(x==T)return maxflow;
	int r=0;
	for(int&i=head[x];i;i=nxt[i])
		if(w[i]&&dep[dis[i]]==dep[x]+1){
			int d=Dinic(dis[i],std::min(maxflow-r,w[i]));
			w[i]-=d,w[i^1]+=d,r+=d;if(r==maxflow)break;
		}
	return r;
}
void get(std::vector<int>set){
	if(set.size()<=1)return;
	id=1;memset(fir,0,sizeof fir);
	for(int i=1;i<=m;++i)link(eA[i],eB[i],eC[i]);
	S=set[0],T=set[1];
	int cut=0;while(BFS())memcpy(head,fir,sizeof head),cut+=Dinic(S,1e9);
	ans+=cut,++nm;nA[nm]=S,nB[nm]=T,nC[nm]=cut;
	std::vector<int>L,R;
	for(int i:set)(dep[i]?L:R).push_back(i);
	get(L),get(R);
}
bool del[2010];
int bel[2010];
void dfs(int x,int fa=-1){for(int i=fir[x];i;i=nxt[i])if(dis[i]!=fa&&!del[i])bel[dis[i]]=bel[x],dfs(dis[i],x);}
void out(std::vector<int>set){
	if(set.size()==1){printf("%d ",set[0]);return;}
	bool inS[210];
	for(int i=1;i<=n;++i)inS[i]=0;
	for(int i:set)inS[i]=1;
	int p=0;
	for(int i=1;i<=nm;++i)if(inS[nA[i]]&&inS[nB[i]]&&nC[i]<nC[p])p=i;
	del[p<<1]=del[p<<1|1]=1;bel[nA[p]]=nA[p],bel[nB[p]]=nB[p];
	dfs(nA[p]),dfs(nB[p]);
	std::vector<int>L,R;
	for(int i:set)(bel[i]==nA[p]?L:R).push_back(i);
	out(L),out(R);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi();
	for(int i=1;i<=m;++i)eA[i]=gi(),eB[i]=gi(),eC[i]=gi();
	std::vector<int>S;for(int i=1;i<=n;++i)S.push_back(i);
	get(S);printf("%d\n",ans);
	memset(fir,0,sizeof fir);id=1;
	for(int i=1;i<=nm;++i)link(nA[i],nB[i],nC[i]);
	nC[0]=1e9,out(S);
	return 0;
}