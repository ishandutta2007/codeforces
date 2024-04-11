#include <iostream>
#include <iomanip>
using namespace std;

int N,M;

int kl[100];

double prob[100001][2];	//probability of receiving this score after so many events

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> kl[i];
	if(M==1)
	{
		cout << 1 << '\n';
		return 0;
	}
	int cur = 1;
	int prev = 0;
	prob[0][0] = 1;
	for(int i=1;i<=N*M;i++)
		prob[i][0] = 0;
	for(int e=0;e<N;e++,swap(cur,prev))
	{
		prob[0][cur] = 0;
		for(int k=1;k<=N*M;k++)
		{
			prob[k][cur] = prob[k-1][cur];
			prob[k][cur] += prob[k-1][prev];
			if(k-M-1 >= 0)
				prob[k][cur] -= prob[k-M-1][prev];
		}
		for(int k=1;k<=N*M;k++)
		{
			if(k >= kl[e])
				prob[k][cur] -= prob[k-kl[e]][prev];
			prob[k][cur] /= (double)(M-1);
		}
	}
	int kscore = 0;
	for(int i=0;i<N;i++)
		kscore += kl[i];
	double exprank = 0;
	for(int k=1;k<kscore;k++)
		exprank += prob[k][prev];
	exprank *= M-1;
	exprank++;
	cout << fixed << setprecision(20) << exprank << '\n';
}