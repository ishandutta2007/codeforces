#include <iostream>
#include <algorithm>
using namespace std;

int A[100000];

int main()
{
	int N;
	long long sm = 0;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		sm += A[i];
	}
	long long bval = sm/N;
	long long ninc = sm%N;
	long long dif = 0;
	sort(A,A+N,greater<int>());
	for(int i=0;i<ninc;i++)
		dif += max(A[i]-(bval+1),(bval+1)-A[i]);
	for(int i=ninc;i<N;i++)
		dif += max(A[i]-bval,bval-A[i]);
	cout << dif/2 << '\n';
}