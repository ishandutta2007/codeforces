#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int a[N*4],s[N*4],n,b[N*4];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i*2-1]>>a[i*2],b[i*2]=a[i*2],b[i*2-1]=a[i*2-1];
	sort(a+1,a+n*2+1);
	for(int i=1;i<=n;i++)
	{
		int l=lower_bound(a+1,a+n*2+1,b[i*2-1])-a,r=lower_bound(a+1,a+n*2+1,b[i*2])-a;
		s[l]++,s[r+1]--;
	}
	for(int i=1;i<=400000;i++)
		s[i]+=s[i-1];
	for(int i=1;i<=400000;i++)
		if(s[i]>2)
		{
			cout<<"NO";
			exit(0);
		}
	cout<<"YES";
}