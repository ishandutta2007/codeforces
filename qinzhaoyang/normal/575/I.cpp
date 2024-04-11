#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10 , Q = 1e5 + 10;

int n, q, op[Q], dir[Q], x[Q], y[Q], c[Q], A[Q];

struct BIT {
	int X, Y, c[N << 1][N << 1];
	void resize(int x, int y) {
		memset(c, 0, sizeof c) , X = x , Y = y;
	}
	int add(int x, int y, int z) {
		for (int i = x; i <= X; i += i & (-i))
			for (int j = y; j <= Y; j += j & (-j))
				c[i][j] += z;
	}
	int ask(int x, int y) {
		int ret = 0;
		for (int i = x; i; i -= i & (-i))
			for (int j = y; j; j -= j & (-j))
				ret += c[i][j];
		return ret; 
	}
}	bit;

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d", &op[i]);
		if(op[i] == 1) scanf("%d%d%d%d", &dir[i], &x[i], &y[i], &c[i]);
		else if(op[i] == 2) scanf("%d%d", &x[i], &y[i]);
	}
	bit.resize(n , n);
    for (int i = 1; i <= q; i++)
        if (op[i] == 1) {
            if (dir[i] == 1) bit.add(x[i], y[i], 1);
            if (dir[i] == 2) bit.add(x[i], y[i] + 1, -1);
            if (dir[i] == 3) bit.add(x[i] + 1, y[i], -1);
            if (dir[i] == 4) bit.add(x[i] + 1, y[i] + 1, 1);
        } else A[i] += bit.ask(x[i], y[i]);
    bit.resize(n + n , n);
    for (int i = 1; i <= q; i++)
        if (op[i] == 1) {
            if (dir[i] == 1) bit.add(x[i] + y[i] + c[i] + 1, y[i], -1);
            if (dir[i] == 4) bit.add(x[i] + y[i] - c[i], y[i] + 1, -1);
        } else A[i] += bit.ask(x[i] + y[i], y[i]);
    bit.resize(n , n + n);
    for (int i = 1; i <= q; i++)
        if (op[i] == 1) {
            if (dir[i] == 1) bit.add(n - x[i] + 2, x[i] + y[i] + c[i] + 1, 1);
            if (dir[i] == 4) bit.add(n - x[i] + 1, x[i] + y[i] - c[i], 1);
        } else A[i] += bit.ask(n - x[i] + 1, x[i] + y[i]);
    bit.resize(n + n , n);
    for (int i = 1; i <= q; i++)
        if (op[i] == 1) {
            if (dir[i] == 2) bit.add(n + x[i] - y[i] + c[i] + 2, y[i] + 1, 1);
            if (dir[i] == 3) bit.add(n + x[i] - y[i] - c[i] + 1, y[i], 1);
        } else A[i] += bit.ask(n + x[i] - y[i] + 1, y[i]);
    bit.resize(n , n + n);
    for (int i = 1; i <= q; i++)
        if (op[i] == 1) {
            if (dir[i] == 2) bit.add(x[i], n - x[i] + y[i] - c[i] + 1, 1);
            if (dir[i] == 3) bit.add(x[i] + 1, n - x[i] + y[i] + c[i] + 2, 1);
        } else A[i] += bit.ask(x[i], n - x[i] + y[i] + 1);
    for (int i = 1; i <= q; i++)
        if (op[i] == 2) printf("%d\n", A[i]);
	return 0;
}