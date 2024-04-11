#include <bits/stdc++.h>
#define int long long 
using namespace std;

int C(int n, int r){
	if(n < r){
		return 0;
	}
	int res = 1;
	for(int i = r + 1; i <= n; i++){
		res *= i;
	}
	for(int i = 2; i <= n - r; i++){
		res /= i;
	}
	return res;
}

void sub(){
	map<int, int> S;
	int n;
	cin >> n;
	int i = 2;
	while(n != 0){
		S[n % i]++;
		n /= i;
		i++;
	}
	int ans = 1;
	int curMax = i - 1;
	for(auto ptr = S.rbegin(); ptr != S.rend(); ptr++){
		ans *= C(curMax - (ptr -> first != 0 ? ptr -> first : 1), ptr -> second);
		curMax -= ptr -> second;
	}
	if(S.find(0) != S.end()){
		int res = 1;
		curMax = i - 2;
		S[0]--;
		for(auto ptr = S.rbegin(); ptr != S.rend(); ptr++){
			res *= C(curMax - (ptr -> first != 0 ? ptr -> first : 1), ptr -> second);
			curMax -= ptr -> second;
		}
		ans -= res;
	}
	cout << ans - 1 << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}