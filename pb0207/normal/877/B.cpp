#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=5e3+1e2+7;

char s[N];

int n,ans,a[N],b[N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n+1;i++)
		a[i]=a[i-1]+(s[i]=='a'),b[i]=b[i-1]+(s[i]=='b');
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			ans=max(ans,a[i]+(b[j]-b[i])+(a[n+1]-a[j]));
		}
	printf("%d",ans); 
}