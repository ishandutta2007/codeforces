#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long a[100000];
int tn[51];
int n[50];
int e[50];
bool pos[100001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> a[i];
		int j = 0;
		while((1LL<<j) < a[i]) j++;
		if((1LL<<j) == a[i]) tn[j]++;
		else
		{
			if(j>0) j--;
			e[j]++;
		}
	}
	int sans = 0;
	for(int c=tn[0];c>0;c--)
	{
		for(int j=1;j<50;j++)
			if(tn[j] > tn[j-1])
			{
				e[j-1] +=tn[j] - tn[j-1];
				tn[j] = tn[j-1];
			}
		for(int j=0;j<50;j++)
			n[j] = tn[j] - tn[j+1];
		int numE = 0;
		for(int j=0;j<50;j++)
			numE += e[j];
		if(numE > tn[0])
			break;
		numE = 0;
		int numN = 0;
		bool good = 1;
		for(int j=39;j>=0;j--)
		{
			numE += e[j];
			numN += n[j];
			if(numE > numN) good = 0;
		}
		if(good)
			pos[c] = 1, sans++;
		tn[0]--;
		e[0]++;
	}
	for(int i=1;i<=N;i++)
		if(pos[i])
			cout << i << ' ';
	if(sans==0) cout << -1;
	cout << '\n';
}