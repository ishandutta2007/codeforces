#include <bits/stdc++.h>

using namespace std;

const long long ma=5e5,dv=1e9+7;
long long n,m,pc[500069],dh[500069],dh2[500069],pr[500069],fq[500069],pwk,z[3],z2[3][3];
vector<long long> al[500069];
bitset<500069> vtd,vtd2;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

void dfs(long long x,long long b4)
{
	long long i,sz=al[x].size(),k,k2,l,w,p;
	
	vtd[x]=1;
	vtd2[x]=1;
	dh2[x]+=max(sz-2,0ll);
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(l==b4)
		{
			continue;
		}
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			dh2[l]=dh2[x];
			pr[l]=x;
			dfs(l,x);
		}
		else if(vtd2[l])
		{
			k=dh[x]-dh[l]+1;
			k2=dh2[x]-dh2[pr[l]];
			w=z[2];
			z[2]=(z[2]+pc[k])%dv;
			z2[0][2]=(z2[0][2]+pc[k]*k+pc[k+1]*(n-k))%dv;
			z2[1][2]=(z2[1][2]+pc[k]*k+pc[k+1]*k2+pc[k+2]*(m-k-k2))%dv;
			for(p=x;p!=pr[l];p=pr[p])
			{
				w=(w+dv-fq[p])%dv;
				z2[2][2]=(z2[2][2]+pc[k]*fq[p]%dv*2%dv*2)%dv;
				fq[p]=(fq[p]+pc[k])%dv;
			}
			z2[2][2]=(z2[2][2]+pc[k]*(w*2+1))%dv;
		}
	}
	vtd2[x]=0;
}

int main()
{
	long long i,k,l,sz,c=0,zzz;
	
	k=pw(2,dv-2);
	pc[0]=1;
	for(i=1;i<=ma;i++)
	{
		pc[i]=pc[i-1]*k%dv;
	}
	scanf("%lld%lld",&n,&m);
	z[0]=pc[1]*n%dv;
	z[1]=pc[2]*m%dv;
	z2[0][0]=(pc[1]*n+pc[2]*n%dv*(n-1))%dv;
	z2[0][1]=(pc[2]*m%dv*2+pc[3]*m%dv*(n-2))%dv;
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		sz=al[i].size();
		c=(c+sz*(sz-1))%dv;
	}
	
	z2[1][1]=(pc[2]*m+pc[3]*c+pc[4]*(m*(m-1)%dv+dv-c))%dv;
	dfs(1,0);
	k=(z[0]+dv-z[1]+z[2])%dv;
	zzz=(z2[0][0]+z2[1][1]+z2[2][2]+dv-z2[0][1]*2%dv+z2[0][2]*2+dv-z2[1][2]*2%dv+dv-k*k%dv)%dv;
	printf("%lld\n",zzz);
}