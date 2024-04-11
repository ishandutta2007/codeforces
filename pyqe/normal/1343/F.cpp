#include <bits/stdc++.h>

using namespace std;

long long n,fq[1069],sq[1069],sr[1069],cd[2][1069],kc[2][1069],zs,pst[1069];
vector<long long> a[1069],vl[1069];
bitset<1069> vtd;

void rc(long long pz,long long x)
{
	long long i,j,l,sz,tg[2],c=0;
	
	sq[pz]=x;
	if(pz==1)
	{
		for(i=1;i<=n;i++)
		{
			cd[zs][i]=sq[i];
			kc[zs][i]=sr[i];
		}
		zs++;
		return;
	}
	for(i=0;vtd[vl[x][i]];i++);
	sr[pz]=vl[x][i];
	vtd[sr[pz]]=1;
	sz=a[sr[pz]].size();
	for(i=0;i<sz;i++)
	{
		l=a[sr[pz]][i];
		fq[l]--;
		if(fq[l]==1||(pz==2&&l!=x))
		{
			tg[c]=l;
			c++;
		}
	}
	for(i=0;i<c;i++)
	{
		rc(pz-1,tg[i]);
	}
	for(i=0;i<sz;i++)
	{
		l=a[sr[pz]][i];
		fq[l]++;
	}
	vtd[sr[pz]]=0;
}

int main()
{
	long long t,rr,i,j,r,k,sz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n+1;i++)
		{
			a[i].clear();
			vl[i].clear();
			fq[i]=0;
			vtd[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			sz=n+1;
			if(i<n)
			{
				scanf("%lld",&sz);
			}
			for(j=1;j<=sz;j++)
			{
				k=j;
				if(i<n)
				{
					scanf("%lld",&k);
				}
				a[i].push_back(k);
				vl[k].push_back(i);
				fq[k]++;
			}
		}
		zs=0;
		rc(n+1,n+1);
		for(i=0;i<zs;i++)
		{
			for(j=1;j<=n;j++)
			{
				pst[cd[i][j]]=j;
			}
			for(j=1;j&&j<=n;j++)
			{
				sz=a[kc[i][j]].size();
				for(r=0;r<sz;r++)
				{
					k=a[kc[i][j]][r];
					if(pst[k]<j-sz+1||pst[k]>j)
					{
						j=-1;
						break;
					}
				}
			}
			if(j)
			{
				for(j=1;j<=n;j++)
				{
					printf("%lld%c",cd[i][j]," \n"[j==n]);
				}
				break;
			}
		}
	}
}