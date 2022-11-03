// It is made by XZZ
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
il int gi(){
	rg int x=0,f=1;rg char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
const int maxn=1001,maxm=2333;
int fir[maxn],nxt[maxm],dis[maxm],id;
il vd link(int x,int y){nxt[++id]=fir[x];fir[x]=id,dis[id]=y;}
int ds[maxn],dt[maxn];int n,m,s,t;
il vd bfs(int x,int*ar){
	for(rg int i=1;i<=n;++i)ar[i]=1e9;
	int que[maxn],hd=1,tl=2;
	que[hd]=x;ar[x]=0;
	while(hd^tl){
		int y=que[hd];
		for(rg int i=fir[y];i;i=nxt[i]){
			if(ar[dis[i]]!=1e9)continue;
			ar[dis[i]]=ar[y]+1;
			que[tl++]=dis[i];
		}
		++hd;
	}
}
bool yes[maxn][maxn];
int main(){
#ifdef xzz
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	n=gi(),m=gi(),s=gi(),t=gi();int x,y;
	while(m--)x=gi(),y=gi(),link(x,y),link(y,x),yes[x][y]=yes[y][x]=1;
	bfs(s,ds);bfs(t,dt);
	int ans=0;
	for(rg int i=1;i<=n;++i)
		for(rg int j=i+1;j<=n;++j){
			if(!yes[i][j]&&(std::min(ds[i]+1+dt[j],dt[i]+1+ds[j])>=ds[t]))++ans;
		}
	printf("%d\n",ans);
	return 0;
}