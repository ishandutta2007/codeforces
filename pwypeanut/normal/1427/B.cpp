#include <bits/stdc++.h>
using namespace std;

int TC, N, K;
string S;
vector< pair<int, pair<int, int> > > lengths, low, high;

int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d%d", &N, &K);
		cin >> S;
		
		lengths.clear();
		low.clear();
		high.clear();
		int chain = 0, wins = 0, lost = 0, start = -1;
		for (int i = 0; i < N; i++) {
			if (S[i] == 'L') lost++;
			else wins++;
			if (S[i] == 'W') {
				if (chain > 0) {
					if (start != -1) lengths.push_back(make_pair(chain, make_pair(start + 1, i - 1)));
					else low.push_back(make_pair(chain, make_pair(start + 1, i - 1)));
				}
				chain = 0;
				start = i;
			}
			else chain++;
		}
		if (chain > 0) high.push_back(make_pair(chain, make_pair(start + 1, N - 1)));
		
		sort(lengths.begin(), lengths.end());
		for (int i = 0; i < lengths.size(); i++) {
			for (int j = lengths[i].second.first; j <= lengths[i].second.second; j++) {
				if (K == 0) break;
				S[j] = 'W';K--;
			}
		}
		
		for (int i = 0; i < low.size(); i++) {
			for (int j = low[i].second.second; j >= low[i].second.first; j--) {
				if (K == 0) break;
				S[j] = 'W';K--;
			}
		}
		
		for (int i = 0; i < high.size(); i++) {
			for (int j = high[i].second.first; j <= high[i].second.second; j++) {
				if (K == 0) break;
				S[j] = 'W';K--;
			}
		}
		
		long long ans = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] == 'W') {
				if (i != 0 && S[i - 1] == 'W') ans+=2;
				else ans++;
			}
		}
		printf("%lld\n", ans);
	}
}