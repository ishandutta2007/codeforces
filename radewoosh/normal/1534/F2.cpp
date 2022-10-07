#include <bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
using vi=vector<int>;
const int nax=1000*1007;

int n, m;

char wcz[nax];

int k;

vector<pii> gdz[nax];
int chce[nax];

int kol[nax];

vi graf[nax];

int kim[nax];
vi jego[nax];

int mocne[nax];

int wyn;

void kra(int a, int b)
{
	graf[a].push_back(b);
}

void oznacz(int v, int czym)
{
	if (kim[v])
		return;
	kim[v]=czym;
	jego[czym].push_back(v);
	for (int i : graf[v])
		oznacz(i, czym);
}

void umocnij(int v)
{
	if (mocne[v])
		return;
	mocne[v]=1;
	for (int i : graf[v])
		umocnij(i);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=m; j++)
		{
			if (wcz[j]=='#')
			{
				k++;
				gdz[j].push_back({n+1-i, k});
				kol[k]=j;
			}
		}
	}
	for (int i=1; i<=m; i++)
		scanf("%d", &chce[i]);
	for (int i=1; i<=m; i++)
		reverse(gdz[i].begin(), gdz[i].end());
	for (int i=1; i<=m; i++)
	{
		chce[i]-=gdz[i].size();
		for (int j=1; j<(int)gdz[i].size(); j++)
		{
			kra(gdz[i][j].second, gdz[i][j-1].second);
			if (gdz[i][j].first-1==gdz[i][j-1].first)
				kra(gdz[i][j-1].second, gdz[i][j].second);
		}
		for (int cel : {i-1, i+1})
		{
			if (cel<1 || cel>m || gdz[cel].empty())
				continue;
			int w=0;
			for (pii j : gdz[i])
			{
				while(w+1<(int)gdz[cel].size() && gdz[cel][w+1].first<=j.first)
					w++;
				if (gdz[cel][w].first>j.first)
					continue;
				kra(j.second, gdz[cel][w].second);
			}
		}
	}
	for (int i=m; i; i--)
		if (!gdz[i].empty())
			oznacz(gdz[i].back().second, i);
	for (int h=1; h<=m; h++)
	{
		if (gdz[h].empty())
			continue;
		int v=gdz[h].back().second;
		for (int i : jego[h])
			if (!mocne[i])
				chce[kol[i]]++;
		int ok=1;
		for (int i : jego[h])
			if (!mocne[i])
				if (chce[kol[i]]>0)
					ok=0;
		if (!ok)
		{
			wyn++;
			for (int i : jego[h])
				if (!mocne[i])
					chce[kol[i]]--;
			umocnij(v);
		}
	}
	printf("%d\n", wyn);
	return 0;
}