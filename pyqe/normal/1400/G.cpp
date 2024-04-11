#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,nm,ex[69],exx[21],dp[2][69],tmp[69],fc[300069],ifc[300069],pwk,dv=998244353;
pair<long long,long long> as[600069],ed[20];
vector<long long> al[300069];
bitset<300069> spc,vtd,vtd2,pcg;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd2[x]=1;
	exx[nm]=x;
	nm++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(vtd[l]&&!vtd2[l])
		{
			dfs(l);
		}
	}
}

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

long long cb(long long x,long long y)
{
	if(x<y)
	{
		return 0;
	}
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long i,j,r,r2,ii,jj,k,l,u,c=0,mk,c2,z=0;
	
	scanf("%lld%lld",&n,&m);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		as[i*2-1]={k,i};
		as[i*2]={l+1,-i};
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	sort(as+1,as+n*2+1);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
		al[k].push_back(l);
		al[l].push_back(k);
		spc[k]=1;
		spc[l]=1;
	}
	dp[0][0]=1;
	for(j=1,i=1;i<=n;i++)
	{
		for(;j<=n*2&&as[j].fr<=i;j++)
		{
			k=as[j].sc;
			u=abs(k)/k;
			k=abs(k);
			if(!spc[k])
			{
				c+=u;
			}
			else
			{
				vtd[k]=u==1;
				if(u==1)
				{
					nn++;
					ex[nn]=k;
				}
				else
				{
					for(r=1;r<=nn;r++)
					{
						if(ex[r]==k)
						{
							ex[r]=ex[nn];
							nn--;
							break;
						}
					}
				}
				for(r=1;r<=nn;r++)
				{
					vtd2[ex[r]]=0;
				}
				for(ii=0;ii<2;ii++)
				{
					for(r=0;r<=nn;r++)
					{
						dp[ii][r]=0;
					}
				}
				dp[0][0]=1;
				for(r=1;r<=nn;r++)
				{
					if(!vtd2[ex[r]])
					{
						nm=0;
						dfs(ex[r]);
						for(mk=0;mk<1ll<<nm;mk++)
						{
							c2=0;
							for(jj=0;jj<nm;jj++)
							{
								k=mk>>jj&1;
								c2+=k;
								pcg[exx[jj]]=k;
							}
							for(jj=0;jj<m;jj++)
							{
								k=ed[jj].fr;
								l=ed[jj].sc;
								if(pcg[k]&&pcg[l])
								{
									jj=-1;
									break;
								}
							}
							if(jj!=-1)
							{
								dp[1][c2]=(dp[1][c2]+1)%dv;
							}
						}
						for(jj=0;jj<nm;jj++)
						{
							pcg[exx[jj]]=0;
						}
						for(jj=0;jj<=nn;jj++)
						{
							tmp[jj]=0;
							for(r2=0;r2<=jj;r2++)
							{
								tmp[jj]=(tmp[jj]+dp[0][r2]*dp[1][jj-r2])%dv;
							}
						}
						for(jj=0;jj<=nn;jj++)
						{
							dp[0][jj]=tmp[jj];
							dp[1][jj]=0;
						}
					}
				}
			}
		}
		for(r=0;r<=min(nn,i);r++)
		{
			z=(z+dp[0][r]*cb(c,i-r))%dv;
		}
	}
	printf("%lld\n",z);
}