#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
long long bt[4][MAXN],p[MAXN],pi[MAXN];
void upd(int k,int x, long long val)
{
	while(x<MAXN)
	{
		bt[k][x]+=val;
		x+=(x&-x);
	}
}
long long query(int k,int x)
{
	long long s=0;
	while(x)
	{
		s+=bt[k][x];
		x-=(x&-x);
	}
	return s;
}
int main()
{
	int n; cin>>n;
	long long inv=0,izb=0;
	priority_queue<int> pql;
	priority_queue<int,vector<int>,greater<int> > pqu;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n;i++) pi[p[i]]=i;
	for(int i=1;i<=n;i++) upd(2,i,1);
	for(int i=1;i<=n;i++)
	{
		int t=pi[i];
		inv+=(i-1-query(1,t));
		int a=query(1,t);
		izb-=(min(a,i-1-a));
		upd(1,t,1);
		if(i==1) {pql.push(t); upd(2,t,-1); cout<<0; continue;}
		if(i&1)
		{
			//oba jednaka
			upd(2,t,-1);
			int y=pql.top(),z=pqu.top();
			if(t>=y && t<=z) pql.push(t);
			else
			{
				if(t<y) {izb+=query(2,y)-query(2,t-1); pql.push(t);}
				else
				{
					izb+=query(2,t)-query(2,z-1);
					int r=pqu.top();
					pqu.pop(); pqu.push(t);
					pql.push(r);
				}
			}
		}
		else
		{
			//nejednaka
			upd(2,t,-1);
			int z=max(t,pql.top()),y=min(t,pql.top());
			izb+=query(2,z)-query(2,y-1);
			if(t>pql.top()) pqu.push(t);
			else
			{
				int r=pql.top();
				pql.pop(); pql.push(t);
				pqu.push(r);
			}
		}
		cout<<" "<<inv+izb;
	}
}