#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int main()
{
	int n;
	long long int a;
	cin>>n;
	long long int sum=0; 
	for(int i=0;i<n;i++)
	{
		cin>>a;
		sum+=a;
	}
	int max=0,B[100000];
	for(int i=0;i<n;i++)
	{
		cin>>B[i];
		if(B[max]<B[i])
			max=i;
	}
	long long int smax=0;
	for(int i=0;i<n;i++)
	{
		if(i!=max&&B[i]>smax)
			smax=B[i];
	}
	smax+=B[max];
	if(smax<sum)
		cout<<"NO";
	else
		cout<<"YES";
}