#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
int m;

vector < pair <long long,int> > wek[1000007];

int co;
int l, p;
long long x;

int dok[1000007];

long long ocze[1000007];

int lew;
int pra;

long long s;

int bsa, bsb, bss;

int main()
{
	scanf("%d%d", &n, &q);
	m=(n-1)/700+1;
	for (int i=1; i<=n; i++)
	{
		dok[i]=(i-1)/700+1;
		scanf("%d", &co);
		wek[dok[i]].push_back(make_pair(co, i));
	}
	for (int i=1; i<=m; i++)
	{
		sort(wek[i].begin(), wek[i].end());
	}
	while(q--)
	{
		scanf("%d", &co);
		if (co==1)
		{
			scanf("%d%d%lld", &l, &p, &x);
			for (int i=dok[l]+1; i<dok[p]; i++)
			{
				ocze[i]+=x;
			}
			for (int i=0; i<wek[dok[l]].size(); i++)
			{
				if (wek[dok[l]][i].second>=l && wek[dok[l]][i].second<=p)
				{
					wek[dok[l]][i].first+=x;
				}
			}
			sort(wek[dok[l]].begin(), wek[dok[l]].end());
			if (dok[l]!=dok[p])
			{
				for (int i=0; i<wek[dok[p]].size(); i++)
				{
					if (wek[dok[p]][i].second>=l && wek[dok[p]][i].second<=p)
					{
						wek[dok[p]][i].first+=x;
					}
				}
				sort(wek[dok[p]].begin(), wek[dok[p]].end());
			}
		}
		else
		{
			scanf("%lld", &x);
			lew=1000000;
			pra=0;
			for (int i=1; i<=m; i++)
			{
				s=x-ocze[i];
				
				bsa=0;
				bsb=wek[i].size()-1;
				while(bsa<bsb)
				{
					bss=(bsa+bsb)>>1;
					if (wek[i][bss].first>=s)
					bsb=bss;
					else
					bsa=bss+1;
				}
				if (wek[i][bsa].first==s)
				lew=min(lew, wek[i][bsa].second);
				
				bsa=0;
				bsb=wek[i].size()-1;
				while(bsa<bsb)
				{
					bss=(bsa+bsb+2)>>1;
					if (wek[i][bss].first<=s)
					bsa=bss;
					else
					bsb=bss-1;
				}
				if (wek[i][bsa].first==s)
				pra=max(pra, wek[i][bsa].second);
			}
			printf("%d\n", max(-1, pra-lew));
		}
	}
	return 0;
}