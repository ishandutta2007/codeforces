#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef double ld;
const int N = 2e5 + 10;
const ld eps = 1e-10L , inf = 1e18L;

int n, q, t, p[N], l[N], c[N];
ld ans;

inline ld f(int x, int c) {
	if(c == -1)	return inf;
	if(c >= l[x]) return 0.0L;
	return 1.0L * p[x] * l[x] / (c + 1 + l[x]) / (c + l[x]); 
}

inline ld g(int x) {
	return 1.0L * p[x] * min(c[x] , l[x]) / (min(c[x] , l[x]) + l[x]);
}

struct T {
	ld o; int x, c;
	inline T(int x = 0 , int c = -1) : x(x) , c(c) {o = f(x , c);}
	inline friend operator < (T A, T B) {
		return abs(A.o - B.o) > eps ? A.o < B.o : A.x < B.x;
	}
};

multiset <T> s, e;

inline void add() {
	auto it = --s.end();
	ans += it->o; int x = it->x;
	e.erase(T(x , c[x] - 1)) , e.insert(T(x , c[x]));
	s.erase(T(x , c[x])) , s.insert(T(x , ++c[x]));
}

inline void rmv() {
	auto it = e.begin();
	ans -= it->o; int x = it->x;
	s.erase(T(x , c[x])) , s.insert(T(x , c[x] - 1));
	e.erase(T(x , c[x] - 1)) , e.insert(T(x , (--c[x]) - 1));
}

int main() {
	scanf("%d%d%d" , &n , &t , &q);
	for (int i = 1; i <= n; i++) scanf("%d" , &p[i]);
	for (int i = 1; i <= n; i++) scanf("%d" , &l[i]);
	for (int i = 1; i <= n; i++) s.insert(T(i , 0)), e.insert(T(i)); 
	while(t--) add();
	while(q--) {
		int o , x; scanf("%d%d" , &o , &x);
		s.erase(T(x , c[x])) , e.erase(T(x , c[x] - 1)) , ans -= g(x);
		l[x] += o == 1 ? 1 : -1;
		s.insert(T(x , c[x])) , e.insert(T(x , c[x] - 1)) , ans += g(x);
		while((--s.end())->o > (e.begin()->o) + eps) rmv() , add();
		printf("%.10Lf\n" , ans);
	}
	return 0;
}