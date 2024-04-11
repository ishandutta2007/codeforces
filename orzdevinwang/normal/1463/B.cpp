#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 505;
int T, n, a;
void Main() {
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &a);
		printf("%d ", (1 << (int)(log2(a))));
	}
	puts("");
}
int main() {
	scanf("%d", &T); while(T--) Main();
	return 0;
}