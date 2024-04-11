#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 500011;
struct edge{int v,w,nxt;}e[MAXN<<1|1];
int cnt=1,last[MAXN];
void adde(int u,int v,int w)
{
	//if(cnt&1)printf("add %d %d %d\n",u,v,w);
	e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;
}
int dis[MAXN];
struct node
{
	int u,dis;
	node(){}
	node(int u,int dis):u(u),dis(dis) {}
	bool operator< (const node& you)const{return dis>you.dis;}
};
std::priority_queue<node>q;
ll Dij(int t)
{
	while(q.size())
	{
		int u=q.top().u,tmp=q.top().dis;q.pop();
		if(dis[u]!=tmp)continue;
		for(int i=last[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(umin(dis[v],dis[u]+e[i].w))q.push(node(v,dis[v]));
		}
	}
	//printf("%d\n",dis[t]);
	return dis[t];
}
int px[511][511],py[511][511],cx[511][511],cy[511][511];
ll solve(int k)
{
	memcpy(cx,px,sizeof px),memcpy(cy,py,sizeof py);
	int M=(k>>1)+1;
	//Type1,from left to center
	//add cx
	for(int x=M;x<=k;++x)cx[k-x+1][M]+=px[x][M];
	for(int y=M+1;y<=k+1;++y)
		for(int x=1;x<=k;++x)cx[k-x+1][k-y+2]+=px[x][y];
	//add cy
	for(int y=M;y<=k;++y)
		for(int x=1;x<=k;++x)cy[k-x+2][k-y+1]+=py[x][y];
	/*
	puts("Cx:");
	for(int y=k+1;y;--y)
		for(int x=1;x<=k+1;++x)printf("%d%c",cx[x][y],x==k+1?'\n':' ');
	puts("Cy:");
	for(int y=k+1;y;--y)
		for(int x=1;x<=k+1;++x)printf("%d%c",cy[x][y],x==k+1?'\n':' ');
		*/
	memset(dis,0x3f,sizeof dis);
	cnt=1,memset(last,0,sizeof last);
	for(int y=1;y<M;++y)
		for(int x=1;x<=k;++x)
		{
			int cur=(y-1)*(k+1)+x;
			adde(cur,cur+1,cx[x][y]),adde(cur+1,cur,cx[x][y]);
		}
	for(int x=1;x<M;++x)
	{
		int cur=(M-1)*(k+1)+x;
		adde(cur,cur+1,cx[x][M]),adde(cur+1,cur,cx[x][M]);
	}
	for(int y=1;y<M;++y)
		for(int x=1;x<=k+1;++x)
		{
			int cur=(y-1)*(k+1)+x;
			adde(cur,cur+(k+1),cy[x][y]),adde(cur+(k+1),cur,cy[x][y]);
		}
	for(int x=1;x<=k+1;++x)dis[x]=0,q.push(node(x,0));
	for(int y=2;y<=M;++y)
		dis[(y-1)*(k+1)+1]=0,q.push(node((y-1)*(k+1)+1,0)),//printf("%d,",(y-1)*(k+1)+1),
		dis[y*(k+1)]=0,q.push(node(y*(k+1),0));//,printf("%d,",y*(k+1));
	return Dij((M-1)*(k+1)+M);
}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),k=read();
		memset(px,0,sizeof px),memset(py,0,sizeof py);
		for(int i=1;i<=n;++i)
		{
			int x1=read(),y1=read(),x2=read(),y2=read();
			if(x2==x1+1)++py[x2][y1];
			if(x1==x2+1)++py[x1][y1];
			if(y2==y1+1)++px[x1][y2];
			if(y1==y2+1)++px[x1][y1];
		}
		ll f1=solve(k);
		for(int y=1;y<=k+1;++y)
			for(int x=1;x<=(k>>1);++x)std::swap(px[x][y],px[k+1-x][y]),std::swap(py[x][y],py[k+2-x][y]);
		ll f2=solve(k);
		for(int y=1;y<=k+1;++y)
			for(int x=1;x<=(k>>1);++x)std::swap(px[x][y],px[k+1-x][y]),std::swap(py[x][y],py[k+2-x][y]);
		for(int i=1;i<=k+1;++i)
			for(int j=1;j<=i;++j)
			{
				if(j<i)std::swap(px[i][j],py[j][i]),std::swap(py[i][j],px[j][i]);
				else std::swap(px[i][j],py[i][j]);
			}
		ll f3=solve(k);
		/*
	puts("Px:");
	for(int y=k+1;y;--y)
		for(int x=1;x<=k+1;++x)printf("%d%c",px[x][y],x==k+1?'\n':' ');
	puts("Py:");
	for(int y=k+1;y;--y)
		for(int x=1;x<=k+1;++x)printf("%d%c",py[x][y],x==k+1?'\n':' ');
		*/
		for(int y=1;y<=k+1;++y)
			for(int x=1;x<=(k>>1);++x)std::swap(px[x][y],px[k+1-x][y]),std::swap(py[x][y],py[k+2-x][y]);
		/*
	puts("Px:");
	for(int y=k+1;y;--y)
		for(int x=1;x<=k+1;++x)printf("%d%c",px[x][y],x==k+1?'\n':' ');
	puts("Py:");
	for(int y=k+1;y;--y)
		for(int x=1;x<=k+1;++x)printf("%d%c",py[x][y],x==k+1?'\n':' ');
		*/
		ll f4=solve(k);
		printf("%lld\n",n-min(min(f1,f2),min(f3,f4)));
	}
	return 0;
}