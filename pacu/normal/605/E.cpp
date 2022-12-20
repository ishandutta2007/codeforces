#include <iostream>
#include <iomanip>
using namespace std;

double p[1000][1000];

double numsum[1000],prod[1000],val[1000];
bool seen[1000];

int main()
{
	int N;
	cin >> N;
	int c;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin >> c;
			p[i][j] = ((double)c)/100.0;
		}
	}
	val[N-1] = 0, prod[N-1] = 1;
	for(int i=N-2;i>=0;i--)
		val[i] = 1000000000.0, prod[i] = 1;
	int cur;
	for(int i=0;i<N;i++)
	{
		cur = 0;
		for(int j=1;j<N;j++)
			if(!seen[j])
				if(val[j] < val[cur])
					cur = j;
		seen[cur] = 1;
		for(int k=0;k<N;k++)
		{
			if(seen[k]) continue;
			numsum[k] += prod[k]*p[k][cur]*(1+val[cur]);
			prod[k] *= (1-p[k][cur]);
			val[k] = (numsum[k]+prod[k])/(1-prod[k]);
		}
	}
	cout << setprecision(20) << val[0] << '\n';
}