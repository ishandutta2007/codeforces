#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
const int nax=1007;

int n, k;

char wcz[nax];
int tab[nax];

int dzmas;

int spoko(int mas)
{
	if (!(mas&(1<<k)))
		return 1;
	if (mas&dzmas)
		return 1;
	return 0;
}

void skroc(int &mas)
{
	mas&=((1<<k)-1);
	int x=(mas&dzmas);
	if (!x)
		return;
	x&=-x;
	mas&=(x-1);
}

unordered_map<int,int> mapa[nax];

int rek(int v, int mas)
{
	if (v==n)
		return 0;
	skroc(mas);
	if (mapa[v].count(mas))
		return mapa[v][mas];
	int ret=rek(v+1, mas)+1;
	int wte=mas;
	mas=(mas<<tab[v+1])|1;
	if (spoko(mas))
		ret=min(ret, rek(v+1, mas));
	return mapa[v][wte]=ret;
}

int main()
{
	scanf("%s%d", wcz+1, &k);
	for (int i=1; i<k; i++)
		if (!(k%i))
			dzmas|=(1<<i);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=wcz[i]-'0';
	printf("%d\n", rek(0, 1));
	return 0;
}