#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>

using namespace std;

int n,a[200001],s[200001],la[32],p[200001];
map<int,int> ma;

int main() 
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=n; i++) 
	{
		for (int j=0; j<=30; j++) 
			if ((a[i]>>j)&1) la[j]=i;
			else p[i]=max(p[i],la[j]+1);
		p[i]=max(p[i],ma[a[i]]+1);
		ma[a[i]]=i;
	}
	for (int i=0; i<=30; i++) la[i]=n+1;
	for (int i=1; i<=n; i++) s[i]=n;
	long long ans=0;
	for (int i=n; i; i--) 
	{
		for (int j=0; j<31; j++)
			if ((a[i]>>j)&1) la[j]=i;
			else s[i]=min(s[i],la[j]-1);
		ans+=1ll*(s[i]-i+1)*(i-p[i]+1);
	}
	printf("%I64d\n",1ll*n*(n+1)/2-ans);
	return 0;
}