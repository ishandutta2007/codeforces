#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n;

	vector < pair < int, int > > ans;

	for(int a = n; a >= 1; --a){
		int b = n - a;
		if(b < a){
			continue;
		}
		if(__gcd(a, b) == 1){
			ans.push_back(make_pair(a, b));
		}
	}

	pair < int, int > x = ans.back();


	for(int i = ans.size() - 2; i >= 0; --i){
		pair < int, int > c = ans[i];

		if(c.first * x.second > x.first * c.second){
			x = c;
		}
	}

	cout << x.first << " " << x.second << endl;

	return 0;
}