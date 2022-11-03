#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m,s,t,p[2010];
int fir[2010],dis[200010],nxt[200010],w[200010],id;
void link(int a,int b,int c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
ll x[2010],y[2010],u[2010];bool vis[2010];
std::priority_queue<std::pair<ll,int>>que;
ll f[2][2010][2010],s1[2010][2010],s2[2010][2010];
ll S1[2010][2010],S2[2010][2010];
bool Y1[2010][2010],Y2[2010][2010];
void Dijk(int s,ll*dist){
	for(int i=1;i<=n;++i)dist[i]=3e18,vis[i]=0;
	que.push({0ll,s});dist[s]=0;
	while(!que.empty()){
		int x=que.top().second;vis[x]=1;
		for(int i=fir[x];i;i=nxt[i])
			if(dist[dis[i]]>dist[x]+w[i]){
				dist[dis[i]]=dist[x]+w[i];
				que.push({-dist[dis[i]],dis[i]});
			}
		while(!que.empty()&&vis[que.top().second])que.pop();
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi(),s=gi(),t=gi();
	int a,b,c;
	for(int i=1;i<=n;++i)p[i]=gi();
	for(int i=1;i<=m;++i)a=gi(),b=gi(),c=gi(),link(a,b,c),link(b,a,c);
	Dijk(s,x),Dijk(t,y);
	for(int i=1;i<=n;++i)u[i]=x[i];
	std::sort(u+1,u+n+1);
	for(int i=1;i<=n;++i)x[i]=std::lower_bound(u+1,u+n+1,x[i])-u;
	for(int i=1;i<=n;++i)u[i]=y[i];
	std::sort(u+1,u+n+1);
	for(int i=1;i<=n;++i)y[i]=std::lower_bound(u+1,u+n+1,y[i])-u;
	memset(f,-63,sizeof f);
	for(int i=0;i<=n+1;++i)f[0][i][n+1]=f[1][i][n+1]=0;
	for(int i=0;i<=n+1;++i)f[0][n+1][i]=f[1][n+1][i]=0;
	for(int i=1;i<=n;++i)S1[x[i]][y[i]]+=p[i],S2[x[i]][y[i]]+=p[i],Y1[x[i]][y[i]]=Y2[x[i]][y[i]]=1;
	for(int i=n;i;--i)
		for(int j=n;j;--j){
			S1[i][j]+=S1[i+1][j],S2[i][j]+=S2[i][j+1];
			Y1[i][j]|=Y1[i+1][j],Y2[i][j]|=Y2[i][j+1];
		}
	memset(s1,-63,sizeof s1);memset(s2,-63,sizeof s2);
	for(int i=n;i;--i)
		for(int j=n;j;--j){
			s1[i][j]=s1[i+1][j];if(Y2[i][j])s1[i][j]=std::max(s1[i][j],-f[1][i+1][j])+S2[i][j];
			s2[i][j]=s2[i][j+1];if(Y1[i][j])s2[i][j]=std::max(s2[i][j],-f[0][i][j+1])+S1[i][j];
			f[0][i][j]=s1[i][j];if(s1[i][j]==s1[0][0])f[0][i][j]=0;
			f[1][i][j]=s2[i][j];if(s2[i][j]==s2[0][0])f[1][i][j]=0;
		}
	if(f[0][1][1]>0)puts("Break a heart");
	else if(f[0][1][1]==0)puts("Flowers");
	else puts("Cry");
	//printf("%lld\n",f[0][1][1]);
	return 0;
}