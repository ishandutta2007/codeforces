#include <iostream>
using namespace std;

int a[102];
int b[102];

int main()
{
	int N,M;
	cin >> N;
	for(int i=0;i<=101;i++)
		a[i] = b[i] = 0;
	for(int i=0;i<N;i++)
	{
		int k;
		cin >> k;
		a[k]++;
	}
	cin >> M;
	for(int i=0;i<M;i++)
	{
		int k;
		cin >> k;
		b[k]++;
	}
	int count = 0;
	for(int i=1;i<=100;i++)
	{
		while(a[i]&&b[i-1])
		{
			a[i]--;
			b[i-1]--;
			count++;
		}
		while(a[i]&&b[i])
		{
			a[i]--;
			b[i]--;
			count++;
		}
		while(a[i]&&b[i+1])
		{
			a[i]--;
			b[i+1]--;
			count++;
		}
	}
	cout << count << endl;
}