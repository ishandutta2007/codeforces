#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn=0,sqn=707,dsu[500069];
pair<pair<long long,long long>,long long> qq[200069];
vector<long long> vl[100069],pst[100069],ex[500069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long t,rr,i,j,ii,k,l,w,sz,p,kk,ll,szz,z;
	vector<long long> v;
	char ch;
	
	scanf("%lld%lld%lld%lld",&n,&m,&d,&t);
	for(rr=1;rr<=m+t;rr++)
	{
		if(rr<=m)
		{
			ch='+';
		}
		else
		{
			scanf(" %c",&ch);
		}
		scanf("%lld%lld",&k,&l);
		w=0;
		if(ch=='+')
		{
			scanf("%lld",&w);
			vl[k].push_back(w);
			vl[l].push_back(w);
		}
		qq[rr]={{k,l},w};
	}
	for(i=1;i<=n;i++)
	{
		vl[i].push_back(0);
		sort(vl[i].begin(),vl[i].end());
		sz=vl[i].size();
		p=0;
		for(j=0;j<sz;j++)
		{
			k=vl[i][j];
			if(!p||k!=vl[i][p-1])
			{
				vl[i][p]=k;
				nn++;
				dsu[nn]=nn;
				pst[i].push_back(nn);
				p++;
			}
		}
		for(j=0;j<sz-p;j++)
		{
			vl[i].pop_back();
		}
		sz=p;
		if(sz>sqn)
		{
			for(j=0;j<sz;j++)
			{
				k=pst[i][j];
				ex[k].push_back(i);
			}
		}
	}
	for(rr=1;rr<=m+t;rr++)
	{
		k=qq[rr].fr.fr;
		l=qq[rr].fr.sc;
		w=qq[rr].sc;
		if(w)
		{
			for(ii=0;ii<2;ii++)
			{
				kk=fd(pst[k][lower_bound(vl[k].begin(),vl[k].end(),0)-vl[k].begin()]);
				ll=fd(pst[l][lower_bound(vl[l].begin(),vl[l].end(),w)-vl[l].begin()]);
				if(kk!=ll)
				{
					v.clear();
					sz=ex[ll].size();
					szz=ex[kk].size();
					for(j=0,i=0;i<=sz;i++)
					{
						p=n+1;
						if(i<sz)
						{
							p=ex[ll][i];
						}
						for(;j<szz&&ex[kk][j]<p;j++)
						{
							v.push_back(ex[kk][j]);
						}
						if(i<sz&&(j>=szz||ex[kk][j]!=p))
						{
							v.push_back(p);
						}
					}
					ex[kk]=v;
					dsu[ll]=kk;
				}
				swap(k,l);
			}
		}
		else
		{
			sz=vl[l].size();
			if(sz<=sqn)
			{
				for(i=0;i<sz;i++)
				{
					kk=pst[l][i];
					if(fd(pst[k][0])==fd(kk))
					{
						break;
					}
				}
				z=i<sz;
			}
			else
			{
				kk=fd(pst[k][0]);
				sz=ex[kk].size();
				p=lower_bound(ex[kk].begin(),ex[kk].end(),l)-ex[kk].begin();
				z=p<sz&&ex[kk][p]==l;
			}
			if(z)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
	}
}