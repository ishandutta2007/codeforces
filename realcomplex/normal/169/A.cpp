#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	swap(a,b);
	int chores[n];
	for(int j = 0;j<n;j++){
		cin >> chores[j];
	}
	sort(chores,chores+n);
	int ans = 0;
	for(int j = 1;j<n;j++){
		if(chores[j]==chores[j-1])continue;
		if(j==a){
			ans += chores[j]-chores[j-1];
		}
	}
	cout << ans << endl;
	return 0;
}