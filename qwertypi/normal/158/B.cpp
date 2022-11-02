#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int cnt[5];
int main(){
	fill(cnt, cnt+5, 0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		cnt[t]++;
	}
	int ans = 0;
	ans += cnt[4];
	cnt[4] = 0;
	int del = min(cnt[3], cnt[1]);
	ans += del;
	cnt[3] -= del;
	cnt[1] -= del;
	if(cnt[3]){
		ans += cnt[3];
		cnt[3] = 0;
	}
	ans += cnt[2] / 2;
	cnt[2] %= 2;
	if(cnt[2] && cnt[1] >= 2){
		ans++;
		cnt[2] = 0;
		cnt[1] -= 2;
	}
	if(cnt[2] && cnt[1] < 2){
		cnt[2] = cnt[1] = 0;
		ans++;
	}
	ans += (cnt[1] + 3) / 4;
	cout << ans;
	return 0;
}