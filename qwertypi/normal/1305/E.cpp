#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int prec[5001];
int32_t main(){
	int n, k;
	cin >> n >> k;
	if(n == 1){
	    if(k == 0){
	        cout << 1 << endl;
	    }else{
	        cout << -1 << endl;
	    }
		return 0;
	}
	int _max = 0;
	for(int i = 3; i <= n; i++){
		prec[i] = prec[i - 1] + (i - 1) / 2;
	}
	if(k > prec[n]){
		cout << -1;
	}else{
		vector<int> ans;
		int i = 2;
		while(prec[i] < k){
			i++;
		}
		int z = 1000000000;
		for(int j = 0; j < n - i; j++){
			ans.push_back(z);
			z -= 20010;
		}
		for(int j = 1; j <= i - 1; j++){
			ans.push_back(j);
		}
		int left = k - prec[i - 1];
		int right = (i - 1) / 2 - left;
		ans.push_back(i + right * 2);
		sort(ans.begin(), ans.end());
		for(auto i : ans){
			cout << i << ' ';
		}
	}
}