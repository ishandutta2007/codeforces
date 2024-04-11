#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
#define pii pair<int,int>
using namespace std;
ll p[100];
int cnt;
int main()
{
	ll n;
	scanf("%lld",&n);
	if(n==1){
		printf("1");
		return 0;
	}
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0){
			p[cnt++]=i;
			while(n%i==0)n/=i;
		}
	}
	if(n>1)p[cnt++]=n;
	if(cnt>=2){
		printf("1");
	}
	else printf("%lld",p[0]);
}