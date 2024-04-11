#include <bits/stdc++.h>
using namespace std;

char S[1000006];
deque<char> D;

int main() {
	scanf("%s", &S);
	
	int N = strlen(S);
	D.push_back(S[N/2]);
	int bot = N/2-1, top = N/2+1;
	while (bot != -1 && top != N) {
		if (S[bot] == S[top]) {
			D.push_front(S[bot]);
			D.push_back(S[top]);
			bot--;
			top++;
			continue;
		}
		else if (bot > 0 && S[bot - 1] == S[top]) {
			D.push_front(S[bot - 1]);
			D.push_back(S[top]);
			bot -= 2;
			top++;
			continue;
		}
		else if (top < N-1 && S[bot] == S[top + 1]) {
			D.push_front(S[bot]);
			D.push_back(S[top + 1]);
			bot--;
			top+=2;
			continue;
		}
		else if (top < N-1 && bot > 0 && S[bot - 1] == S[top + 1]) {
			D.push_front(S[bot - 1]);
			D.push_back(S[top + 1]);
			bot-=2;
			top+=2;
			continue;
		} else break;
	}
	if (D.size() >= N/2) {
		for (int i = 0; i < D.size(); i++) printf("%c", D[i]);
		printf("\n");
	} else printf("IMPOSSIBLE\n");
}