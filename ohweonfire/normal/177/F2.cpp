#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n,m,t;
pair<int,pii> p[111];

struct data
{
	int seq[20],tot;
	data()
	{
		tot=0;
	}
	void add(int v)
	{
		seq[tot++]=v;
	}
	void change(int v)
	{
		assert(tot>0);
		seq[tot-1]=v;
	}
};


bool markx[22],marky[22];

queue<data> qs[2111];

int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1,u,v,w;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		p[i]=mp(w,mp(u,v));
	}
	sort(p+1,p+m+1);
	
	qs[0].push(data());
	int cur=0;
	while(--t)
	{
		while(qs[cur].empty())cur++;
		data v=qs[cur].front();qs[cur].pop();
		memset(markx,0,sizeof(markx));
		memset(marky,0,sizeof(marky));
		
		//printf("cur= %d\n",cur);
		//for(int i=0;i<v.tot;i++)printf("%d ",v.seq[i]);puts("");
		int id=0;
		for(int i=0;i<v.tot;i++)
		{
			id=v.seq[i];
			markx[p[id].ss.ff]=marky[p[id].ss.ss]=1;
		}
		//add
		for(int i=id+1;i<=m;i++)if(!markx[p[i].ss.ff]&&!marky[p[i].ss.ss])
		{
			data nv=v;
			nv.add(i);
			qs[cur+p[i].ff].push(nv);
			break;
		}
		//change
		if(id)
		{
			markx[p[id].ss.ff]=marky[p[id].ss.ss]=0;
			for(int i=id+1;i<=m;i++)if(!markx[p[i].ss.ff]&&!marky[p[i].ss.ss])
			{
				data nv=v;
				nv.change(i);
				qs[cur-p[id].ff+p[i].ff].push(nv);
				break;
			}
		}
	}
	while(qs[cur].empty())cur++;
	printf("%d\n",cur);
	return 0;
}