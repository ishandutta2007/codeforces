#include <iostream>
#include <iomanip>
using namespace std;

long double prob[2001][2001];	//[num on][time]


int main()
{
	int N;
	long double P;
	int T;
	cin >> N >> P >> T;
	prob[0][0] = 1;
	for(int i=1;i<=N;i++)
		prob[i][0] = 0;
	for(int t=1;t<=T;t++)
	{
		for(int i=0;i<=N;i++)
		{
			if(i==0) prob[i][t] = (1-P)*prob[i][t-1];
			else if(i==N) prob[i][t] = P*prob[i-1][t-1] + prob[i][t-1];
			else prob[i][t] = P*prob[i-1][t-1] + (1-P)*prob[i][t-1];
		}
	}
	long double tot = 0;
	for(int i=0;i<=N;i++)
		tot += i*prob[i][T];
	cout << setprecision(20) << tot << endl;
	return 0;
}