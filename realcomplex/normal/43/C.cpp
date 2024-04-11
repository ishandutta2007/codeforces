#include <bits/stdc++.h>

using namespace std;

int cnt[3];

int main(){
	int n;
	cin >> n;
	int sk;
	for(int j = 0;j<n;j++){
		cin >> sk;
		cnt[sk%3]++;
	}
	int ans = cnt[0]/2;
	ans += min(cnt[1],cnt[2]);
	cout << ans << endl;
	return 0;
}