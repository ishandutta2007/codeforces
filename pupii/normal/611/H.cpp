#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int mian[]={0,1,10,100,1000,10000,100000};
int n,count[7],N,c[7][7],tr[7][7],pruf[7];
int fir[30],dep[30],head[30],dis[10000],nxt[10000],w[10000],cnt,S,T,id,edge[7][7];
void link(int a,int b,int c){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=0;
}
bool BFS(){
	static int que[30],hd,tl;
	hd=tl=0;que[tl++]=S;
	memset(dep,0,sizeof dep);dep[S]=1;
	while(hd^tl){
		int x=que[hd++];
		for(int i=fir[x];i;i=nxt[i])
			if(!dep[dis[i]]&&w[i])
				dep[dis[i]]=dep[x]+1,que[tl++]=dis[i];
	}
	return dep[T];
}
int Dinic(int x,int maxflow){
	if(x==T)return maxflow;
	int ret=0;
	for(int&i=head[x];i;i=nxt[i])
		if(dep[dis[i]]==dep[x]+1&&w[i]){
			int d=Dinic(dis[i],std::min(maxflow-ret,w[i]));
			w[i]-=d,w[i^1]+=d,ret+=d;
			if(ret==maxflow)break;
		}
	return ret;
}
void dfs(int x){
	if(x>N-2){
		static int deg[7];
		for(int i=1;i<=N;++i)deg[i]=1;
		for(int i=1;i<=N-2;++i)++deg[pruf[i]];
		memset(tr,0,sizeof tr);
		std::priority_queue<int,std::vector<int>,std::greater<int>>que;
		for(int i=1;i<=N;++i)if(deg[i]==1)que.push(i);
		for(int i=1;i<=N-2;++i){
			int a=que.top(),b=pruf[i];
			que.pop();
			tr[a][b]=tr[b][a]=1;
			if(--deg[b]==1)que.push(b);
		}
		tr[N][que.top()]=tr[que.top()][N]=1;
		S=N+1,T=N+2;cnt=N+2;
		memset(fir,0,sizeof fir);id=1;
		for(int i=1;i<=N;++i)
			for(int j=i;j<=N;++j){
				if(tr[i][j]&&!c[i][j])return;
				if(c[i][j]-tr[i][j]){
					if(i==j)edge[i][j]=id+2,link(i,T,c[i][j]-tr[i][j]);
					else{
						link(++cnt,T,c[i][j]-tr[i][j]);
						edge[i][j]=id+2,link(i,cnt,1e6);
						edge[j][i]=id+2,link(j,cnt,1e6);
					}
				}else edge[i][j]=edge[j][i]=-1;
			}
		int ans=n-N;
		for(int i=1;i<=N;++i)link(S,i,count[i]-1);
		while(BFS())memcpy(head,fir,sizeof head),ans-=Dinic(S,1e9);
		if(!ans){
			for(int i=1;i<=N;++i)
				for(int j=i+1;j<=N;++j)
					if(tr[i][j])printf("%d %d\n",mian[i],mian[j]);
			for(int i=1;i<=N;++i){
				int begin=mian[i];
				for(int j=1;j<=N;++j)
					if(~edge[i][j]){
						while(w[edge[i][j]]--)printf("%d %d\n",++begin,mian[j]);
					}
			}
			exit(0);
		}
		return;
	}
	for(int i=1;i<=N;++i)pruf[x]=i,dfs(x+1);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();
	if(n>=1)count[++N]=std::min(9,n);
	if(n>=10)count[++N]=std::min(99,n)-9;
	if(n>=100)count[++N]=std::min(999,n)-99;
	if(n>=1000)count[++N]=std::min(9999,n)-999;
	if(n>=10000)count[++N]=std::min(99999,n)-9999;
	if(n>=100000)count[++N]=n-99999;
	if(n<=9){for(int i=2;i<=n;++i)printf("1 %d\n",i);return 0;}
	for(int i=1;i<n;++i){
		static char a[10],b[10];
		scanf("%s",a+1);scanf("%s",b+1);
		int A=strlen(a+1),B=strlen(b+1);
		++c[A][B];if(A^B)++c[B][A];
	}
	dfs(1);puts("-1");
	return 0;
}