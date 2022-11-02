#include <bits/stdc++.h>
 
using namespace std;
 
int A[300001];
map<int, int> S;
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		S[abs(A[i])]++;
	}
	
	int ans = 0;
	for(auto i : S){
	    // gray ppl fail A
	    if(i.first != 0) ans += min(i.second, 2);
	    else ans++;
	}
	cout << ans << endl;
	S.clear();
}
 
int main(){
	int q;
	cin >> q;
	while(q--){
		solve();
	}
}