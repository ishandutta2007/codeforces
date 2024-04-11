#include <iostream>
using namespace std;
#define MOD 1000000007

int A[100000];
int N;

int occ[100001];
int mult[100001];
int pw[100001];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		occ[A[i]]++;
	}
	pw[0] = 1;
	for(int i=1;i<=100000;i++)
		pw[i] = (2*pw[i-1])%MOD;
	for(int i=1;i<=100000;i++)
	{
		for(int j=i;j<=100000;j+=i)
			mult[i] += occ[j];
		mult[i] = (pw[mult[i]]+MOD-1)%MOD;
	}
//	cout << mult[1] << ' ' << mult[2] << ' ' << mult[3] << '\n';
	for(int i=100000;i>=1;i--)
		for(int j=2*i;j<=100000;j+=i)
			mult[i] = (mult[i] + MOD - mult[j])%MOD;
	cout << mult[1] << '\n';
}