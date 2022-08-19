#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int nax=20*1007;
const int d=15;
const int kax=32;

int n, q;
int tab[nax];
int cel[nax];
int jump[nax][kax][kax];
int aktu[kax][kax];

int dalszy(int a, int b)
{
	return (tab[a]>tab[b] ? a : b);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		tab[i]=min(n, i+tab[i]);
	}
	vector<int> stos;
	for (int i=n; i; i--)
	{
		while(!stos.empty() && tab[i]>tab[stos.back()])
			stos.pop_back();
		stos.push_back(i);
		int bsa=0;
		int bsb=(int)stos.size()-1;
		while(bsa<bsb)
		{
			int bss=(bsa+bsb)>>1;
			if (stos[bss]<=tab[i])
				bsb=bss;
			else
				bsa=bss+1;
		}
		cel[i]=stos[bsa];
	}
	for (int i=n; i; i--)
	{
		jump[i][0][0]=cel[i];
		for (int j=1; j<kax; j++)
			jump[i][0][j]=dalszy(min(n, tab[i]+j), jump[i][0][j-1]);
		for (int j=1; j<d; j++)
			for (int l=0; l<kax; l++)
				for (int p=0; p<=l; p++)
					jump[i][j][l]=dalszy(jump[i][j][l], jump[jump[i][j-1][p]][j-1][l-p]);
	}
	while(q--)
	{
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		if (a==b)
		{
			printf("0\n");
			continue;
		}
		if (tab[a]+k>=b)
		{
			printf("1\n");
			continue;
		}
		int wyn=0;
		for (int j=0; j<=k; j++)
			aktu[d][j]=a;
		for (int j=d-1; j>=0; j--)
		{
			for (int l=0; l<=k; l++)
				aktu[j][l]=a;
			int moge=0;
			for (int l=0; l<=k; l++)
			{
				aktu[j][l]=a;
				for (int p=0; p<=l; p++)
					aktu[j][l]=dalszy(aktu[j][l], jump[aktu[j+1][p]][j][l-p]);
				if (tab[aktu[j][l]]+k-l>=b)
					moge=1;
			}
			if (moge)
			{
				for (int l=0; l<=k; l++)
					aktu[j][l]=aktu[j+1][l];
			}
			else
			{
				wyn+=(1<<j);
			}
		}
		printf("%d\n", wyn+2);
	}
	return 0;
}