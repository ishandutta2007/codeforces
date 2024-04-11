#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,n1,n2,a[N];

long long s1,s2;

double ans1,ans2;

int main()
{
	cin>>n>>n1>>n2;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n1>n2)
		swap(n1,n2);
	for(int i=n;i>=n-n1+1;i--)
		s1+=1ll*a[i];
	for(int i=n-n1;i>=n-n1-n2+1;i--)
		s2+=1ll*a[i];
	ans1=(double)s1/(double)n1;
	ans2=(double)s2/(double)n2;
	printf("%.10lf",ans1+ans2);
}