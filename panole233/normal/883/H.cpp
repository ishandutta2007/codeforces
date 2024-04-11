#if (__APPLE__)
#include "/Users/zhaofuqing/c++_head/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define N (1000010)
int n, cnt[1010], S, top, qs, Qs;
char s[N], Stack[1010], ans[N], q[N], Q[N];
int main() {
	#if (ONLINE_JUDGE) 
	#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	scanf("%s",s+1);
	for (int i = 1; i <= n; ++i) cnt[s[i]]++;
	for (char c = 'a'; c <= 'z'; ++c) Stack[++top] = c;
	for (char c = 'A'; c <= 'Z'; ++c) Stack[++top] = c;
	for (char c = '0'; c <= '9'; ++c) Stack[++top] = c;
	for (int j = 1; j <= top; ++j) S += cnt[Stack[j]] / 2;
	for (int i = 1; i <= n; ++i) if (n % i == 0) {
		int t=n/i;
		int v=t/2*i;
		if (S<v) continue;
		for (int j = 1; j <= top; ++j) {
			for (int k = 1; k <= cnt[Stack[j]] / 2; k++) q[++qs] = Stack[j];
			if (cnt[Stack[j]] & 1) Q[++Qs] = Stack[j];
		}
		cout<<i<<endl;
		for (int j = 1; j <= i; ++j) {
			for (int j = 1; j <= t / 2; ++j) ans[j] = ans[t-j+1] = q[qs--];
			if (t & 1) {
				if (Qs) ans[t/2+1]=Q[Qs--];
				else {
					ans[t/2+1] = q[qs--];
					Q[++Qs] = ans[t/2+1];
				}
			}
			for (int j = 1; j <= t; ++j) putchar(ans[j]);
			if (j < i) putchar(' '); else putchar('\n');
		}
		break;
	}
	return 0;
}