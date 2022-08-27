#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, m, x[N], y[N];
void Main() {
	scanf("%d%d", &n, &m);
	L(i ,1, n) scanf("%d%d", &x[i], &y[i]);
	L(i, 1, n) {
		bool ok = 1;
		L(j, 1, n) {
			if(abs(x[i] - x[j]) + abs(y[i] - y[j]) > m) {
				ok = 0;
				break;
			}
		}
		if(ok) {
			puts("1");
			return;
		}
	}
	puts("-1");
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}