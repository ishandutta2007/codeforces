#include <stdio.h>
#include <stdlib.h>
bool isprime(int n){
	for(int i=2;i*i<=n;i++)if(n%i==0)return false;
	return true;
}
void f(int i){printf("%d\n",i);exit(0);}
int main(){
	int n;scanf("%d",&n);
	if(isprime(n))f(1);
	if(n%2==0)f(2);
	if(isprime(n-2))f(2);
	f(3);
}