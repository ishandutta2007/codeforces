#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int fir[100010],nxt[200010],dis[200010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int dist[100010],lst[100010];
il vd BFS(int S){
	static bool vis[100010];
	static int que[100010];
	int hd=0,tl=0;
	memset(vis,0,sizeof vis);
	vis[S]=1;que[tl++]=S;lst[S]=0;
	while(hd^tl){
		int x=que[hd];
		for(int i=fir[x];i;i=nxt[i])
			if(!vis[dis[i]])vis[dis[i]]=1,que[tl++]=dis[i],dist[dis[i]]=dist[x]+1,lst[dis[i]]=x;
		++hd;
	}
}
int s[100010],tot,f[100010],w[100010],st1[17][100010],st2[17][100010],lg[100010],tp[100010],dst[100010];
il vd dfs(int x,int A=-1,int B=-1){
	for(int i=fir[x];i;i=nxt[i]){
		if(dis[i]==A||dis[i]==B)continue;
		tp[dis[i]]=tp[x];
		dst[dis[i]]=dst[x]+1;
		dfs(dis[i],x);
		f[x]=std::max(f[x],f[dis[i]]+1);
	}
}
il int query(int st[][100010],int l,int r){
	if(l>r)return -1e9;
	return std::max(st[lg[r-l+1]][l],st[lg[r-l+1]][r-(1<<lg[r-l+1])+1]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("418d.in","r",stdin);
	freopen("418d.out","w",stdout);
#endif
	int n=gi(),a,b,A=1,B=1;
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	BFS(1);for(int i=1;i<=n;++i)if(dist[i]>dist[A])A=i;
	BFS(A);for(int i=1;i<=n;++i)if(dist[i]>dist[B])B=i;
	for(int i=B;i;i=lst[i])s[++tot]=i;
	for(int i=1;i<=tot;++i)tp[s[i]]=i,dfs(s[i],s[i-1],s[i+1]),w[i]=f[s[i]],st1[0][i]=f[s[i]]+i,st2[0][i]=f[s[i]]-i;
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=lg[tot];++i)
		for(int j=1;j+(1<<i)-1<=tot;++j){
			st1[i][j]=std::max(st1[i-1][j],st1[i-1][j+(1<<i-1)]);
			st2[i][j]=std::max(st2[i-1][j],st2[i-1][j+(1<<i-1)]);
		}
	int m=gi(),ans,mid;
	while(m--){
		a=gi(),b=gi();
		if(tp[a]>tp[b])std::swap(a,b);
		mid=std::min(tp[b],std::max(tp[a],(dst[b]-dst[a]+tp[b]-tp[a])/2+tp[a]));
		int len=dst[a]+dst[b]+tp[b]-tp[a];
		if(tp[a]!=tp[b]){
			ans=std::max(std::min(dst[a]+tp[a]-1,dst[b]+tp[b]-1),std::min(dst[a]+tot-tp[a],dst[b]+tot-tp[b]));
			if(dst[a]*2<len&&dst[b]*2<len){
				ans=std::max(ans,query(st1,tp[a]+1,mid)-tp[a]+dst[a]);
				if(mid!=tp[b])ans=std::max(ans,query(st2,mid+1,tp[b]-1)+tp[b]+dst[b]);
			}
			else{
				if(mid==tp[a])ans=std::max(ans,std::max((len+1)/2,query(st2,tp[a]+1,tp[b])+tp[b]+dst[b]));
				else ans=std::max(ans,std::max((len+1)/2,query(st1,tp[a],tp[b]-1)-tp[a]+dst[a]));
			}
		}else ans=std::max(std::min(dst[a],dst[b])+tp[a]-1,std::min(dst[a],dst[b])+tot-tp[a]);
		printf("%d",ans);
		//printf(" %d %d %d %d %d",tp[a],tp[b],dst[a],dst[b],mid);
		//printf(" %d %d %d %d",dst[a]+tp[a]-1,dst[b]+tot-tp[b],query(st1,tp[a],mid)-tp[a]+dst[a],query(st2,mid+1,tp[b])+tp[b]+dst[b]);
		puts("");
	}
	return 0;
}