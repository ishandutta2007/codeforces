#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int l = INT_MAX,r = INT_MIN;
	int k;
	for(int j = 0;j<n;j++){
		cin >> k;
		l = min(l,k);
		r = max(r,k);
	}
	int bl,br;
	bl = INT_MAX,br = INT_MIN;
	for(int j = 0;j<m;j++){
		cin >> k;
		bl = min(bl,k);
		br = max(br,k);
	}
	if(bl<=r||l*2>=bl) cout << -1;
	else{
		if(l*2<=r)cout << r;
		else cout << l*2;
	}
	cout << endl;
	return 0;
}