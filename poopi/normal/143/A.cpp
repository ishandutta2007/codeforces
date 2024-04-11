                                       /* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define PLL pair<int64, int64>

int n, m, k;
int r[1010], c[1010];
int mat[1010][1010];

int main(){
	int r1, r2, c1, c2, d1, d2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	int a = (r1 + d1 - c2) / 2;
	int b = r1 - a;
	int c = c1 - a;
	int d = d1 - a;
	if(r1 != a + b || r2 != c + d || c1 != a + c || c2 != b + d || d1 != a + d || d2 != b + c)
		cout << -1 << endl;
	else if(a == b || a == c || a == d || b == c || b == d || c == d)
		cout << -1 << endl;
	else if(a < 1 || a > 9 || b < 1 || b > 9 || c < 1 || c > 9 || d < 1 || d > 9)
		cout << -1 << endl;
	else cout << a << ' ' << r1 - a << endl << c1 - a << ' ' << d1 - a << endl;
    return 0;
}