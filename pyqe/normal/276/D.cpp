#include <bits/stdc++.h>

using namespace std;

long long lb,rb;

int main()
{
	long long i;
	
	scanf("%lld%lld",&lb,&rb);
	for(i=59;i+1&&(lb>>i&1)==(rb>>i&1);i--);
	printf("%lld\n",(1ll<<i+1)-1);
}