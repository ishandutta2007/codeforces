#include <stdio.h>
#include <algorithm>
struct P {long long w, t, fly;};
bool cmp1(const P &a, const P &b) {return a.fly > b.fly;}
bool cmp2(const P &a, const P &b) {return a.t < b.t;}
int n, as = 0, bs = 0, ans, i;
long long T;
P a[300000], b[300000], temp;
int main() {
	scanf("%d%I64d%*I64d", &n, &T);
	for(i = 1; i < n; ++i) {
		scanf("%I64d%I64d", &temp.t, &temp.w);
		temp.fly = temp.w - temp.t + 1;
		if(temp.t > T) a[as++] = temp; else b[bs++] = temp;
	}
	std::make_heap(a, a + as, cmp1);
	std::make_heap(b, b + bs, cmp2);
	ans = as;
	while(as && a[0].fly <= T) {
		T -= a[0].fly;
		std::pop_heap(a, a + as--, cmp1);
		while(bs && b[0].t > T) {
			a[as++] = b[0];
			std::pop_heap(b, b + bs--, cmp2);
			std::push_heap(a, a + as, cmp1);
		}
		if(as < ans) ans = as;
	}
	return !printf("%d", ans + 1);
}