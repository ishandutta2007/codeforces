#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n,k,l,a[N];

int main()
{
	scanf("%d%d%d",&n,&k,&l);
	for(int i=1;i<=n*k;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n*k+1);
	int N=n*k,tmp=0;
	ll ans=0;
	for(int i=N;i>=1;i--)
	{
		if(a[i]>a[1]+l||tmp<k-1)
			tmp++;
		else 
			tmp-=k-1,ans+=a[i];
	}
	printf("%lld",tmp>0?0:ans);
}
/*
3 2 2
1 2 3 4 5 6
*/