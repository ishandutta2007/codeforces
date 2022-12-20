#include <iostream>
using namespace std;

int main()
{
	int A,B,N;
	cin >> A >> B;
	N = A+B+1;
	for(int i=(N-A);i<=N;i++)
		cout << i << " ";
	for(int i=(N-A-1);i>0;i--)
		cout << i << " ";
	return 0;
}