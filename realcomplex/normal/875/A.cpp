#include <bits/stdc++.h>

using namespace std;

int s(int n){
	int ans = 0;
	while(n>0){
		ans += n%10;
		n/=10;
	}
	return ans;
}

int main(){
	
	int n;
	cin >> n;
	vector<int>rez;
	for(int j = max(0,n-500);j<n;j++){
		if(j+s(j)==n )rez.push_back(j);
	}
	cout << rez.size() << "\n";
	for(auto x : rez) cout << x << "\n";
	return 0;
}