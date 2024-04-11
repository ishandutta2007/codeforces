#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007,inf=100000000;
int n,hd[100010],m,cnt,dis[100010],x,y,ans[100010],T[200010],Tn,mi[10];
bool bo[100010];
struct node{int to,next,tn,t[10],p,val,fro;}e[200010];
pair<int,int> pp;
set<pair<int,int> > s;
set<pair<pair<int,int>,int> > S;

void addedge(int x,int y,int v)
{
	e[++cnt].next=hd[x];
	hd[x]=cnt,e[cnt].fro=x;
	e[cnt].to=y,e[cnt].val=v;
	e[cnt].tn=e[cnt].p=0;
	while (v) e[cnt].t[++e[cnt].tn]=v%10,v/=10;
	for (int i=1; e[cnt].tn-i+1>i; i++) swap(e[cnt].t[i],e[cnt].t[e[cnt].tn-i+1]);
}

int main()
{
	mi[0]=1;
	for (int i=1; i<10; i++) mi[i]=mi[i-1]*10ll%mod;
	scanf("%d%d",&n,&m),cnt=0;
	memset(hd,0,sizeof(hd));
	for (int i=1; i<=m; i++) scanf("%d%d",&x,&y),addedge(x,y,i),addedge(y,x,i);
	s.clear(),dis[1]=0,s.insert(make_pair(0,1));
	for (int i=2; i<=n; i++) dis[i]=inf,s.insert(make_pair(inf,i));
	while (!s.empty())
	{
		x=(*s.begin()).second,s.erase(s.begin());
		for (int i=hd[x]; i; i=e[i].next) 
			if (dis[x]+e[i].tn<dis[e[i].to])
			{
				s.erase(make_pair(dis[e[i].to],e[i].to));
				dis[e[i].to]=dis[x]+e[i].tn;
				s.insert(make_pair(dis[e[i].to],e[i].to));
			}
	}
	memset(bo,0,sizeof(bo));
	ans[1]=0,S.clear(),bo[1]=1;
	for (int i=hd[1]; i; i=e[i].next) 
		e[i].p=1,S.insert(make_pair(make_pair(-1,e[i].t[1]),i));
	while (!S.empty())
	{
		Tn=0,pp=(*S.begin()).first;
		while (!S.empty()&&(*S.begin()).first==pp) 
		{
			T[++Tn]=(*S.begin()).second;
			S.erase(S.begin());
		}
		for (int i=1; i<=Tn; i++)
		{
			x=T[i];
			if (e[x].p==e[x].tn)
			{
				if (bo[e[x].to]) continue;
				ans[e[x].to]=(1ll*ans[e[x].fro]*mi[e[x].tn]+e[x].val)%mod;
				bo[y=e[x].to]=1;
				for (int j=hd[y]; j; j=e[j].next)
					if (dis[e[j].to]==dis[y]+e[j].tn)
						e[j].p=1,S.insert(make_pair(make_pair(pp.first-1,e[j].t[1]),j));
			}
			else S.insert(make_pair(make_pair(pp.first-1,e[x].t[++e[x].p]),x));
		}
	}
	for (int i=2; i<=n; i++) printf("%d\n",ans[i]);
	return 0;
}