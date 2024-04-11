#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,m,d,nr[3069][3069],pr[3069][3069],sq[9000069],zs=0,inf=1e9;
vector<int> al[3069];
pair<pair<int,int>,int> ex[100069];
queue<pair<int,int>> q;

int main()
{
	int i,j,k,l,w,sz,tg,p,mn,e;
	pair<int,int> mne={inf,-1};
	
	scanf("%d%d%d",&n,&m,&d);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=d;i++)
	{
		scanf("%d%d%d",&k,&l,&w);
		ex[i]={{k,l},w};
	}
	sort(ex+1,ex+d+1);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			nr[i][j]=inf;
		}
	}
	q.push({0,1});
	nr[0][1]=0;
	for(;!q.empty();)
	{
		k=q.front().fr;
		l=q.front().sc;
		q.pop();
		sz=al[l].size();
		for(i=0;i<sz;i++)
		{
			tg=al[l][i];
			p=lower_bound(ex+1,ex+d+1,mp(mp(k,l),tg))-ex;
			if((p>d||ex[p]!=mp(mp(k,l),tg))&&nr[k][l]+1<nr[l][tg])
			{
				q.push({l,tg});
				nr[l][tg]=nr[k][l]+1;
				pr[l][tg]=k;
			}
		}
	}
	zs++;
	sq[zs]=n;
	for(i=1;i<=n;i++)
	{
		mne=min(mne,{nr[i][n],i});
	}
	mn=mne.fr;
	if(mn==inf)
	{
		printf("-1\n");
		return 0;
	}
	l=n;
	e=mne.sc;
	for(;e;)
	{
		zs++;
		sq[zs]=e;
		tg=pr[e][l];
		l=e;
		e=tg;
	}
	printf("%d\n",mn);
	for(i=zs;i;i--)
	{
		printf("%d%c",sq[i]," \n"[i==1]);
	}
}