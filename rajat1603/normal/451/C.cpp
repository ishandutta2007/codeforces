#include "bits/stdc++.h"
using namespace std;
int t;
long long n , k , d1 , d2;
bool solve(long long a , long long b , long long c){
	if(a + b + c > k){
		return 0;
	}
	if((k - (a + b + c)) % 3){
		return 0;
	}
	long long lft = n - k;
	long long tmp = max(a , max(b , c));
	lft -= tmp - a;
	lft -= tmp - b;
	lft -= tmp - c;
	if(lft >= 0 && lft % 3 == 0){
		return 1;
	}
	return 0;
}
int main(){
	scanf("%d" , &t);
	while(t--){
		scanf("%lld %lld %lld %lld" , &n , &k , &d1 , &d2);
		puts((solve(0 , d1 , d1 + d2) || solve(d2 - min(d1 , d2) , d1 + d2 - min(d1 , d2) , d1 - min(d1 , d2)) || solve(d1 , 0 , d2) || solve(d1 + d2 , d2 , 0)) ? "yes" : "no");
	}
}