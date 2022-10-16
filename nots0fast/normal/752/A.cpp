#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long int lli;
#define for_(z,v) for(int i=z; i<v; i++)
#define for__(z,v) for(int j=z; j<v; j++)
typedef long long int lli;
int main()
{
	int n, m ,k;
	cin>>n>>m>>k;
	int umumi = 2*n*m;
	int radlar = 2*m;
	int radsay = k/radlar;
	int qalan = k-radsay*radlar;
	int rad;
	int col ;
	char qaa ;
	rad=radsay;
	if(qalan)
	{
		++rad;
	}
	else
	{
		qalan+=2*m;
	}
		++qalan;
		col = qalan/2;
		--qalan;
		if((qalan%2))
		{
			qaa = 'L';
		}
		else
		{
			qaa='R';
		}
	cout<<rad<<" "<<col<<" "<<qaa;
}