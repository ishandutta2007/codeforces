#include<bits/stdc++.h>
#define nosol puts("-1"),exit(0)
typedef long long ll;
int gi(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='?')return-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x;
}
bool eq(int a,int b){if(b==-1)return 1;return a==b;}
int n,D[310],L[310],Cnt[310],CNT[310],exist[310],maxdep[310];
int p[310];
int fir[610],dep[610],head[610],dis[10000010],nxt[10000010],w[10000010],id,cnt;
int S,T,numl[310],numr[310],chain[310][310],chlen[310];
void link(int a,int b,int c){
	//printf("%d %d %d\n",a,b,c);
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=0;
}
int edger[310],edgelr[310][310],edgelc[310][310][310];
bool BFS(){
	static int que[610],hd,tl;
	hd=tl=0;que[tl++]=S;memset(dep,0,sizeof dep);
	dep[S]=1;
	while(hd^tl){
		int x=que[hd++];
		for(int i=fir[x];i;i=nxt[i])
			if(w[i]&&!dep[dis[i]])dep[dis[i]]=dep[x]+1,que[tl++]=dis[i];
	}
	return dep[T];
}
int Dinic(int x,int maxflow){
	if(x==T)return maxflow;
	int ret=0;
	for(int&i=head[x];i;i=nxt[i])
		if(dep[dis[i]]==dep[x]+1&&w[i]){
			int d=Dinic(dis[i],std::min(w[i],maxflow-ret));
			w[i]-=d,w[i^1]+=d;ret+=d;if(ret==maxflow)break;
		}
	return ret;
}
std::vector<int>V[310][310];int Get(int i,int j){int r=V[i][j].back();V[i][j].pop_back();return r;}
int main(){
	n=gi();
	int maxl=0;
	for(int i=1;i<=n;++i){
		D[i]=gi(),L[i]=gi();
		if(~L[i]){
			if(~D[i])maxdep[L[i]]=std::max(maxdep[L[i]],D[i]);
			if(D[i]==0)++Cnt[L[i]];
			else exist[L[i]]=1;
		}else maxl=std::max(maxl,D[i]);
	}
	for(int i=1;i<=n;++i){
		CNT[i]=(Cnt[i]+i-1)/i;
		if(exist[i])CNT[i]=std::max(CNT[i],1);
	}
	bool FLG=0;
	for(int o=1;o<=n;++o){/////////////
		cnt=2;S=1,T=2;
		memset(fir,0,sizeof fir);id=1;
		int tot=0;
		bool flg=!CNT[o];
		if(flg)
			if(!FLG)FLG=1,CNT[o]=1;
			else continue;
		for(int i=1;i<=n;++i){
			int c=CNT[i]*i-Cnt[i];
			if(c)edger[i]=id+1,link(numr[i]=++cnt,T,c),tot+=c;
			else edger[i]=-1;
		}
		int sum=tot;
		for(int i=1;i<=n;++i){
			chlen[i]=std::max(o==i?maxl:0,maxdep[i]);
			sum+=chlen[i];
		}
		if(sum>n){if(flg)CNT[o]=0;continue;}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=chlen[i];++j)
				link(chain[i][j]=++cnt,T,1),++tot;
		}
		for(int i=1;i<=n;++i){
			memset(edgelr[i],-1,sizeof edgelr[i]);memset(edgelc[i],-1,sizeof edgelc[i]);
			if(D[i]==0&&~L[i])continue;
			link(S,numl[i]=++cnt,1);
			if(D[i]<=0)for(int j=1;j<=n;++j)if(numr[j]&&eq(j,L[i]))edgelr[i][j]=id+1,link(numl[i],numr[j],1);
			if(D[i]!=0){
				for(int j=1;j<=n;++j)
					if(eq(j,L[i]))
					for(int k=1;k<=chlen[j];++k)
						if(k==D[i]||D[i]==-1)edgelc[i][j][k]=id+1,link(numl[i],chain[j][k],1);
			}
		}
		while(BFS())memcpy(head,fir,sizeof head),tot-=Dinic(S,1e9);
		if(tot){if(flg)CNT[o]=0;continue;}
		for(int i=1;i<=n;++i)p[i]=-1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)if(~edgelr[i][j]&&!w[edgelr[i][j]])L[i]=j,D[i]=0;
			for(int j=1;j<=n;++j)
				for(int k=1;k<=chlen[j];++k)
					if(~edgelc[i][j][k]&&!w[edgelc[i][j][k]])L[i]=j,D[i]=k;
			if(~L[i]&&~D[i])V[D[i]][L[i]].push_back(i);
		}
		for(int i=1;i<=n;++i){
			if(!CNT[i])continue;
			static int seq[82];
			while(CNT[i]--){
				for(int j=1;j<=i;++j)seq[j]=Get(0,i);
				seq[0]=seq[i];for(int j=1;j<=i;++j)p[seq[j-1]]=seq[j];
			}
			for(int j=1;j<=chlen[i];++j)seq[j]=Get(j,i);
			for(int j=1;j<=chlen[i];++j)p[seq[j]]=seq[j-1];
			for(int j=1;j<=n;++j)if(p[j]==-1&&D[j]&&eq(i,L[j])&&chlen[i]>=D[j]-1)p[j]=seq[std::max(0,D[j]-1)];
		}
		for(int i=1;i<=n;++i)printf("%d ",~p[i]?p[i]:i);
		exit(0);
	}
	puts("-1");
	return 0;
}