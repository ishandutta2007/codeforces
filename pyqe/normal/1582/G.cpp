#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const int ma=1e6,inf=1e9;
int n,nn[1000069],fq[1000069],a[1000069];
pair<int,int> fz[1000069][7];
vector<pair<int,int>> sk[1000069];
bitset<1000069> spc;
multiset<int> ms;

int main()
{
	int i,j,k,w,c,u,ww;
	long long z=0;
	char ch;
	
	for(i=2;i<=ma;i++)
	{
		if(!fq[i])
		{
			for(j=i;j<=ma;j+=i)
			{
				for(c=0,k=j;k%i==0;k/=i,c++);
				fz[j][fq[j]]={i,c};
				fq[j]++;
			}
			sk[i].push_back({-1,-inf});
			sk[i].push_back({0,0});
			nn[i]=1;
			ms.insert(-1);
		}
	}
	scanf("%d",&n);
	for(i=n;i;i--)
	{
		scanf("%d",a+i);
	}
	for(i=n;i;i--)
	{
		scanf(" %c",&ch);
		spc[i]=ch=='/';
	}
	for(i=1;i<=n;i++)
	{
		u=spc[i]*2-1;
		for(j=0;j<fq[a[i]];j++)
		{
			k=fz[a[i]][j].fr;
			w=fz[a[i]][j].sc;
			sk[k][nn[k]].fr=i-1;
			ms.erase(ms.find(sk[k][nn[k]-1].fr));
			ww=sk[k][nn[k]].sc+w*u;
			for(;nn[k]&&sk[k][nn[k]].sc>=ww;sk[k].pop_back(),nn[k]--);
			ms.insert(sk[k][nn[k]].fr);
			sk[k].push_back({i,ww});
			nn[k]++;
		}
		z+=i-1-*prev(ms.end());
	}
	printf("%lld\n",z);
}