//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

bool isprime(int x){
	if(x <= 1) return false;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0) return false;
	return true;
}

int main(){
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int m = 1; m <= 1000; m++)
		if(!isprime(n * m + 1)){
			cout << m << endl;
			return 0;
		}
	return 0;
}