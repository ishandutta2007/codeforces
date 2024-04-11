#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
long long m;
vector <int> pocz;
vector <int> kon; 
long long k=1;

int main()
{
	scanf("%d%lld", &n, &m);
	for (int i=1; i<n; i++)
	k*=2;
	for (int i=1; i<n; i++)
	{
		if (m<=(k>>1))
		{
			pocz.push_back(i);
		}
		else
		{
			kon.push_back(i);
			m-=(k>>1);
		}
		k>>=1;
	}
	for (int i=0; i<pocz.size(); i++)
	printf("%d ", pocz[i]);
	printf("%d ", n); 
	for (int i=kon.size()-1; i>=0; i--)
	printf("%d ", kon[i]);
	return 0;
}