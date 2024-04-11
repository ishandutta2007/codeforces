#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e3+1e2+7;

int n,k;

double a[N],ave;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],ave+=a[i];
	int cnt=0;
	while(ave/(double)n<(double)(k)-0.5)
	{
		ave+=k;
		n++;
		cnt++;
	}
	cout<<cnt;
}