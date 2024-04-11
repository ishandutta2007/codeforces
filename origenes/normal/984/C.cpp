#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
	return !b?a:gcd(b, a%b);
}
bool check(ll q, ll b){
	ll d=gcd(q, b);
	while(d>1){
		while(q%d==0) q/=d;
		d=gcd(q, b);
	}
	return q==1;
}
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
	ll n, p, q, b;
	scanf("%I64d", &n);
	while(n--){
		scanf("%I64d%I64d%I64d", &p, &q, &b);
		if(!p){
			puts("Finite");
			continue;
		}
		ll d=gcd(p, q);
		q/=d;
		if(check(q, b)) puts("Finite");
		else puts("Infinite");
	}
	return 0;
}