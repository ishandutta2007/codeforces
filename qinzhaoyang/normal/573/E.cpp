#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define pr pair <ll,int>
#define il inline
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
const ld inf = 1e18;
const int N = 1e5 + 10 , M = 400;

int n , m , k , a[N] , b[N] , p[N] , l[N] , r[N];
ll f[N] , ans;

struct T {
	int tl , tr , q[M]; ll k , b;
	il ll c(int i) {return f[i] + k * a[i] + b;}
	il ld s(int i , int j) {return a[i] == a[j] ? (f[i] < f[j] ? inf : -inf) : (f[j] - f[i]) * 1.0L / (a[j] - a[i]);}
	il void B(int x) {
		for (int i = l[x]; i <= r[x]; i++) f[i] += k * a[i] + b;
		k = b = tr = 0 , tl = 1;
		for (int i = l[x]; i <= r[x]; i++) {
			while(tr >= 2 && s(q[tr - 1] , q[tr]) <= s(q[tr] , p[i])) tr--;
			q[++tr] = p[i];
		}
	}
	il pr A() {
		while(tl != tr && c(q[tl]) <= c(q[tl + 1])) ++tl;
		return mp(c(q[tl]) , q[tl]); 
	}
}	t[M];

int main() {
	scanf("%d" , &n) , m = sqrt(n);
	for(int i = k = 1; i <= n; k += !(i % m) , i++)
		scanf("%d" , &a[i]) , f[i] = a[i] , p[i] = i , b[i] = k;
	if(!(n % m)) --k;
	for(int i = 1; i <= k; i++) {
		l[i] = r[i - 1] + 1 , r[i] = min(n , i * m);
		sort(p + l[i] , p + r[i] + 1 , [&](int i , int j) {return a[i] < a[j];});
		t[i].B(i);
	}
	while(true) {
		pr o = mp(0 , 0);
		for(int i = 1; i <= k; i++) o = max(o , t[i].A());
		if(o.fi == 0) return printf("%lld\n" , ans) , 0;
		ans += o.fi , f[o.se] = -inf;
		for(int i = 1; i < b[o.se]; i++) t[i].b += a[o.se];
		for(int i = l[b[o.se]]; i < o.se; i++) f[i] += a[o.se];
		for(int i = o.se + 1; i <= r[b[o.se]]; i++) f[i] += a[i];
		for(int i = b[o.se] + 1; i <= k; i++) t[i].k++;
		t[b[o.se]].B(b[o.se]);
	}
	return 0;
}