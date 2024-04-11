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
int n, a[N], minn = 1e9, cnt; 
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]), minn = min(minn, a[i]);
	L(i, 1, n) cnt += (minn == a[i]);
	if(cnt > n / 2) puts("Bob");
	else puts("Alice");
	return 0;
}