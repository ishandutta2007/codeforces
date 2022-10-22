#include <bits/stdc++.h>
using namespace std;

string S;
char g[2][13];
vector<int> v[26];

int main() {
	cin >> S;
	for (int i = 0; i < 27; i++) {
		v[S[i] - 'A'].push_back(i);
	}
	for (int i = 0; i < 26; i++) {
		if (v[i].size() == 2) {
			int dis = v[i][1] - v[i][0] - 1;
			if (dis == 0) {
				printf("Impossible\n");
				return 0;
			}
			else {
				if (dis % 2 == 0) {
					int idx = 13 - (dis / 2) - 1;
					g[0][idx] = 'A' + i;
					for (int j = 1; j <= dis / 2; j++) {
						g[0][idx + j] = S[v[i][0] + j];
					}
					for (int j = dis / 2 + 1; j <= dis; j++) {
						g[1][12 - (j - dis/2 - 1)] = S[v[i][0] + j];
					}
					string news = S.substr(v[i][1] + 1, S.length() - v[i][1] - 1);
					news += S.substr(0, v[i][0]);
					for (int i = 0; i <= news.length() / 2; i++) {
						g[1][idx - i] = news[i];
					}
					for (int i = 0; i < news.length() / 2; i++) {
						g[0][i] = news[news.length() / 2 + i + 1];
					}
				} else {
					string news = S.substr(v[i][1] + 1, S.length() - v[i][1] - 1);
					news += S.substr(0, v[i][0]);
					
					int idx = 13 - (news.length() / 2) - 1;
					g[0][idx] = 'A' + i;
					for (int j = 1; j <= news.length() / 2; j++) {
						g[0][idx + j] = news[j - 1];
					}
					for (int j = news.length() / 2 + 1; j <= news.length(); j++) {
						g[1][12 - (j - news.length()/2 - 1)] = news[j - 1];
					}
					
					string s2 = S.substr(v[i][0] + 1, dis);
					
					for (int i = 0; i <= s2.length() / 2; i++) {
						g[1][idx - i] = s2[i];
					}
					for (int i = 0; i < s2.length() / 2; i++) {
						g[0][i] = s2[s2.length() / 2 + i + 1];
					}
				}
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 13; j++) printf("%c", g[i][j]);
		printf("\n");
	}
}