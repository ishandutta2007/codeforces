#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=(1<<20)+100;
queue<int>q;
char s[30],t[30];
int msk[N],dis[N],pos[N],n,m,k,a[30],ans,l,r,tmp[30];
int get(char s[])
{
	rep(i,k)tmp[a[i]]=s[i]-'0';
	int msk=0;
	rep(i,k)msk=(msk<<1)|tmp[i];
	return msk;
}
void insert(int S,int po)
{
	dis[S]=0;pos[S]=po;
	q.push(S);
	for(;!q.empty();q.pop())
	{
		int u=q.front();
		rep(i,k)
		{
			int x=u^(1<<(i-1));
			if(dis[u]+1<dis[x])dis[x]=dis[u]+1,pos[x]=po,q.push(x);
		}
	}
}
void update(int S,int po)
{
	if(dis[S]>=ans)return;
	ans=dis[S];
	l=pos[S]+1;r=po;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",s+1,t+1);
	rep(i,(1<<k))dis[i-1]=k+1;
	ans=k+1;
	rep(i,k)a[i]=i;
	msk[0]=get(s);
	rep(i,n)
	{
		int x,y;scanf("%d%d",&x,&y);
		swap(a[x],a[y]);
		msk[i]=get(s);
		if(i>=m)insert(msk[i-m],i-m);
		update(get(t),i);
	}
	printf("%d\n%d %d\n",k-ans,l,r);
    return 0;
}