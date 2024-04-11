#include <bits/stdc++.h>

using namespace std;

int max2 = -1;
bool query(int l, int r){
	int L = min(l, max2);
	int R = max(r, max2);
	if(L == R) return false;
	cout << "? " << L << ' ' << R << endl;
	int ver; cin >> ver;
	return ver == max2;
}

int main(){
	int n; cin >> n;
	cout << "? " << 1 << ' ' << n << endl;
	cin >> max2;
	int l = 1, r = n;
	while(l != r){
		int m = (l + r) >> 1;
		if(l <= m && m <= max2){
			if(query(m + 1, r)){
				l = m + 1;
			}else{
				r = m;
			}
		}else{
			if(query(l, m)){
				r = m;
			}else{
				l = m + 1;
			}
		}
	}
	cout << "! " << (l == r ? l : l + r - max2) << endl;
}