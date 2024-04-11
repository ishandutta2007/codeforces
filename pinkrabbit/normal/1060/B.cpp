#include<bits/stdc++.h>
using namespace std;
#define LL long long
// from_luogu
LL n,A;
int F(LL x){
	int S=0;
	while(x) S+=x%10, x/=10;
	return S;
}

int main(){
	scanf("%lld",&n);
	while(A*10+9<=n) A=A*10+9;
	printf("%d",F(A)+F(n-A));
	return 0;
}