#include <iostream>
using namespace std;

long long start[100000];
long long tm[100000];

int main()
{
	long long n[3];
	long long t[3];
	long long N;
	cin >> n[0] >> n[1] >> n[2];
	cin >> t[0] >> t[1] >> t[2];
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> start[i];
		tm[i] = start[i];
	}
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<N;i++)
		{
			if(i<n[j]) tm[i] = tm[i] + t[j];
			else tm[i] = max(tm[i-n[j]],tm[i]) + t[j];
		}
	}
	long long mx = 0;
	for(int i=0;i<N;i++)
		mx = max(mx,tm[i]-start[i]);
	cout << mx << endl;
}