#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll x,y;
	ll lx = INT_MAX,ly = INT_MAX;
	ll rx = INT_MIN,ry = INT_MIN;
	for(int j = 0;j<n;j++){
		cin >> x >> y;
		lx = min(lx,x);
		ly = min(ly,y);
		rx = max(rx,x);
		ry = max(ry,y);
	}
	cout << max(max(ry-ly,rx-lx)*max(ry-ly,rx-lx),ll(1));
	return 0;
}