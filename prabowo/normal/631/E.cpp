#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long LL;
const int N = 200000;

int n;
LL a[N];
pair <LL, int> b[N];

struct Line {
	Line () {}
	Line (LL _m, LL _c) {m = _m, c = _c;}
	LL m, c;
};	

struct Stack {
	int size;
	Line a[N];
	
	Stack () {size = 0;}
	
	Line top (int x = 1) {return a[size - x];}
	
	void push (Line x) {a[size++] = x;}
	void pop () {size--;}
} stek;

// xy < yz
bool check (Line x, Line y, Line z) {
	return (z.c - x.c) * (y.m - z.m) < (z.c - y.c) * (x.m - z.m);
}

long long eval (Line l, long long x) {
	return l.m * x + l.c;
}

LL sum[N];
long long findMax () {
	long long ret = 0;
	for (int i=0; i<n; i++) sum[i] = sum[i - 1] + a[i];
	
	stek.size = 0;
	
	for (int i=0; i<n; i++) {
		Line tmp = Line (i, -sum[i]);
		while (stek.size >= 2 && !check (stek.top(2), stek.top(), tmp)) stek.pop();
		stek.push (tmp);
	}
	
	for (int i=0; i<n; i++) b[i].first = a[i], b[i].second = i;
	sort (b, b + n);
			
	int now = 0;
	for (int i=0; i<n; i++) {
		while (now < stek.size - 1 && eval(stek.a[now], b[i].first) < eval(stek.a[now + 1], b[i].first))
			now++;
			
		if (stek.a[now].m >= b[i].second) 
			ret = max(ret, eval(stek.a[now], b[i].first) - b[i].second * b[i].first + sum[b[i].second]);
	}
	
	return ret;
}

int main () {
	scanf ("%d", &n);
	
	long long ans = 0;
	for (int i=0; i<n; i++) {
		scanf ("%I64d", a + i);
		ans += a[i] * (i + 1);
	}
	
	long long maks = findMax();	
	reverse (a, a + n);
	for (int i=0; i<n; i++) a[i] = -a[i];
	maks = max(maks, findMax());
	
	printf ("%I64d\n", ans + maks);
	
	return 0;
}