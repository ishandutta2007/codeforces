#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, a[N], cnta, cntb;
char s[N], t[N];
int main() {
	scanf("%d", &n);
	scanf("%s%s", s + 1, t + 1);
	L(i, 1, n) cnta += (s[i] == '0'), cnta -= (t[i] == '0');
	if(cnta) return puts("-1"), 0;
	L(i, 1, n) {
		if(s[i] == t[i]) continue;
		if(s[i] == '0') {
			if(cntb) cntb --, cnta ++;
			else cnta ++;
		}
		else {
			if(cnta) cnta --, cntb ++;
			else cntb ++;
		}
	}
	printf("%d\n", cnta + cntb);
	return 0;
}

/*
 1    0  (cnta, cntb)
NOIPRP++
*/