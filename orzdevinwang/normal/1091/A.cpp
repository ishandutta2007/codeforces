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
int a, b, c; //, a[N];
void Main() {
	scanf("%d%d%d", &a, &b, &c);
	b -= 1, c -= 2;
	printf("%d\n", min(a, min(b, c)) * 3 + 3);
}
int main() {
	// int T; scanf("%d", &T);
	// while(T--) Main();
	Main();
	return 0;
}