#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5e5 + 7;
const int inf = 1e9 + 7;
int n, cnt[N << 1];
char s[N];
void Main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	int now = 0;
	L(i, 1, n) {
		if(s[i] == '1') cnt[N + now] ++, now ++; 
		else now --, cnt[N + now] ++;
	}
	now = 0;
	L(i, 1, n) {
		if(cnt[N + now - 1] > 0 && (!cnt[N + now] || cnt[N + now - 1] > 1)) --now, cnt[N + now] --, putchar('0');
		else cnt[N + now] --, now ++, putchar('1');
	}
	puts("");
	L(i, -n, n) cnt[N + i] = 0;
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}