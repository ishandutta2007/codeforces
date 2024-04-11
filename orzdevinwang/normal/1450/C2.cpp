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
int n, m, cnto[5], cntx[5], Cnt;
char s[N][N];
void Main() {
	scanf("%d", &n);
	Cnt = 0;
	cntx[0] = cntx[1] = cntx[2] = 0;
	cnto[0] = cnto[1] = cnto[2] = 0;
	L(i, 1, n) scanf("%s", s[i] + 1);
	L(i, 1, n) L(j, 1, n) if(s[i][j] == 'X') cntx[(i + j) % 3] ++, Cnt ++; else if(s[i][j] == 'O') cnto[(i + j) % 3] ++, Cnt ++;
	int Minn = 1e9, x = 0, y = 0;
	L(i, 0, 2) L(j, 0, 2) if(i != j) if(cntx[i] + cnto[j] < Minn) Minn = cntx[i] + cnto[j], x = i, y = j;
	L(i, 1, n) L(j, 1, n) if(s[i][j] == 'X' && (i + j) % 3 == x) s[i][j] = 'O';
	L(i, 1, n) L(j, 1, n) if(s[i][j] == 'O' && (i + j) % 3 == y) s[i][j] = 'X';
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