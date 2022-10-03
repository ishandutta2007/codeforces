#include <cstdio>
#include <cstring>
#include <vector>

const int MN = 1000005;

int N, cnt;
char s[MN];
int stkL[MN], stkR[MN], tpL, tpR;
std::vector<int> V[MN], LL, LR, RL, RR;

inline void Print(int i) {
	for (auto x : V[i]) printf("%d ", x);
}
inline void PrintLRRL() {
	if (LR.empty()) for (auto v : RL) Print(v);
	else if (RL.empty()) for (auto v : LR) Print(v);
	else {
		if (V[LR.back()].back() > V[RL.back()].back()) LR.swap(RL);
		V[LR.back()].push_back(V[RL.back()].back());
		V[RL.back()].pop_back();
		for (auto v : LR) Print(v);
		for (auto v : RL) Print(v);
	}
}
inline void PrintLLRR(int t) {
	if (t) LL.swap(RR);
	for (int i = 0; i < (int)LL.size(); ++i) {
		Print(LL[i]);
		if (i < (int)RR.size()) Print(RR[i]);
	}
}

int main() {
	scanf("%s", s + 1), N = strlen(s + 1);
	for (int i = 1, z; i <= N; ++i) {
		if (s[i] == 'L') {
			z = tpR ? stkR[tpR--] : ++cnt;
			V[stkL[++tpL] = z].push_back(i);
		} else {
			z = tpL ? stkL[tpL--] : ++cnt;
			V[stkR[++tpR] = z].push_back(i);
		}
	}
	printf("%d\n", cnt - 1);
	for (int i = 1; i <= cnt; ++i) {
		char x = s[V[i].front()], y = s[V[i].back()];
		if (x == 'L' && y == 'L') LL.push_back(i);
		if (x == 'L' && y == 'R') LR.push_back(i);
		if (x == 'R' && y == 'L') RL.push_back(i);
		if (x == 'R' && y == 'R') RR.push_back(i);
	}
	if (LR.empty() && RL.empty()) PrintLLRR(RR.size() > LL.size());
	else {
		int o = LR.empty() || (!RL.empty() && V[LR.back()].back() > V[RL.back()].back());
		if (LL.size() == RR.size()) PrintLRRL(), PrintLLRR(o);
		else if (LL.size() > RR.size()) {
			if (!o) PrintLRRL();
			PrintLLRR(0);
			if (o) PrintLRRL();
		} else {
			if (o) PrintLRRL();
			PrintLLRR(1);
			if (!o) PrintLRRL();
		}
	}
	return 0;
}