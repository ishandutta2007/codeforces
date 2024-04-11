#include <cstdio>
#include <algorithm>

int N, H[200005];
int x;

int main() {
	
	scanf("%d%d", &N, &x);
	for(int i = 1; i <= N; ++i)
		scanf("%d", H + i);
	std::sort(H + 1, H + N + 1);
	
	int Mid = N / 2 + 1;
	
	if(H[Mid] == x) puts("0");
	else if(H[Mid] < x) {
		
		long long Ans = 0;
		
		for(int i = Mid; i <= N; ++i) {
			if(H[i] < x) Ans += x - H[i];
			else break;
		}
		
		printf("%lld\n", Ans);
	}
	else {
		
		long long Ans = 0;
		
		for(int i = Mid; i >= 1; --i) {
			if(H[i] > x) Ans += H[i] - x;
			else break;
		}
		
		printf("%lld\n", Ans);
	}
	
	return 0;
}