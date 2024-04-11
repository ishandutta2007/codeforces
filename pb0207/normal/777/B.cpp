#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e3+1e2+7;

int n,ans1,ans2;

char a[N],b[N];

int main()
{
	cin>>n;
	scanf("%s",a);
	scanf("%s",b);
	sort(a,a+n);
	sort(b,b+n);
	int j=0;
	for(int i=0;i<n;i++)
		if(b[i]>a[j])
			j++;
	ans2=j;
	j=n-1;
	for(int i=n-1;i>=0;i--)
		if(b[j]>=a[i])
			j--;
	ans1=j+1;
	cout<<ans1<<endl<<ans2;
}