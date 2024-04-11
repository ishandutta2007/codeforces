#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d%d",&a,&b);
		int d=__gcd(a,b);
		if(d==1){
			printf("Finite\n");
		}
		else{
			printf("Infinite\n");
		}
	}
 }