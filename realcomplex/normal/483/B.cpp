#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a,b,c,d;

bool can(ll k){
	ll X = k-(k/c);
	X += k-(k/d);
	X -= k-(k/(c*d));
	ll vi = (k-(k/c))-X;
	ll vj = (k-(k/d))-X;
	if(max(0LL,(a-vi))+max(0LL,(b-vj))<=X)return true;
	else return false;
}

int main(){
	cin >> a >> b >> c >> d;
	ll l = 0,r = 1e12;
	ll m;
	while(r-l>1){
		m = (l+r)/2;
		if(can(m))
			r = m;
		else 
			l = m;
	}
	cout << r << "\n";
	return 0;
}