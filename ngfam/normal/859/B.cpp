#include <bits/stdc++.h>

using namespace std;

int solve(int n, int ok = 0){

	int f = 0;
	while(f * f <= n){
		++f;
	}
	--f;

	int cur = f * 4;

	int rem = n - f * f;

	int ans = cur;


	for(int i = 1; i <= 4; ++i){
		int take = min(rem, f);

if(take > 0){		ans += 2;
		rem -= take;
		}
	}




	if(rem > 0){
		ans += rem * 2;
	}

	return ans;

}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int n;

	cin >> n;

	cout << solve(n, 1);

	return 0;
}