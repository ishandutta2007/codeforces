#include <iostream>
using namespace std;

int A[200000];
int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	long long ans = 0;
	int cntRight = 0;
	for(int i=0;i<N;i++)
	{
		if(A[i]==1)
			cntRight++;
		else
			ans += cntRight;
	}
	int cntLeft = 0;
	for(int i=(N-1);i>=0;i--)
	{
		if(A[i]==0)
			cntLeft++;
		else
			ans += cntLeft;
	}
	cout << ans/2 << endl;
}