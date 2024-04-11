#include<bits/stdc++.h>
using namespace std;
const int X = 2, Y = 5, P = 7, Q = 9;
int l, r, L, R;
int A, B, C, D;
int p, q, x, y;
int query(int x, int y) {
	fflush(stdout);
	printf("? %d %d\n", x, y);
	/*
	if (x >= X && y >= Y && x <= P && y <= Q)
		assert(0);
	return max(max(X - x, x - P), 0) + max(max(Y - y, y - Q), 0);
	*/
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}
int main(){
	l = 1; r = 1000000000;
	//x + y = A + 2
	//999999999 - p + y = B
	//x + 999999999 - q = C
	//2000000000 - p - q = D
	//B + C - A = D
	A = query(1, 1);
	B = query(1, 1000000000);
	C = query(1000000000, 1);
	l = 1; r = 1000000000;
	L = A; R = B;
	while(l < r) {
		int mid = l + r >> 1;
		if (L > R) {
			l = mid + 1;
			L = query(1, l);
		} else {
			r = mid;
			R = query(1, r);
		}
	}
	y = L + 1;
	x = A + 2 - y;
	q = x + 999999999 - C;
	p = y + 999999999 - B;
	printf("! %d %d %d %d\n", y, x, q, p);
	
}