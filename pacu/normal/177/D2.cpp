#include <iostream>
using namespace std;

long long A[100000];
long long B[100000];
int N,M,C;

int main()
{
	cin >> N >> M >> C;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<M;i++)
		cin >> B[i];
	int a = 0;
	int b = M-N-1;
	long long s = 0;
	for(int i=0;i<N;i++)
	{
		if(a<M) s += B[a];
		if(b>=0) s -= B[b];
		a++,b++;
		cout << (A[i]+s)%C << " ";
	}
	cout << "\n";
	return 0;
}