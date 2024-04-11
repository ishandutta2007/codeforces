#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
typedef long long ll;

struct Point {int x, y;} a[10], b[N];
Point operator - (Point A, Point B) {return (Point){A.x - B.x, A.y - B.y};}
ll cross(Point A, Point B) {return 1ll * A.x * B.y - 1ll * A.y * B.x;}
ll pro(Point A, Point B) {return 1ll * A.x * B.x + 1ll * A.y * B.y;}

int k, n, s[10], f[N], A, ct = 0;
vector <int> to[10][N], pre;

int check(int x) {
	if(ct == k) return 0; f[x] = 1, ++ct, pre.push_back(x);
	for (int i : to[s[ct]][x]) if(!f[i] && !check(i))
		return 0;
	return 1;
}

int main() {
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= k; i++) scanf("%d%d", &a[i].x, &a[i].y);
	for (int i = 1; i <= n; i++) scanf("%d%d", &b[i].x, &b[i].y); 
	for (int i = 1; i <= k; i++) for (int j = 1; j <= n; j++)
		for (int m = 1; m <= n; m++) if(m != j)
			if (cross(b[j] - a[i], b[m] - b[j]) == 0 && pro(a[i] - b[j], b[m] - b[j]) < 0)
				to[i][m].push_back(j);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) s[j] = j;
		do {
			while(pre.size()) f[pre.back()] = 0, pre.pop_back(); 
			if(ct = 0, check(i)) {A++; break;}
		} while(next_permutation(s + 1, s + k + 1));
	}
	printf("%d\n", A);
	return 0;
}