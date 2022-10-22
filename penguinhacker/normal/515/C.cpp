#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, cnt[4], nums[4]={2, 3, 5, 7};
string s, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (char c : s) {
		int i=c-'0';
		cnt[0]+=i/2+i/4+i/8;
		cnt[1]+=i/3+i/9;
		cnt[2]+=i/5;
		cnt[3]+=i/7;
	}

	for (int i=3; ~i; --i) {
		int j=nums[i];
		while(cnt[i]) {
			ans.push_back('0'+nums[i]);
			cnt[0]-=j/2+j/4+j/8;
			cnt[1]-=j/3+j/9;
			cnt[2]-=j/5;
			cnt[3]-=j/7;
		}
	}
	cout << ans;
	return 0;
}