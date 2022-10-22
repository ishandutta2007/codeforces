#include<bits/stdc++.h>
using namespace std;
inline long long gcd(long long a,long long b){
	if(b){
		return gcd(b,a%b);
	}else return a;
}
int main(){
	long long a,b,c,n,t;
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		b=b/gcd(b,a);
		t=c;
		while(b!=1&&t!=1){
			t=gcd(t,b);
			b/=t;
		}
		if(b==1){
			printf("Finite\n");
		}else printf("Infinite\n");
	}
	return 0;
}