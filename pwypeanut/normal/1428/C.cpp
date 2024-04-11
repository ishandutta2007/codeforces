#include <bits/stdc++.h>
using namespace std;

int TC;
char S[200005];
vector<char> V, V2;

int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf(" %s", S);
		int N = strlen(S);
		V.clear();
		V2.clear();
		for (int i = 0; i < N; i++) {
			if (S[i] == 'B' && V.size() > 0 && V.back() == 'A') {
				V.pop_back();
			} else V.push_back(S[i]);
		}
		for (int i = 0; i < V.size(); i++) {
			if (V[i] == 'B' && V2.size() > 0 && V2.back() == 'B') {
				V2.pop_back();
			} else V2.push_back(V[i]);
		}
		printf("%d\n", (int)V2.size());
	}
}