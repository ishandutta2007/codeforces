#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,m,nn,nm,a[300069],pst[300069],ex[300069],vi[300069];
map<int,int> fq;
pair<int,int> as[300069];
vector<int> al[300069];

int main()
{
	int t,rr,i,j,r,k,l,p,sz;
	long long z;
	
	scanf("%d",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d",&n,&m);
		fq.clear();
		nn=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			if(!fq[k])
			{
				nn++;
				a[nn]=k;
			}
			fq[k]++;
		}
		sort(a+1,a+nn+1);
		for(i=1;i<=nn;i++)
		{
			as[i]={fq[a[i]],a[i]};
			al[i].clear();
		}
		sort(as+1,as+nn+1);
		nm=0;
		for(i=1;i<=nn;i++)
		{
			l=as[i].sc;
			p=lower_bound(a+1,a+nn+1,l)-a;
			pst[p]=i;
			if(i==nn||as[i].fr!=as[i+1].fr)
			{
				nm++;
				ex[nm]=i;
			}
			vi[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&k,&l);
			k=lower_bound(a+1,a+nn+1,k)-a;
			l=lower_bound(a+1,a+nn+1,l)-a;
			al[k].push_back(l);
			al[l].push_back(k);
		}
		z=0;
		for(i=1;i<=nn;i++)
		{
			sz=al[i].size();
			for(j=0;j<sz;j++)
			{
				l=al[i][j];
				vi[pst[l]]=i;
			}
			vi[pst[i]]=i;
			for(j=1;j<=nm;j++)
			{
				for(r=ex[j];r>ex[j-1]&&vi[r]==i;r--);
				if(r>ex[j-1])
				{
					z=max(z,(long long)(as[pst[i]].fr+as[r].fr)*(as[pst[i]].sc+as[r].sc));
				}
			}
		}
		printf("%lld\n",z);
	}
}