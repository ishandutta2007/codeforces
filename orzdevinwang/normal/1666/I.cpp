#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 4e5 + 7;
int AX = 2, AY = 3;
int BX = 3, BY = 4;
int SCAN(int x, int y) {
	cout << "SCAN " << x << ' ' << y << endl;
	int w = abs(x - AX) + abs(x - BX) + abs(y - AY) + abs(y - BY);
	cin >> w;
	return w;
}
int DIG(int x, int y) {
	cout << "DIG " << x << ' ' << y << endl;
	int w = (x == AX && y == AY) + (x == BX && y == BY);
	cin >> w;
	return w;
}
int n, m;
void Main() {
	cin >> n >> m;
	int a = SCAN(1, 1) + 4;
	int b = SCAN(1, m) + 2 - m * 2;
	int x = (a + b) / 2, y = (a - b) / 2;
//	cout << x << " and " << y << endl;
	int wx = SCAN(x / 2, 1) + 2 - y;
	int wy = SCAN(1, y / 2) + 2 - x;
	int x_1 = (x - wx) / 2, x_2 = (x + wx) / 2;
	int y_1 = (y - wy) / 2, y_2 = (y + wy) / 2;
	if(DIG(x_1, y_1)) DIG(x_2, y_2);
	else DIG(x_1, y_2), DIG(x_2, y_1);
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
} 
/*
(1, 1) : (x_1-1) + (y_1-1) + (x_2-1) + (y_2-1).
(1, m) : (x_1-1) + (m-y_1) + (x_2-1) + (m-y_2). 
A=x_1 + x_2, B=y_1 + y_2 is known. 
then query (1,A/2), (B/2,1)
x_1 <= x_2, so far, x_2 - x_1 is known. 
*/