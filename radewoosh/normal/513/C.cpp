#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

int n;
int tabo[10];
int tabd[10];
double wyn;
int m=1;
double por[35];
double mnie[35];
double mniez[35];
bitset <6> roz;
double aktu;
int pot[10];
int ile;

double mniej(int num, int od)
{
	double ret=(1.0*(min(od-1, tabd[num])-tabo[num]+1))/(1.0*(tabd[num]-tabo[num]+1));
	if (ret<0.0)
	ret=0.0;
	return ret;
}

double wiecej(int num, int od)
{
	double ret=(1.0*(tabd[num]-max(od+1, tabo[num])+1))/(1.0*(tabd[num]-tabo[num]+1));
	if (ret<0.0)
	ret=0.0;
	return ret;
}

double rowno(int num, int od)
{
	double ret=1.0-wiecej(num, od)-mniej(num, od);
	return ret;
}

int main()
{
	scanf("%d", &n);
	pot[0]=1;
	pot[1]=2;
	pot[2]=4;
	pot[3]=8;
	pot[4]=16;
	for (int i=0; i<n; i++)
	{
		m<<=1;
		scanf("%d%d", &tabo[i], &tabd[i]);
	}
	por[0]=1.0;
	mnie[0]=1.0;
	mniez[0]=0.0;
	for (int i=1; i<=10000; i++)
	{
		for (int j=1; j<m; j++)
		{
			roz=j;
			aktu=1.0;
			for (int l=0; l<n; l++)
			{
				if (roz[l])
				{
					aktu*=rowno(l, i);
				}
			}
			por[j]=aktu;
			aktu=1.0;
			for (int l=0; l<n; l++)
			{
				if (roz[l])
				{
					aktu*=mniej(l, i);
				}
			}
			mnie[j]=aktu;
		}
		for (int j=1; j<m; j++)
		{
			roz=j;
			aktu=0.0;
			for (int l=0; l<n; l++)
			{
				if (roz[l])
				{
					aktu+=wiecej(l, i)*mnie[j^pot[l]];
				}
			}
			mniez[j]=aktu;
			//printf("%d %d    %f %f %f\n", i, j, mnie[j], mniez[j], por[j]);
			//printf("    %d %f %f %f\n", j, mnie[j], mniez[j], por[j]);
		}
		aktu=0.0;
		for (int j=1; j<m; j++)
		{
			ile=0;
			roz=j;
			for (int l=0; l<n; l++)
			{
				if (roz[l])
				{
					ile++;
				}
			}
			if (ile==1)
			{
				aktu+=por[j]*mniez[(m-1)^j];
			}
			else
			{
				aktu+=por[j]*(mniez[(m-1)^j]+mnie[(m-1)^j]);
			}
			//printf(" %d %d   %d   %f\n", j, (m-1)^j, ile, aktu);
		}
		//printf("%d %f\n", i, aktu);
		wyn+=aktu*i;
	}
	printf("%.10f", wyn);
	return 0;
}