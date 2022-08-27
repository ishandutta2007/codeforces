#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
const int N = 1e6 + 7;
int n, m, val, B = 321;
mt19937 orz(19260817 ^ time(NULL));
int rad(int l, int r) { return orz() % (r - l + 1) + l; }
int ask(int x) {
	x = (x % n + n - 1) % n + 1; 
	printf("? %d\n", x);
	fflush(stdout);
	return read();
}
void Main() {
	n = read(), m = read();
	int now = 1, cnt = 0;
	while(1) {
		now = (now + B - 1) % n + 1, val = ask(now); if(val < m) break; 
		B = rad(300, 340);
	} 
	while(1) {
		if(ask((now + B - 1) % n + 1) < m) now = (now + B - 1) % n + 1;
		else {
			while(ask(now % n + 1) < m) now = now % n + 1;
			break;
		}
		B = rad(300, 340);
	}
	printf("! %d\n", now % n + 1);
}
int main() {
	Main();
	return 0;
}