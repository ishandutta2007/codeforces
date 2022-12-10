#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL n;

bool isprime(int x){
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}

int main(){
	int t;
	cin >> t;
	while(t--){
	cin >> n;
		if(isprime(n)){
			LL p = n + 1;
			while(!isprime(p)) p++;
			LL soor = p * n - 2 * p + 2;
			LL makh = 2 * n * p;
			LL gcd = __gcd(soor, makh);
			cout << soor / gcd << '/' << makh / gcd << '\n';
		}
		else{
			LL p1 = n - 1;
			LL p2 = n + 1;
			while(!isprime(p1))
				p1--;
			while(!isprime(p2))
				p2++;
			LL soor = p1 * p2 - 2 * p2 + 2 * (n - p1 + 1);
			LL makh = 2 * p1 * p2;
			LL gcd = __gcd(soor, makh);
			cout << soor / gcd << '/' << makh / gcd << '\n';
		}
	}
}