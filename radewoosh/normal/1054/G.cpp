#include <bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
const int nax=2007;
using bn=bitset<nax>;

int n, m;

bn nal[nax];
int czlo[nax];
char wcz[nax];

int alive[nax];

vector <pii> wyn;

queue <int> kol;

void zbij(int v)
{
	czlo[v]--;
	if (czlo[v]==1)
	{
		for (int i=1; i<=n; i++)
		{
			if (nal[i][v])
			{
				kol.push(i);
				nal[i][v]=0;
				czlo[v]--;
			}
		}
	}
}

void podczep(int v, int w)
{
	alive[v]=0;
	wyn.push_back({v, w});
	for (int i=1; i<=m; i++)
		if (nal[v][i])
			zbij(i);
}

void test()
{
	scanf("%d%d", &n, &m);
	wyn.clear();
	for (int i=1; i<=n; i++)
	{
		alive[i]=1;
		nal[i].reset();
	}
	for (int i=1; i<=m; i++)
	{
		scanf("%s", wcz+1);
		czlo[i]=0;
		for (int j=1; j<=n; j++)
		{
			if (wcz[j]=='1')
			{
				czlo[i]++;
				nal[j][i]=1;
			}
		}
		if (czlo[i]==1)
			for (int j=1; j<=n; j++)
				nal[j][i]=0;
	}
	for (int i=1; i<=n; i++)
		kol.push(i);
	while(!kol.empty())
	{
		int v=kol.front();
		kol.pop();
		if (!alive[v])
			continue;
		int x=-1;
		for (int i=1; i<=n && x==-1; i++)
		{
			if (i==v || !alive[i])
				continue;
			if ((nal[v]&nal[i])==nal[v])
				x=i;
		}
		if (x!=-1)
			podczep(v, x);
	}
	if ((int)wyn.size()+1==n)
	{
		printf("YES\n");
		for (pii i : wyn)
			printf("%d %d\n", i.first, i.second);
	}
	else
	{
		printf("NO\n");
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}