#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>ans;
	for(int j = 2;j<=n;j+=2)ans.push_back(j);
	for(int j = 1;j<=n;j+=2)ans.push_back(j);
	for(int j = 2;j<=n;j+=2)ans.push_back(j);
	cout << ans.size() << "\n";
	for(auto x : ans)cout << x << " ";
	return 0;
}