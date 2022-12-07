#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long int maxm(long long int m1,long long int m2,long long int m3,long long int m4)
{
	long long int man[4] = {m1,m2,m3,m4};
	sort(man,man+4);
	return man[3];
}

int main()
{
	int n,m;
	cin>>n>>m;
	long long int little[n], big[m];
	for(int i=0;i<n;i++)
	{
		long long int k;
		cin>>k;
		little[i]=k;
	}
	for(int i=0;i<m;i++)
	{
		long long int k;
		cin>>k;
		big[i]=k;
	}
	sort(little,little+n);
	sort(big,big+m);
	long long int m1 = little[n-1]*big[m-1];
	long long int m2 = little[0]*big[0];
	long long int m3 = little[0]*big[m-1];
	long long int m4 = little[n-1]*big[0];
	long long int max = maxm(m1,m2,m3,m4);
	if(max==m1||max==m4)
	{
		m1 = little[n-2]*big[m-1];
		m4 = little[n-2]*big[0];
		max = maxm(m1,m2,m3,m4);
	}
	else
	{
		m2 = little[1]*big[0];
		m3 = little[1]*big[m-1];
		max = maxm(m1,m2,m3,m4);
	}
	cout<<max<<endl;
	return 0;
}