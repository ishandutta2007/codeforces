#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int n,a[301];

int main()
{
	cin>>n;
	for(int i=1;i<=n*2;i++)
		cin>>a[i];
	sort(a+1,a+n*2+1);
	if(a[n]<a[n+1])
		cout<<"YES";
	else
		cout<<"NO";
}