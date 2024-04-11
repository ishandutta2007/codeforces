#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int ang[n];
	int s = 0;
	for(int i = 0;i<n;i++){
 		cin >> ang[i];
		s += ang[i];
	}
	int l = 0;
	int ans = s;
	for(int i = 0;i<n;i++){
		l = 0;
		for(int j = i;j<n;j++){
			l+=ang[j];
			ans = min(ans,abs((s-l)-l));
		}
	}
	cout << ans << "\n";
	return 0;
}