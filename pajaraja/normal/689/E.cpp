#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 1000000007
#define stepen 1000000005
using namespace std;
long long binom[200001];
struct pockraj
{
	int x,io;
};
struct pomoc
{
	int iz,us;
	long long x;
};
bool cmp(pockraj a,pockraj b)
{
	return a.x<b.x;
}
pockraj a[400010];
vector<pomoc> d;
long long inverz(int u,long long t)
{
	if(u==0) return 1;
	long long v=inverz(u/2,t);
	if(u%2==0) return v*v%MOD;
	v=v*v%MOD;
	return v*t%MOD;
}
int main(int argc, char** argv) 
{
	inverz(stepen,2);
	pockraj tm;
	tm.x=-1000000001;
	tm.io=2;
	pomoc h;
	fill(a,a+400010,tm);
	int n,k,t1,t2,tmpi=0,tmpo=0,u=0;
	long long sol=0;
	bool uik=false;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++) binom[i]=0;
	binom[k]=1;
	for(int i=k;i<n;i++) binom[i+1]=((binom[i]*(i+1))%MOD*inverz(stepen,i-k+1)%MOD);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&t1,&t2);
		a[2*i].x=t1;
		a[2*i+1].x=t2;
		a[2*i].io=1;
		a[2*i+1].io=-1;
	}
	sort(a,a+2*n,cmp);
	for(int i=0;i<2*n;i++)
	{
		if(a[i].x==a[i+1].x)
		{
			if(a[i].io==1) tmpi++;
			else tmpo++;
		}
		else
		{
			if(a[i].io==1) tmpi++;
			else tmpo++;
			h.iz=tmpo;
			h.us=tmpi;
			h.x=a[i].x;
			d.push_back(h);
			tmpi=tmpo=0;
		}
	}
	if(n!=1)
	{
	for(int i=0;i<d.size()-1;i++)
	{
		u+=d[i].us;
		sol=(sol+binom[u])%MOD;
		u-=d[i].iz;
		sol=(sol+(d[i+1].x-d[i].x-1)*(binom[u])%MOD)%MOD;
	}
	u+=d[d.size()-1].us;
	sol=(sol+binom[u])%MOD;
    }
    else if(k==1) sol=a[1].x-a[0].x+1;
	printf("%d\n",sol);
	return 0;
}