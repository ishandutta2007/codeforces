#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pie;
typedef pair<LL, LL> ple;

#define PB push_back
#define MP make_pair
#define L first
#define R second

long long int n;

bool isprime(int x){
	if(x <= 1)
		return false;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}

ple solve(LL a, LL b){
	if(b == 0)
		return MP(1, 0);
	ple an = solve(b, a % b);
	ple ret;
	ret.L = an.R;
	ret.R = an.L - an.R * LL(a / b);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if(!isprime(n) and n != 4 and n != 1){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	if(n == 4){
		cout << 1 << endl
			<< 3 << endl
			<< 2 << endl
			<< 4 << endl;
		return 0;
	}
	cout << 1 << '\n';
	for(long long int i = 2; i < n; i++)
		cout << (i * (((solve(n, i - 1).R % n) + n) % n)) % n << '\n';
	cout << n << '\n';
	return 0;
}