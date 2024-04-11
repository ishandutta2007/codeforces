#include <bits/stdc++.h>
using namespace std;

int TC, N, M, A[12][2005], cnt_impt, arr[12][12], dp[13][5000], memo[13][5005];
bool impt[2005];
vector<int> impt_cols;
vector< pair<int, pair<int, int> > > V;

int mx_add(int i, int k) {
	if (memo[i][k] != -1) return memo[i][k];
	int mxadd = 0;
	for (int l = 0; l < N; l++) {
		int add = 0;
		for (int m = 0; m < N; m++) {
			if ((1 << m) & k) add += arr[(l+m)%N][i-1];
		}
		mxadd=max(mxadd,add);
	}
	return memo[i][k] = mxadd;
}

int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &A[i][j]);
		V.clear();
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) V.push_back(make_pair(A[i][j], make_pair(i,j)));
		sort(V.begin(), V.end(), greater< pair< int, pair<int, int> > >());
		memset(impt, 0, sizeof(impt));
		cnt_impt = 0;
		impt_cols.clear();
		for (int i = 0; i < V.size(); i++) {
			if (!impt[V[i].second.second]) {
				impt[V[i].second.second] = 1;
				impt_cols.push_back(V[i].second.second);
				cnt_impt++;
				if (cnt_impt == N) break;
			}
		}
		for (int i = 0; i < impt_cols.size(); i++) {
			for (int j = 0; j < N; j++) arr[j][i] = A[j][impt_cols[i]];
		}
		M = impt_cols.size();
		memset(dp, -63, sizeof(dp));
		memset(memo, -1, sizeof(memo));
		dp[0][0] = 0;
		for (int i = 1; i <= M; i++) {
			for (int j = 0; j < (1 << N); j++) {
				dp[i][j] = dp[i-1][j];
				for (int k = j; k > 0; k = ( j & (k-1) ) ) {
					
					dp[i][j] = max(dp[i][j], dp[i-1][j^k] + mx_add(i, k));
				}
			}
		}
		printf("%d\n", dp[M][(1 << N) - 1]);
	}
}