#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[120][5];

int M;
int correct[5];
int points[5];

bool getScores()
{
	int dif = 0;
	for(int i=0;i<5;i++)
	{
		if(correct[i]*2 > M) points[i] = 500;
		else if(correct[i]*4 > M) points[i] = 1000;
		else if(correct[i]*8 > M) points[i] = 1500;
		else if(correct[i]*16 > M) points[i] = 2000;
		else if(correct[i]*32 > M) points[i] = 2500;
		else points[i] = 3000;
		if(a[0][i]!=-1) dif += points[i] - (points[i]*a[0][i])/250;
		if(a[1][i]!=-1) dif -= points[i] - (points[i]*a[1][i])/250;
	}
	return (dif>0);
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		for(int j=0;j<5;j++)
		{
			cin >> a[i][j];
			if(a[i][j] != -1) correct[j]++;
		}
	M = N;
	if(getScores())
	{
		cout << 0 << '\n';
		return 0;
	}
	for(M = N+1; M <= N + 120*33; M++)
	{
		for(int i=0;i<5;i++) if(a[0][i]!=-1)
		{
			if(a[1][i]!=-1 && a[1][i] < a[0][i]) correct[i]++;
		}
		if(getScores())
		{
			cout << M-N << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}