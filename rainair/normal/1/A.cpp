/*User:Rain Air
ID: 001
*/

#include <iostream>
#include <cstdio>
#include <cstring>

int main(){
	long long n,m,a;
	scanf("%lld%lld%lld",&n,&m,&a);
	printf("%lld",((n+a-1)/a)*((m+a-1)/a));
	return 0;
}