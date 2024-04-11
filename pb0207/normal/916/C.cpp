#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

int n,m;

ll np;

bool isprime(ll x)
{
	for(ll i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}

int main()
{
	cin>>n>>m;
	for(np=n;!isprime(np);np++);
	printf("%d %d\n",2,np);
	printf("%d %d %lld\n",1,n,2ll);
	if(n==2)
		return 0;
	for(int i=2;i<=n-2;i++)
		printf("%d %d %lld\n",1,i,1ll);
	printf("%d %d %lld\n",1,n-1,np-(n-1));
	int k=m-(n-1);
	if(k==0)
		return 0;
	for(int i=2;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			{
				printf("%d %d %lld\n",i,j,(ll)(1e9));
				k--;
				if(k==0)
					return 0; 
			}
}