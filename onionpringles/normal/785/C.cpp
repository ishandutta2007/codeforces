#include  <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll sq(ll n){
	ll l=0,r=2012345678;
	while(l!=r){
		ll m=(l+r)/2;
		if(m*(m+1)/2 >= n)r=m;
		else l=m+1;
	}
	return l;
}
int main(){
	ll a,b;scanf("%lld%lld",&a,&b);
	if(a<=b)return !printf("%lld\n",a);
	else printf("%lld\n",b+sq(a-b));
}