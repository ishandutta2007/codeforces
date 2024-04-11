#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())

ll calc_len(int x){
	ll len = 0;
	while(x > 0){
		x/=10;
		len++;
	}
	return len;
}

int main(){
	fastIO;
	ll n;
	cin >> n;
	if(n <= 4){
		cout << (n * (n-1))/2; 
		return 0;
	}
	ll ans_len = calc_len(n * 2);
	ans_len--;
	ll r = 1;
	ll nine = 0;
	for(int i = 1;i<=ans_len;i++){
		nine += r * 9;
		r *= 10;
	}
	ll x;
	ll ans = 0;
	ll l;
	ll v;
	for(ll j = 0;j<9;j++){
		x = r*j + nine;
		if(n >= x){
			ans += x/2; // ways
		}
		else{
			v = x/2;
			ans += max(0LL,n-v);
			
		}
	}
	cout << ans;
	return 0;
}