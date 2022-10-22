#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd (ll a,ll b){
	if(!b){
		return a;
	}else{
		return gcd(b,a%b);
	}
}
int main(){
	ll a,b,x,y,t;
	cin>>a>>b;
	t=a*b/gcd(a,b);
	x=t/a-1;y=t/b-1;
	if(x-y>1){
		puts("Dasha");
	}else if(y-x>1){
		puts("Masha");
	}else puts("Equal");
	return 0;
}