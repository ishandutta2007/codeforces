#include<bits/stdc++.h>
#define N 110
using namespace std;
int T, n, a[N], cnt[N], flag, Ans;
int main() {
	scanf("%d", &T);
	while(T--){
	Ans = flag = 0;
	scanf("%d", &n);
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[a[i]]++;
	for(int i = 0; i <= n; i++) {
		if(cnt[i] <= 1) {
			if(!flag) {
				Ans += i;
				flag = 1;
			}
			if(cnt[i] == 0) {
				Ans += i;
				break;
			}
		}
	}
	printf("%d\n", Ans);
	}
	return 0;
}