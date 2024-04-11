#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

using namespace std;

const int inf = -1u/2;
const int N = 5010;

bool dp1[N][N], dp2[N][N];
int dp3[N][N];
int mx1[N], mx2[N];

vector<int> idx1, idx2;
string s1, s2;

int lcp(string &s, int id1, int id2) {
	int ans = 0;
	while(id1 < s.length() and id2 < s.length() and s[id1] == s[id2]) {
		ans++;
		id1++;
		id2++;
	}
	return ans;
}
int main() {

	ios::sync_with_stdio(false);

	cin >> s1 >> s2;

	int n = s1.length(), m = s2.length();

	for(int i = n-1;i >= 0;i--) {
		for(int j = n-1;j >= i;j--) {
				if(i == j) dp1[i][j] = 0;
				else if(s1[i] != s1[j]) dp1[i][j] = s1[i] < s1[j];
				else if(j == n-1) dp1[i][j] = 0;
				else dp1[i][j] = dp1[i+1][j+1]; 
		}
	}

	for(int j = 0;j < n;j++) {
		for(int i = j+1;i < n;i++) {
			dp1[i][j] = !dp1[j][i];
		}
	}

	for(int i = 0;i < n;i++) idx1.push_back(i);
	sort(idx1.begin(), idx1.end(), [&] (int id1, int id2) {
		return dp1[id1][id2];
	});

	for(int i = m-1;i >= 0;i--) {
		for(int j = m-1;j >= i;j--) {
				if(i == j) dp2[i][j] = 0;
				else if(s2[i] != s2[j]) dp2[i][j] = s2[i] < s2[j];
				else if(j == m-1) dp2[i][j] = 0;
				else dp2[i][j] = dp2[i+1][j+1]; 
		}
	}

	for(int j = 0;j < m;j++) {
		for(int i = j+1;i < m;i++) {
			dp2[i][j] = !dp2[j][i];
		}
	}

	for(int i = 0;i < m;i++) idx2.push_back(i);
	sort(idx2.begin(), idx2.end(), [&] (int id1, int id2) {
		return dp2[id1][id2];
	});
	
	for(int i = 0;i < n;i++) {
		mx1[idx1[i]] = max((i > 0 ? lcp(s1, idx1[i], idx1[i-1]) : 0), (i+1 < n ? lcp(s1, idx1[i], idx1[i+1]) : 0)) + 1;
	}

	for(int i = 0;i < m;i++) {
		mx2[idx2[i]] = max((i > 0 ? lcp(s2, idx2[i], idx2[i-1]) : 0), (i+1 < m ? lcp(s2, idx2[i], idx2[i+1]) : 0)) + 1;
	}

	int ans = inf;
	for(int i = n-1;i >= 0;i--) {
		for(int j = m-1;j >= 0;j--) {
			if(s1[i] == s2[j]) {
				dp3[i][j] = 1 + dp3[i+1][j+1];
			}else {
				dp3[i][j] = 0;
			}
			int l = dp3[i][j];
			int r = max(mx1[i], mx2[j]);
			if(r <= l) {
				ans = min(ans, r);
			}
		}
	}

	if(ans == inf) ans = -1;
	cout << ans << "\n";

	return 0;
}