#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p 1000000007
using namespace std;
typedef long long ll;

ll n, m, t;
ll g;

ll f(int x, ll y){
	if(x == 1){
		return (y - 1) / (n / g);
	}else{
		return (y - 1) / (m / g);
	}
}

int main(){
	cin >> n >> m >> t;
	g = __gcd(n, m);
	
	for(int Case = 0; Case < t; Case++){
		ll s1, v1, s2, v2;
		cin >> s1 >> v1 >> s2 >> v2;
		ll d1 = f(s1, v1);
		ll d2 = f(s2, v2);
		if(d1 == d2){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}