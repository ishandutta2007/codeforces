#include <iostream>
using namespace std;

int N;
int A[100001];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<N;i++)
		cout << A[i]+A[i+1] << ' ';
	cout << '\n';
}