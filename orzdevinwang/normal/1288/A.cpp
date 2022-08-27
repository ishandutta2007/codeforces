#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int T, n, d;
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &d, &n);
		int Ans = n;
		for(int i = 1; i <= min((int)(sqrt(n)) * 2 + 1, n); i++) {
			Ans = min(Ans, i + (n + i) / (i + 1));
		}
		if(Ans <= d) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}