#include <iostream>
using namespace std;

long long sat[1<<18][18];
int pcnt[1<<18];

int N,M,K;
long long A[18];
long long C[18][18];

int main()
{
	cin >> N >> M >> K;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int x,y,c;
	for(int i=0;i<K;i++)
	{
		cin >> x >> y >> c;
		C[x-1][y-1] = c;
	}
	pcnt[0] = 0;
	for(int i=1;i<(1<<N);i++)
		pcnt[i] = 1+pcnt[i-(i&-i)];
	long long best = 0;
	for(int i=0;i<N;i++)
		sat[1<<i][i] = A[i];
	for(int j=1;j<(1<<N);j++)
	{
		for(int k=0;k<N;k++)
		{
			if(!(j&(1<<k))) continue;
			if(pcnt[j]<=M)
				best = max(best,sat[j][k]);
			for(int l=0;l<N;l++)
				if(!(j&(1<<l)))
					sat[j|(1<<l)][l] = max(sat[j|(1<<l)][l],sat[j][k]+C[k][l]+A[l]);
		}
	}
	cout << best << '\n';
}