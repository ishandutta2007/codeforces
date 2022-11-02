#include <bits/stdc++.h>

using namespace std;

int tL[300001][2], tR[300001][2];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n; string s;
		cin >> n >> s;
		tL[0][0] = tL[0][1] = 0;
		for(int i = 0; i < n; i++){
			tL[i + 1][0] = (s[i] == ((i % 2) ? 'L' : 'R') ? tL[i][0] + 1 : 0);
			tL[i + 1][1] = (s[i] == ((i % 2) ? 'R' : 'L') ? tL[i][1] + 1 : 0);
		}
		tR[n][0] = tR[n][1] = 0;
		for(int i = n - 1; i >= 0; i--){
			tR[i][0] = s[i] == ((n - 1 - i) % 2 ? 'R' : 'L') ? tR[i + 1][0] + 1 : 0;
			tR[i][1] = s[i] == ((n - i) % 2 ? 'R' : 'L') ? tR[i + 1][1] + 1 : 0;
		}
		for(int i = 0; i <= n; i++){
			int ans = tL[i][i % 2] + tR[i][((n - i) % 2)];
			cout << ans + 1 << ' ';
		}
		cout << endl;
	} 
}