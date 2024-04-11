#include <cstdio>
#include <vector>

const int MN = 150005;

int N, Ans;
char s1[MN], s2[MN];
std::vector<int> q1[27], q2[27];
int Ax[MN], Ay[MN];

int main() {
	scanf("%d", &N);
	scanf("%s%s", s1 + 1, s2 + 1);
	for (int i = 1; i <= N; ++i) {
		if (s1[i] != '?') q1[s1[i] - 'a'].push_back(i);
		else q1[26].push_back(i);
		if (s2[i] != '?') q2[s2[i] - 'a'].push_back(i);
		else q2[26].push_back(i);
	}
	for (int i = 0; i < 26; ++i) {
		while (!q1[i].empty() && !q2[i].empty()) {
			Ax[++Ans] = q1[i].back(), Ay[Ans] = q2[i].back();
			q1[i].pop_back(), q2[i].pop_back();
		}
	}
	for (int i = 0; i < 26; ++i) {
		while (!q1[i].empty() && !q2[26].empty()) {
			Ax[++Ans] = q1[i].back(), Ay[Ans] = q2[26].back();
			q1[i].pop_back(), q2[26].pop_back();
		}
		while (!q1[26].empty() && !q2[i].empty()) {
			Ax[++Ans] = q1[26].back(), Ay[Ans] = q2[i].back();
			q1[26].pop_back(), q2[i].pop_back();
		}
	}
	while (!q1[26].empty() && !q2[26].empty()) {
		Ax[++Ans] = q1[26].back(), Ay[Ans] = q2[26].back();
		q1[26].pop_back(), q2[26].pop_back();
	}
	printf("%d\n", Ans);
	for (int i = 1; i <= Ans; ++i) printf("%d %d\n", Ax[i], Ay[i]);
	return 0;
}

// lg