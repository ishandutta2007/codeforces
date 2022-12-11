#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	vector<int>t(n);
	for(int i = 0;i<n;i++){
		cin >> t[i];
	}
	sort(t.begin(),t.end());
	int am = 0;
	while(t.size() > 0){
		if(k*2 >= t[0]){
			if(t[0] > k){
				k = t[0];
			}
			t.erase(t.begin());
		}
		else{
			while(k*2 < t[0]){
				k*=2;
				am++;
			}
			if(t[0] > k){
				k = t[0];
			}
			t.erase(t.begin());
		}
	}
	cout << am;
	return 0;
}