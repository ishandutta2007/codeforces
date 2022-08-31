#include <bits/stdc++.h>
using namespace std;

int h;
int n;

deque <int> kol;

vector <int> now, sta;

vector <int> znam[1007];

int pyty;

void odpowiedz(int v)
{
	printf("! %d\n", v);
	fflush(stdout);
}

int spytaj(int v)
{
	if (!znam[v].empty())
		return 0;
	pyty++;
	if (pyty==17)
	{
		odpowiedz(v);
		return 1;
	}
	printf("? %d\n", v);
	fflush(stdout);
	int p1, p2;
	scanf("%d", &p1);
	while(p1--)
	{
		scanf("%d", &p2);
		znam[v].push_back(p2);
	}
	if ((int)znam[v].size()==2)
	{
		odpowiedz(v);
		return 1;
	}
	return 0;
}

int nieod(int v)
{
	for (int i=0; i<znam[v].size(); i++)
		if (znam[znam[v][i]].empty())
			return znam[v][i];
	assert(0);
}

int nieod2(int v)
{
	for (int i=(int)znam[v].size()-1; i>=0; i--)
		if (znam[znam[v][i]].empty())
			return znam[v][i];
	assert(0);
}

void wypisz(deque <int> to)
{
	while(!to.empty())
	{
		printf(" %d", to.front());
		to.pop_front();
	}
	printf("\n");
}

void solve()
{
	scanf("%d", &h);
	pyty=0;
	n=(1<<h)-1;
	for (int i=1; i<=n; i++)
		znam[i].clear();
	if (h<=4)
	{
		for (int i=1; i<=n; i++)
			if (spytaj(i))
				return;
	}
	kol.clear();
	kol.push_back(1);
	if (spytaj(1))
		return;
	while((int)znam[kol.front()].size()!=1)
	{
		int x=kol.front();
		kol.push_front(nieod(x));
		if (spytaj(kol.front()))
			return;
	}
	while((int)znam[kol.back()].size()!=1)
	{
		int x=kol.back();
		kol.push_back(nieod(x));
		if (spytaj(kol.back()))
			return;
	}
	while((int)kol.size()<7)
	{
		int r=(int)kol.size();
		for (int i=1; i<=(r/2); i++)
			kol.pop_back();
		while((int)znam[kol.back()].size()!=1 || (int)kol.size()==1)
		{
			int x=kol.back();
			kol.push_back(nieod(x));
			if (spytaj(kol.back()))
				return;
		}
	}
	int r=(int)kol.size();
	for (int i=1; i<=(r/2); i++)
		kol.pop_back();
	int m=kol.back();
	now.clear();
	sta.clear();
	now.push_back(nieod(m));
	while(1)
	{
		sta=now;
		now.clear();
		for (int i=0; i<sta.size(); i++)
			if (spytaj(sta[i]))
				return;
		for (int i=0; i<sta.size(); i++)
		{
			now.push_back(nieod(sta[i]));
			now.push_back(nieod2(sta[i]));
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}