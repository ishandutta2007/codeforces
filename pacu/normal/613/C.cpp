#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
int A[26];

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	cin >> N;
	int g = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		g = gcd(g,A[i]);
	}
	for(int i=0;i<N;i++)
		A[i] /= g;
	int numOdd = 0;
	for(int i=0;i<N;i++)
		if(A[i]%2==1)
			numOdd++;
	int ans = g;
	if(numOdd > 1)
	{
		if(g%2 == 1)
		{
			cout << 0 << '\n';
			for(int i=0;i<N;i++)
				for(int j=0;j<A[i]*g;j++)
					cout << (char)('a'+i);
			cout << '\n';
			return 0;
		}
		else
		{
			g /= 2;
			for(int i=0;i<N;i++)
				A[i] *= 2;
			numOdd = 0;
		}
	}
	cout << ans << '\n';
	for(int i=0;i<g;i++)
	{
		for(int j=0;j<N;j++)
			if(A[j]%2 == 0)
				for(int k=0;k<A[j]/2;k++)
					cout << (char)('a'+j);
		for(int j=0;j<N;j++)
			if(A[j]%2 == 1)
				for(int k=0;k<A[j];k++)
					cout << (char)('a'+j);
		for(int j=N-1;j>=0;j--)
			if(A[j]%2 == 0)
				for(int k=0;k<A[j]/2;k++)
					cout << (char)('a'+j);
	}
	cout << '\n';
}