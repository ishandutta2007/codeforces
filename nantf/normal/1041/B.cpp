#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,x,y,g,hmin,wmin;
ll gcd(ll x,ll y){
	if(!y) return x;
	return gcd(y,x%y);
}
ll calc(ll x,ll y){
	return y/gcd(x,y);
}
int main(){
	scanf("%I64d%I64d%I64d%I64d",&a,&b,&x,&y);
	g=gcd(x,y);hmin=y/g;wmin=x/g;
	printf("%I64d\n",min(a/wmin,b/hmin));
}