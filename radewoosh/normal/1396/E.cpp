#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;

int n;
ll k;

vi graf[nax];

int mini[nax];
int maxi[nax];

int roz[nax];

ll smini, smaxi;

int oj[nax];

int opty[nax];

void dfs1(int v)
{
	for (int &i : graf[v])
	{
		if (i==oj[v])
		{
			swap(i, graf[v].back());
			graf[v].pop_back();
			break;
		}
	}
	roz[v]=1;
	for (int i : graf[v])
	{
		oj[i]=v;
		dfs1(i);
		roz[v]+=roz[i];
	}
	mini[v]=roz[v]&1;
	maxi[v]=min(roz[v], n-roz[v]);
}

ll sumanad[nax];
ll ilenad[nax];

int check(int v)
{
	ll sum=0;
	for (int i=1; i<=n; i++)
	{
		int nowe=min(maxi[i], v);
		if ((nowe&1)!=(maxi[i]&1))
			nowe++;
		opty[i]=nowe;
		sum+=opty[i];
	}
	if (sum<k)
		return 1;
	vi wek;
	for (int i=1; i<=n; i++)
	{
		if (opty[i]==v+1 && v>=1)
			wek.push_back(i);
	}
	if (sum-(ll)wek.size()*2>k)
		return -1;
	for (int i : wek)
	{
		if (sum>k)
		{
			sum-=2;
			opty[i]-=2;
		}
	}
	return 0;
}

vi zwr[nax];

vi moje[nax];

void dfs2(int v)
{
	for (int i : graf[v])
		dfs2(i);
	int r=1;
	moje[1].clear();
	moje[1].push_back(v);
	for (int i : graf[v])
	{
		r++;
		moje[r].clear();
		moje[r].swap(zwr[i]);
	}
	priority_queue<pii> kol;
	int mam=0;
	for (int i=1; i<=r; i++)
	{
		mam+=moje[i].size();
		kol.push({moje[i].size(), i});
	}
	while(mam>opty[v])
	{
		mam-=2;
		int a=kol.top().second;
		kol.pop();
		int b=kol.top().second;
		kol.pop();
		printf("%d %d\n", moje[a].back(), moje[b].back());
		moje[a].pop_back();
		moje[b].pop_back();
		kol.push({moje[a].size(), a});
		kol.push({moje[b].size(), b});
	}
	for (int i=1; i<=r; i++)
	{
		if ((int)moje[i].size()>(int)zwr[v].size())
			zwr[v].swap(moje[i]);
		for (int j : moje[i])
			zwr[v].push_back(j);
		moje[i].clear();
	}
}

int main()
{
	scanf("%d%lld", &n, &k);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs1(1);
	for (int i=1; i<=n; i++)
	{
		smini+=mini[i];
		smaxi+=maxi[i];
	}
	if (k<smini || k>smaxi || (k&1)!=(smini&1))
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i=1; i<=n; i++)
	{
		sumanad[maxi[i]]+=maxi[i];
		ilenad[maxi[i]]++;
	}
	int bsa=0;
	int bsb=n;
	while(1)
	{
		int bss=(bsa+bsb+1)>>1;
		int wez=check(bss);
		if (!wez)
			break;
		if (wez==-1)
			bsb=bss-1;
		else
			bsa=bss+1;
	}
	dfs2(1);
	return 0;
}