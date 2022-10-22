#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

long long n,a[N],b[N],sum;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum+=a[i];	
	for(int i=1;i<=n;i++)
		cin>>b[i];
	sort(b+1,b+n+1);
	long long k=b[n]+b[n-1];
	if(sum<=k)
		puts("Yes");
	else
		puts("No");
}