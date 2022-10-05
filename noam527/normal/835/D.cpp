#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define last(X) (X)[(X).size() - 1]
#define last(x, y) (x)[(x).size() - y]
typedef long long ll;
using namespace std;

string s;
vector<vector<bool>> isp(5000, vector<bool>(5000));
vector<vector<vector<bool>>> dp(2, vector<vector<bool>>(5000, vector<bool>(5000)));

int output[5000];

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

void preprocess() {
	for (int i = 0; i < s.size(); i++) output[i] = 0;
	output[0] += s.size();
	for (int i = 0; i < s.size(); i++) for (int j = 0; j < s.size(); j++) isp[i][j] = false;
	for (int i = 0; i < s.size(); i++) isp[i][i] = true;
	for (int i = 0, x; i < s.size(); i++) {
		x = 1;
		while (i - x >= 0 && i + x < s.size() && s[i - x] == s[i + x]) isp[i - x][i + x] = true, x++, output[0]++;
		x = 1;
		while (i - x + 1 >= 0 && i + x < s.size() && s[i - x + 1] == s[i + x]) isp[i - x + 1][i + x] = true, x++, output[0]++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin >> s;
	preprocess();
	for (int i = 0; i + 1 < s.size(); i++) {
		for (int j = i + 1; j < s.size(); j++) {
			if (isp[i][j] && isp[i][(i + j - 1) / 2] && isp[(i + j + 2) / 2][j]) dp[0][i][j] = true, output[1]++;
			else dp[0][i][j] = false;
		}
	}
	for (int y = 1, mnln = 4; mnln <= s.size(); y++, mnln *= 2) {
		for (int i = 0; i + mnln - 1 < s.size(); i++) {
			for (int j = i + mnln - 1; j < s.size(); j++) {
				if (isp[i][j] && dp[(y - 1) % 2][i][(i + j - 1) / 2] && dp[(y - 1) % 2][(i + j + 2) / 2][j]) dp[y % 2][i][j] = true, output[y + 1]++;
				else dp[y % 2][i][j] = false;
			}
		}
	}
	for (int i = 0; i < s.size(); i++) cout << output[i] << " "; cout << endl;
}