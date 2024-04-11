#include<bits/stdc++.h>
using namespace std;

int n,m,q,p[200010],v[200010],t[200010],x,y,cnt;
pair<long double,int> nw;
set<pair<long double,int> > si,so;
long double ans;
double Ans;

long double calc(int v,int t,int p) {return (1.0*v*t)/(1ll*(t+p)*(t+p+1));}
long double sum(int v,int t,int p) {return (1ll*v*t)*(1.0/t-1.0/(t+p));}

int main()
{
	scanf("%d%d%d",&n,&m,&q),si.clear(),so.clear();
	for (int i=1; i<=n; i++) scanf("%d",&v[i]);
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&t[i]),p[i]=0;
		so.insert(make_pair(calc(v[i],t[i],p[i]),i));
	}
	ans=0,cnt=0;
	for (int i=1; i<=m; i++)
	{
		if (so.empty()) break;
		nw=(*--so.end()),so.erase(--so.end());
		if (p[x=nw.second]) si.erase(make_pair(calc(v[x],t[x],p[x]-1),x));
		si.insert(make_pair(calc(v[x],t[x],p[x]),x));
		ans+=nw.first,p[x]++,cnt++;
		if (p[x]<t[x]) so.insert(make_pair(calc(v[x],t[x],p[x]),x));
	}
	while (q--)
	{
		scanf("%d%d",&x,&y);
		if (x==1)
		{
			if (p[y])
			{
				ans+=sum(v[y],t[y]+1,p[y])-sum(v[y],t[y],p[y]);
				si.erase(make_pair(calc(v[y],t[y],p[y]-1),y));
				if (p[y]!=t[y]) so.erase(make_pair(calc(v[y],t[y],p[y]),y)); else
				if (cnt<m) 
				{
					si.insert(make_pair(calc(v[y],t[y]+1,p[y]),y));
					ans+=calc(v[y],t[y]+1,p[y]),cnt++,p[y]++,t[y]++;
					Ans=ans,printf("%.10lf\n",Ans); 
					continue;
				}
				if (!so.empty()&&calc(v[y],t[y]+1,p[y]-1)<(*--so.end()).first)
				{
					p[y]--;
					if (p[y]) si.insert(make_pair(calc(v[y],t[y]+1,p[y]-1),y));
					so.insert(make_pair(calc(v[y],t[y]+1,p[y]),y));
					ans-=calc(v[y],t[y]+1,p[y]),ans+=(*--so.end()).first;
					x=(*--so.end()).second,so.erase(--so.end());
					if (p[x]) si.erase(make_pair(calc(v[x],t[x],p[x]-1),x));
					si.insert(make_pair(calc(v[x],t[x],p[x]),x));
					if ((++p[x])!=t[x]) so.insert(make_pair(calc(v[x],t[x],p[x]),x));
				} else 
				{
					if (!si.empty()&&p[y]==t[y]&&calc(v[y],t[y]+1,p[y])>(*si.begin()).first)
					{
						si.insert(make_pair(calc(v[y],t[y]+1,p[y]),y));
						ans+=calc(v[y],t[y]+1,p[y]),ans-=(*si.begin()).first,p[y]++;
						x=(*si.begin()).second,si.erase(si.begin());
						if (p[x]!=t[x]) so.erase(make_pair(calc(v[x],t[x],p[x]),x));
						so.insert(make_pair(calc(v[x],t[x],p[x]-1),x));
						if (--p[x]) si.insert(make_pair(calc(v[x],t[x],p[x]-1),x));
					}
					else si.insert(make_pair(calc(v[y],t[y]+1,p[y]-1),y)),so.insert(make_pair(calc(v[y],t[y]+1,p[y]),y));
				}
			}
			else so.erase(make_pair(calc(v[y],t[y],p[y]),y)),so.insert(make_pair(calc(v[y],t[y]+1,p[y]),y));
			t[y]++;
		} else
		{
			ans+=sum(v[y],t[y]-1,p[y])-sum(v[y],t[y],p[y]);
			if (p[y]!=t[y])
			{
				if (p[y]) si.erase(make_pair(calc(v[y],t[y],p[y]-1),y));
				so.erase(make_pair(calc(v[y],t[y],p[y]),y));
				if (!si.empty()&&p[y]<t[y]-1&&calc(v[y],t[y]-1,p[y])>(*si.begin()).first)
				{
					p[y]++;
					if (p[y]!=t[y]-1) so.insert(make_pair(calc(v[y],t[y]-1,p[y]),y));
					si.insert(make_pair(calc(v[y],t[y]-1,p[y]-1),y));
					ans+=calc(v[y],t[y]-1,p[y]-1),ans-=(*si.begin()).first;
					x=(*si.begin()).second,si.erase(si.begin());
					if (p[x]!=t[x]) so.erase(make_pair(calc(v[x],t[x],p[x]),x));
					so.insert(make_pair(calc(v[x],t[x],p[x]-1),x));
					if (--p[x]) si.insert(make_pair(calc(v[x],t[x],p[x]-1),x));
				}
				else 
				{
					if (p[y]) si.insert(make_pair(calc(v[y],t[y]-1,p[y]-1),y));
					if (p[y]!=t[y]-1) so.insert(make_pair(calc(v[y],t[y]-1,p[y]),y));
				}
			}
			else 
			{
				ans-=calc(v[y],t[y],p[y]-1);
				si.erase(make_pair(calc(v[y],t[y],p[y]-1),y)),p[y]--;
				si.insert(make_pair(calc(v[y],t[y]-1,p[y]-1),y)),cnt--;
				if (!so.empty())
				{
					nw=(*--so.end()),so.erase(--so.end());
					if (p[x=nw.second]) si.erase(make_pair(calc(v[x],t[x],p[x]-1),x));
					si.insert(make_pair(calc(v[x],t[x],p[x]),x));
					ans+=nw.first,p[x]++,cnt++;
					if (p[x]<t[x]) so.insert(make_pair(calc(v[x],t[x],p[x]),x));
				}
			}
			t[y]--;
		}
		Ans=ans,printf("%.10lf\n",Ans);
	}
	return 0;
}