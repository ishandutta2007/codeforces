#include <bits/stdc++.h>
 
// !!!!!!!!!!!
// Last Div 2!
// Hope so.
// !!!!!!!!!!!
 
 
using namespace std;
 
int A[100001][2];
 
int dp[1001][1001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i][0] >> A[i][1];
        int v = A[i][0] * A[i][0] + A[i][1] * A[i][1];
    	int sq = sqrt(v);
    	if(A[i][0] + A[i][1] == 0){
    		cout << 0 << endl;
    	}else if(sq * sq == v){
    		cout << 1 << endl;
    	}else{
    		cout << 2 << endl;
    	}
	}
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}