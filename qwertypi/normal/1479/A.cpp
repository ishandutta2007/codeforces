#include <bits/stdc++.h>

using namespace std;

int query(int x){
	cout << "? " << x << endl;
	int v; cin >> v;
	return v;
}
int main(){
	int n;
	cin >> n;
	int ans = 1;
	for(int l = 1, r = n, m = (l + r) / 2; l != r; m = (l + r) / 2){
		if(query(m) < query(m + 1)){
			r = m;
		}else{
			l = m + 1;
		}
		ans = l; 
	}
	cout << "! " << ans << endl;
}