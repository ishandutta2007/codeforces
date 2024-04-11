#include <bits/stdc++.h>

using namespace std;

long long n,m,rt[2],fq[2];
vector<long long> al[200069];
queue<long long> q;
bitset<200069> vtd;

int main()
{
	long long t,rr,i,j,ii,k,l,sz,c,u;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,rt,rt+1);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		fq[0]=0;
		fq[1]=0;
		vtd.reset();
		for(i=1;i<=n;i++)
		{
			if(i!=rt[0]&&i!=rt[1]&&!vtd[i])
			{
				u=-1;
				c=0;
				q.push(i);
				vtd[i]=1;
				for(;!q.empty();)
				{
					k=q.front();
					q.pop();
					c++;
					sz=al[k].size();
					for(j=0;j<sz;j++)
					{
						l=al[k][j];
						if(l==rt[0]||l==rt[1])
						{
							for(ii=0;ii<2;ii++)
							{
								if(l==rt[ii])
								{
									if(u==-1)
									{
										u=ii;
									}
									else if(u!=ii)
									{
										u=2;
									}
								}
							}
						}
						else if(!vtd[l])
						{
							q.push(l);
							vtd[l]=1;
						}
					}
				}
				if(u>=0&&u<=1)
				{
					fq[u]+=c;
				}
			}
		}
		printf("%lld\n",fq[0]*fq[1]);
	}
}