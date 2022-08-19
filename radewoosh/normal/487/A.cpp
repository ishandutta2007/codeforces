#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int hpc, ac, dc;
int hpm, am, dm;
int hpk, ak, dk;
int wyn=1000000000;
int ilec;
int ileh;

int main()
{
	scanf("%d%d%d", &hpc, &ac, &dc);
	scanf("%d%d%d", &hpm, &am, &dm);
	scanf("%d%d%d", &hpk, &ak, &dk);
	for (int i=max(0, dm-ac+1); i<=200; i++)
	{
		for (int j=0; j<=100; j++)
		{
			ilec=hpm/((ac+i)-dm);
			if (hpm%((ac+i)-dm))
			ilec++;
			ileh=max(ilec*(am-dc-j)-hpc+1, 0);
			wyn=min(wyn, i*ak+dk*j+ileh*hpk);
		}
	}
	printf("%d", wyn);
	return 0;
}