#include <stdio.h>
#define MA 50000

bool isPrime[MA+5];

bool _isPrime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}

void solve(){
	int d;
	scanf("%d",&d);
	int d1 = d+1;
	while(!isPrime[d1]) d1++;
	int d2 = d1+d;
	while(!isPrime[d2]) d2++;
	printf("%d\n",d1*d2);
}

int main(){
	for(int i=2;i<=MA;i++)
		isPrime[i] = _isPrime(i);
	int T; scanf("%d",&T);
	while(T--) solve();
}