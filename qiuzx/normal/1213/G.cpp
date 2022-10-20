#include <bits/stdc++.h>
#define N 200010
#define F first
#define S second
using namespace std;
long long n,m,t,ans=0,num[N]={},boss[N],fs[N];
vector<pair<long long,pair<long long,long long> > > e;
vector<pair<long long,long long> > q;
int getf(int x)
{
	int ret;
	if(boss[x]==x)
	{
		return x;
	}
	boss[x]=getf(boss[x]);
	return boss[x];
}
void merge(int x,int y)
{
	int a,b,c;
	a=getf(x);
	b=getf(y);
	if(num[a]<num[b])
	{
		c=a;
		a=b;
		b=c;
	}
	ans+=num[a]*num[b];
	num[a]+=num[b];
	boss[b]=a;
	return;
}
int main(){
	long long i,j,k,x,y,z;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		num[i]=1;
		boss[i]=i;
	}
	for(i=1;i<n;i++)
	{
		cin>>x>>y>>z;
		x--;
		y--;
		e.push_back(make_pair(z,make_pair(x,y)));
	}
	sort(e.begin(),e.end());
	for(i=0;i<m;i++)
	{
		cin>>t;
		q.push_back(make_pair(t,i));
	}
	sort(q.begin(),q.end());
	j=0;
	for(i=0;i<m;i++)
	{
		for(;j+1<n;j++)
		{
			if(e[j].F>q[i].F)
			{
				break;
			}
			merge(e[j].S.F,e[j].S.S);
		}
		fs[q[i].S]=ans;
	}
	for(i=0;i<m;i++)
	{
		cout<<fs[i]<<" ";
	}
	cout<<endl;
	return 0;
}