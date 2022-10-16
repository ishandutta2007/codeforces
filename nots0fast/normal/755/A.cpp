#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define forz(v) for(int z=0; z<v; z++)
#define mp(a,b) make_pair(a,b)
#define lli long long int
int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,1,-1,0,0};
int main()
{
	int m;
	cin>>m;
	for(int i=1; i<=1000; i++)
	{
		int eded = m*i+1;
		int kok = sqrt(eded);
		bool sade = true;
		for(int j=2; j<=kok; j++)
		{
			if(!(eded%j))
			{
				sade = false;
				j = kok+1;
			}
		}
		if(!sade)
		{
			cout<<i; return 0;
		}
	}
}