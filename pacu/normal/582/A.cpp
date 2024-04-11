#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int,int> M;

int C;
int B[250000];
int A[250000];
int N;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	cin >> N;
	for(int i=0;i<N*N;i++)
	{
		cin >> A[i];
		M[A[i]]++;
	}
	sort(A,A+N*N);
	C = 0;
	for(int i=N*N-1;i>=0;i--)
	{
		if(M[A[i]] > 0)
		{
			cout << A[i] << ' ';
			B[C++] = A[i];
			for(int j=0;j<C-1;j++)
			{
				M[gcd(A[i],B[j])]-=2;
			}
			M[A[i]]--;
		}
	}
	cout << '\n';
}