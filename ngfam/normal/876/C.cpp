#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int n;
	cin >> n; 

	vector < int > ans;

	for(int i = 0; i <= 100; ++i){
		int x = n - i;
		int totdigits = 0;

		while(x > 0){
			totdigits += x %  10;
			x /= 10;
		}

		if(totdigits == i){
			if(n - i != 0) ans.push_back(n - i);
		}
	}

	printf("%d\n", int(ans.size()));

	sort(ans.begin(), ans.end());

	for(int x : ans){
		printf("%d\n", x);
	}

	return 0;
}