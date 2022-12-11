#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int cnt[n][n];
	char s;
	for(int j = 0;j<n;j++){
		for(int i = 0;i<n;i++){
			cin >> s;
			if(s=='.')cnt[j][i]=0;
			else cnt[j][i] = 1;
		}
	}
	int p;
	int ans = 0;
	for(int i = 0;i<n;i++){
		p = 0;
		for(int j = 0;j<n;j++)p+=cnt[i][j];
		ans += (p*(p-1))/2;
	}
	for(int j = 0;j<n;j++){
		p = 0;
		for(int i = 0;i<n;i++){
			p += cnt[i][j];
		}
		ans += (p*(p-1))/2;
	}
	cout << ans;
	return 0;
}