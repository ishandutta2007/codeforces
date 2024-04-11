#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1005;
char a[N], b[N];
int main() {
	scanf("%s%s", &a, &b);
	int ca = 0, cb = 0;
	for(auto i = a; *i; i++) ca += *i - 48;
	for(auto i = b; *i; i++) cb += *i - 48;
	if(ca & 1) ca++;
	puts(ca >= cb ? "YES" : "NO");
}