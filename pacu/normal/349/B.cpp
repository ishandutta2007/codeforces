#include <iostream>
using namespace std;

int A[9];
int v;

int main()
{
	cin >> v;
	int low = 100000;
	for(int i=0;i<9;i++)
	{
		cin >> A[i];
		low = min(A[i],low);
	}
	int dig = v/low;
	if(dig==0)
	{
		cout << -1 << endl;
		return 0;
	}
	int rem = v%low;
	for(int i=0;i<9;i++)
		A[i] -= low;
	int d;
	for(int i=0;i<dig;i++)
	{
		for(d=8;d>=0;d--)
			if(A[d] <= rem)
				break;
		cout << d+1;
		rem -= A[d];
	}
	cout << endl;
	return 0;
}