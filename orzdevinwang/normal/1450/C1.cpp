#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3e3 + 7;
int n, m, cnt[5], cs;
char s[N][N];
void Main() {
	scanf("%d", &n);
	cnt[0] = cnt[1] = cnt[2] = 0;
	L(i, 1, n) scanf("%s", s[i] + 1);
	L(i, 1, n) L(j, 1, n) if(s[i][j] == 'X') cnt[(i + j) % 3] ++;
	if(cnt[0] < cnt[1] && cnt[0] < cnt[2]) cs = 0;
	else if(cnt[1] < cnt[2]) cs = 1;
	else cs = 2;
	assert(cnt[cs] <= (cnt[0] + cnt[1] + cnt[2]) / 3);
	L(i, 1, n) L(j, 1, n) if(s[i][j] == 'X' && (i + j) % 3 == cs) s[i][j] = 'O';
	L(i, 1, n) {
		L(j, 1, n) putchar(s[i][j]);
		puts("");
	}
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}