#include <bits/stdc++.h>
using namespace std;

const int nax=1100*1007;
const int n1=(1<<19);
using ll=long long;

int n;
ll c;

pair <ll,ll> prze[nax];
ll kosz[nax];

int kt[nax];
int gdz[nax];

vector <pair <ll,int> > wek;

ll ost;

ll naj;
ll wolne;

map <int,ll> lo[nax];
ll best_lo[nax];
ll only[nax];

ll drz[nax];

int m;

int m_wsk;
pair <ll,int> zapy[nax];
ll wyn[nax];

set <int> setel;

void pisz(int v, ll w)
{
	v+=n1-1;
	while(v)
	{
		drz[v]=max(drz[v], w);
		v>>=1;
	}
}

ll czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
		return drz[v];
	if (a>grab || b<graa)
		return 0;
	return max(
	czyt((v<<1), a, (a+b)>>1, graa, grab),
	czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab)
	);
}

bool mniej(int a, int b)
{
	return kosz[a]<kosz[b];
}

inline void consider(int v)
{
	if (kosz[v]>c)
		return;
	naj=max(naj, only[v]+best_lo[v]);
	int bsa=0;
	int bsb=n;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb+2)>>1;
		if (kosz[kt[bss]]+kosz[v]<=c)
			bsa=bss;
		else
			bsb=bss-1;
	}
	naj=max(naj, only[v]+czyt(1, 1, n1, 1, min(gdz[v]-1, bsa)));
	naj=max(naj, only[v]+czyt(1, 1, n1, gdz[v]+1, bsa));
}

int main()
{
	scanf("%d%lld", &n, &c);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld%lld", &prze[i].first, &prze[i].second, &kosz[i]);
		wek.push_back({prze[i].first, i});
		wek.push_back({prze[i].second, -i});
		kt[i]=i;
	}
	sort(kt+1, kt+1+n, mniej);
	for (int i=1; i<=n; i++)
		gdz[kt[i]]=i;
	wek.push_back({2000*1000*1000, 0});
	sort(wek.begin(), wek.end());
	scanf("%d", &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%lld", &zapy[i].first);
		zapy[i].second=i;
	}
	sort(zapy+1, zapy+1+m);
	for (auto i : wek)
	{
		ll dlu=i.first-ost;
		ost=i.first;
		
		if (setel.size()==0)
		{
			wolne+=dlu;
		}
		if (setel.size()==1)
		{
			int x=(*setel.begin());
			only[x]+=dlu;
			pisz(gdz[x], only[x]);
			consider(x);
		}
		if (setel.size()==2)
		{
			auto it=setel.begin();
			int x=(*it);
			it++;
			int y=(*it);
			lo[x][y]+=dlu;
			lo[y][x]+=dlu;
			if (kosz[x]+kosz[y]<=c)
			{
				best_lo[x]=max(best_lo[x], lo[x][y]+only[y]);
				best_lo[y]=max(best_lo[y], lo[y][x]+only[x]);
				naj=max(naj, only[x]+only[y]+lo[x][y]);
			}
		}
		
		while(m_wsk<m && zapy[m_wsk+1].first<=wolne+naj)
		{
			m_wsk++;
			wyn[zapy[m_wsk].second]=ost-(wolne+naj-zapy[m_wsk].first);
		}
		
		if (i.second>0)
			setel.insert(i.second);
		else
			setel.erase(-i.second);
	}
	for (int i=1; i<=m; i++)
		printf("%lld\n", wyn[i]);
	return 0;
}