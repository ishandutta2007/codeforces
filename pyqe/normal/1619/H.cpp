#include <bits/stdc++.h>

using namespace std;

const int sqn=77;
int n,nn,a[100069],ln[100069],sr[100069],od[100069];
bitset<100069> vtd,spc;
vector<int> vl[100069],ex[100069];

inline void bd()
{
	int i,p;
	
	vtd.reset();
	for(i=1;i<=n;i++)
	{
		vl[i].clear();
		ln[i]=0;
		if(!vtd[i])
		{
			for(p=i;!vtd[p];p=a[p],ln[i]++)
			{
				vtd[p]=1;
				vl[i].push_back(p);
				sr[p]=i;
				od[p]=ln[i];
			}
		}
		ex[i].clear();
	}
	nn=0;
	spc.reset();
}

int main()
{
	int t,rr,i,ii,ky,k,l,w,p,sz;
	
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	bd();
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d%d",&ky,&k,&l);
		if(ky==1)
		{
			swap(a[k],a[l]);
			for(ii=0;ii<2;ii++)
			{
				if(!spc[k])
				{
					nn++;
					if(nn>=sqn*2)
					{
						bd();
					}
					else
					{
						spc[k]=1;
						p=lower_bound(ex[sr[k]].begin(),ex[sr[k]].end(),od[k])-ex[sr[k]].begin();
						sz=ex[sr[k]].size();
						ex[sr[k]].push_back(0);
						for(i=sz;i>p;i--)
						{
							ex[sr[k]][i]=ex[sr[k]][i-1];
						}
						ex[sr[k]][p]=od[k];
					}
				}
				swap(k,l);
			}
		}
		else
		{
			for(;1;)
			{
				if(ex[sr[k]].empty())
				{
					break;
				}
				p=lower_bound(ex[sr[k]].begin(),ex[sr[k]].end(),od[k])-ex[sr[k]].begin();
				sz=ex[sr[k]].size();
				if(p>=sz)
				{
					p=0;
				}
				w=(ex[sr[k]][p]+ln[sr[k]]-od[k])%ln[sr[k]];
				if(w>=l)
				{
					break;
				}
				k=a[vl[sr[k]][ex[sr[k]][p]]];
				l-=w+1;
			}
			printf("%d\n",vl[sr[k]][(od[k]+l)%ln[sr[k]]]);
		}
	}
}