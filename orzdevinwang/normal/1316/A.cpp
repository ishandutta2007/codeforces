#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
long long T,n,a,m,sum;
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		sum=0;
		for(int i = 1; i <= n; i++) scanf("%d",&a),sum+=a;
		printf("%lld\n",min(m,sum));
	}
}