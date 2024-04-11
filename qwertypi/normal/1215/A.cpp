#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first

using namespace std;
int main(){
	int a1, a2, x1, x2, n;
	cin >> a1 >> a2 >> x1 >> x2 >> n;
	int k = n;
	int _min, _max;
	if(x1 > x2){
		if(n >= x2 * a2){
			n -= x2 * a2;
			_max =  a2 + min(a1, n / x1);
		}else{
			_max =  n / x2;
		}
	}else{
		if(n >= x1 * a1){
			n -= x1 * a1;
			_max =  a1 + min(a2, n / x2);
		}else{
			_max =  n / x1;
		}
	}
	k -= (x1 - 1) * a1 + (x2 - 1) * a2;
	if(k <= 0){
		_min = 0;
	}else{
		_min = k;
	}
	cout << _min << ' ' << _max << endl;
	return 0;
}