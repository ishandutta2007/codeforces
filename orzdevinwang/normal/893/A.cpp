#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e6 + 7;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f; 
}
int n;
void Main() {
	n = read();
	int x = 1, y = 2;
	L(i, 1, n) {
		int v = read();
		if(v == y) swap(x, y);
		if(v != x) return puts("NO"), void();
		y = 6 - x - y;
	}
	puts("YES");
}
int main() {
	Main();
	return 0;
}