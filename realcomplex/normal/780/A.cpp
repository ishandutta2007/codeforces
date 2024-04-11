#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int k;
	set<int>cur;
	int ans = 0;
	for(int j = 0;j<n*2;j++){
		cin >> k;
		if(cur.count(k) == 1){
			cur.erase(k);
		}
		else{
			cur.insert(k);
			ans = max(ans,int(cur.size()));
		}
	}
	cout << ans;
	cout << "\n";
	return 0;
}