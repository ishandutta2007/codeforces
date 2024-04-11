#include <iostream>
#include <map>

#define SIGMA 26

using namespace std;

map<int, map<long long, int> > dp;

long long x[SIGMA];
string str;

int main() {
	for(int i = 0;i < SIGMA;i++) {
		cin >> x[i];
	}
	cin >> str;
	long long sum = 0, ans = 0;
	for(int i = 0;str[i];i++) {
		if(i > 0) {
			if(dp[str[i]].find(sum) != dp[str[i]].end()) {
				ans += dp[str[i]][sum];
			}
		}
		sum += x[str[i]-'a'];
		dp[str[i]][sum]++;
	}
	cout << ans << endl;
	return 0;
}