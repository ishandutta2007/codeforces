#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

int main(){
	ll d,k,a,b,t;
	cin >> d >>k >> a >> b >> t;
	ll c = (d-1)/k;
	if(d < k){
		cout << d*a;
	}
	else if(k*b <= t+k*a){
		cout << k*a + (d-k) * b;
	}
	else{
		if(d%k == 0){
			cout << d*a + t*c;
		}
		else{
			ll r = d-(d%k);
			ll v = (c-1) * t + a * r;
			v += min((d%k) * b,(d%k) * a + t);
			cout << v;
		}
	}
	cout << "\n";
	return 0;
}