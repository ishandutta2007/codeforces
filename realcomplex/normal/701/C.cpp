#include <bits/stdc++.h>

using namespace std;

int k = 0;

main(){
	int n;
	cin >> n;
	char v[n];
	cin >> v;
	map<int,int>cnt;
	int k = 0;
	for(int j = 0;j<n;j++)
		if(cnt[v[j]] == 0){
			k++;
			cnt[v[j]]++;
		}
	cnt.clear();
	int ans = INT_MAX;
	int p = 0;
	int c = 0;
	for(int j = 0;j<n;j++){
		cnt[v[j]]++;
		if(cnt[v[j]] == 1){
			c++;
		}
		while(cnt[v[p]] > 1){
			cnt[v[p]]--;
			p++;
		}
		if(c == k)ans = min(ans,j-p+1);
	}
	cout << ans;
}