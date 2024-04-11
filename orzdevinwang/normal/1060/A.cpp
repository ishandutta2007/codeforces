#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 6e5 + 7;
int n, cnt;
char p[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> (p + 1);
	L(i, 1, n) {
		if(p[i] == '8') cnt ++;
	}
	cout << min(cnt, (int) n / 11) << endl;
	return 0;
}