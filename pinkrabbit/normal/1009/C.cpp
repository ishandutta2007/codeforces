#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double

ll n,m;
int a[100001],b[100001];

int main(){
	ll sum=0;
	scanf("%lld%lld",&n,&m);
	while(m--){
		int x,d;
		scanf("%d%d",&x,&d);
		sum+=n*x;
		if(d>=0) sum+=(ll)d*n*(n-1)/2;
		else sum+=(ll)d*((ll)(n/2)*(n/2+1)/2 + ((n-1)/2)*((n-1)/2+1)/2);
	} printf("%.15lf",(ld)sum/n);
	return 0;
}