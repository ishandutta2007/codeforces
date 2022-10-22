#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L >> R;
	L--;
	R--;
	int num[2][3][3] = {};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> num[i][j][k];
				num[i][j][k]--;
			}
		}
	}
	pair<long long int,pair<long long int, long long int>>dp[3][3] = {};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = { -1,{ -1,-1} };
		}
	}
	if (L == R) {
		dp[L][R] = { 1,{0,0} };
	}
	else if ((L + 1) % 3 == R) {
		dp[L][R] = { 1,{ 1,0 } };
	}
	else{
		dp[L][R] = { 1,{ 0,1 } };
	}
	queue<pair<int, int>>Q;
	Q.push({ L,R });
	while (1) {
		int a = Q.front().first;
		int b = Q.front().second;
		//cout << dp[a][b].first << endl;
		if (dp[a][b].first == N) {
			cout << dp[a][b].second.second << " " << dp[a][b].second.first << endl;
			return 0;
		}
		Q.pop();
		int na, nb;
		na = num[0][a][b];
		nb = num[1][a][b];
		Q.push({ na,nb });
		if (dp[na][nb].first == -1) {
			if (na == nb) {
				dp[na][nb] = { dp[a][b].first + 1,{dp[a][b].second.first,dp[a][b].second.second} };
			}
			else if ((na + 1) % 3 == nb) {
				dp[na][nb] = { dp[a][b].first + 1,{ dp[a][b].second.first + 1,dp[a][b].second.second } };
			}
			else {
				dp[na][nb] = { dp[a][b].first + 1,{ dp[a][b].second.first,dp[a][b].second.second + 1 } };
			}
		}
		else {
			long long int box = (N - dp[na][nb].first) / (dp[a][b].first + 1 - dp[na][nb].first);
			if (na == nb) {
				dp[na][nb] = { dp[na][nb].first + box*(dp[a][b].first + 1 - dp[na][nb].first),{dp[na][nb].second.first + box*(dp[a][b].second.first - dp[na][nb].second.first),dp[na][nb].second.second + box*(dp[a][b].second.second - dp[na][nb].second.second) } };
			}
			else if ((na + 1) % 3 == nb) {
				dp[na][nb] = { dp[na][nb].first + box*(dp[a][b].first + 1 - dp[na][nb].first),{ dp[na][nb].second.first + box*(dp[a][b].second.first + 1 - dp[na][nb].second.first),dp[na][nb].second.second + box*(dp[a][b].second.second - dp[na][nb].second.second) } };
			}
			else {
				dp[na][nb] = { dp[na][nb].first + box*(dp[a][b].first + 1 - dp[na][nb].first),{ dp[na][nb].second.first + box*(dp[a][b].second.first - dp[na][nb].second.first),dp[na][nb].second.second + box*(dp[a][b].second.second + 1 - dp[na][nb].second.second) } };
			}
			while (!Q.empty()) {
				Q.pop();
			}
			Q.push({ na,nb });
			break;
		}
	}
	while (1) {
		int a = Q.front().first;
		int b = Q.front().second;
		if (dp[a][b].first == N) {
			cout << dp[a][b].second.second << " " << dp[a][b].second.first << endl;
			return 0;
		}
		Q.pop();
		int na, nb;
		na = num[0][a][b];
		nb = num[1][a][b];
		Q.push({ na,nb });
		if (na == nb) {
			dp[na][nb] = { dp[a][b].first + 1,{ dp[a][b].second.first,dp[a][b].second.second } };
		}
		else if ((na + 1) % 3 == nb) {
			dp[na][nb] = { dp[a][b].first + 1,{ dp[a][b].second.first + 1,dp[a][b].second.second } };
		}
		else {
			dp[na][nb] = { dp[a][b].first + 1,{ dp[a][b].second.first,dp[a][b].second.second + 1 } };
		}
	}
	return 0;
}