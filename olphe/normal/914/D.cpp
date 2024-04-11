#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int gcd(int a,int b) {
	if (a < b) {
		a ^= b;
		b ^= a;
		a ^= b;
	}
	while (b) {
		a %= b;
		a ^= b;
		b ^= a;
		a ^= b;
	}
	return a;
}

int n, m;
vector<int>v;
vector<int>g;
vector<int>l;
vector<int>r;
int cnt;
int flag;
int a, b, c;

void solve(int p) {
	if (cnt > 1) {
		return;
	}
	if (r[p]<a || l[p]>b) {
		return;
	}
	if(p>=m){
	    if(g[p]%c){
	        cnt++;
	    }
	    return;
	}
	if (l[p] >= a&&r[p] <= b) {
		if (g[p] % c == 0) {
			return;
		}
		solve(p * 2);
		solve(p * 2 + 1);
		return;
	}
	solve(p * 2);
	solve(p * 2 + 1);
	return;
}

int main() {
	scanf("%d", &n);
	m = 1;
	while (m < n) {
		m *= 2;
	}
	v.resize(m,1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	g.resize(2 * m);
	l.resize(2 * m);
	r.resize(2 * m);
	for (int i = 0; i < m; i++) {
		g[i + m] = v[i];
		l[i + m] = i;
		r[i + m] = i;
	}
	for(int i=m-1;i>=1;i--){
	    l[i]=l[i*2];
	    r[i]=r[i*2+1];
	    g[i]=gcd(g[i*2],g[i*2+1]);
	}
	scanf("%lld", &K);
	for (int loop = 0; loop < K; loop++) {
		scanf("%d", &flag);
		if (flag == 1) {
			cnt = 0;
			scanf("%d %d %d", &a, &b, &c);
			a--;
			b--;
			solve(1);
			if (cnt > 1) {
				printf("NO\n");
			}
			else {
				printf("YES\n");
			}
		}
		else {
			scanf("%d %d", &a, &b);
			a--;
			v[a] = b;
			g[a + m] = b;
			int box = a + m;
			box /= 2;
			while (box) {
				g[box] = gcd(g[box * 2], g[box * 2 + 1]);
				box /= 2;
			}
		}
	}
	return 0;
}