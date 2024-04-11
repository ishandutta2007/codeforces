#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e3 + 7;
int n, q; char s[N];
void get(int l, int r) {
	L(i, 1, l - 1) if(s[l] == s[i]) return puts("YES"), void();
	L(i, r + 1, n) if(s[r] == s[i]) return puts("YES"), void();
	puts("NO");
}
void Main() {
	scanf("%d%d%s", &n, &q, s + 1);
	while(q--) {
		int l, r; scanf("%d%d", &l, &r);
		get(l, r);
	} 
}
int T; 
int main() {
	scanf("%d", &T); while(T--) Main();
	return 0;
}