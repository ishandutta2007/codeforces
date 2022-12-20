#include <iostream>
#include <algorithm>
using namespace std;

int A[200000];
int B[200000];
int N,M;

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int j=0;j<M;j++)
		cin >> B[j];
	sort(A,A+N);
	for(int j=0;j<M;j++)
		cout << upper_bound(A,A+N,B[j])-A << ' ';
	cout << '\n';
}