#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)

using namespace std;

typedef long long  int ll;
typedef pair<int,int> pll;

const long long int N=4e2+30,mod = 1e9+7,inf=1e18;
const long double eps = 0.0001;
bool val(ll n){
	ll n1 = n;
	while (n1){
		int d = n1%10;
		n1/=10;
		if (!d) continue;
		if (n%d) return 0;
	}
	return 1;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		ll n;
		cin >> n;
		rep(i,0,3000){
			if (val(n+i)){
				cout << n+i <<endl;
				break;
			}
		}
	}
    return 0;
}