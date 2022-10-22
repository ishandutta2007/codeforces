#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e6+1e3+7;

int n,k,a[N],s[N];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),s[a[i]]++;
	sort(a+1,a+n+1);
	for(int i=1;i<=(int)2e6;i++)
		s[i]+=s[i-1];
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(s[a[i]+k]-s[a[i]])
			cnt++;
	printf("%d",n-cnt);
}