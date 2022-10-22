#include <bits/stdc++.h>
using namespace std;

string a, b;
int A[200005];
bool vis[200005];

bool attempt(int x) {
	for (int i = 0; i < a.length(); i++) {
		if (i < x) vis[A[i]] = 1;
		else vis[A[i]] = 0;
	}
	int best = 0;
	for (int i = 0; i < a.length(); i++) {
		if (vis[i]) continue;
		//printf("%c", a[i]);
		if (best == b.length()) continue;
		if (a[i] == b[best]) best++;
	}
	//printf("%d: %d\n", x, best == b.length());
	return best == b.length();
}

int main() {
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) scanf("%d", &A[i]);
	for (int i = 0; i < a.length(); i++) A[i]--;
	int bot = 0, top = a.length(), mid;
	while (bot + 1 < top) {
		mid=(bot+top)/2;
		if (attempt(mid)) bot = mid;
		else top = mid;
	}
	printf("%d\n", bot);
}