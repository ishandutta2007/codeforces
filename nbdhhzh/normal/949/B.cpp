#include<bits/stdc++.h>
using namespace std;
long long n,x,y,z,X;
int q;
int main(){
	scanf("%I64d%d",&n,&q);
	while(q--){
		scanf("%I64d",&x);
		y=n;z=0;
		for(;!(x&1);){
			y=y+x/2-z;
			z=x/2;
			x=y;
		}
		printf("%I64d\n",x+1>>1);
	}
}