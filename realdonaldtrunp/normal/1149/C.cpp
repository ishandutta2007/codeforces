#include"bits/stdc++.h"
#include "chrono"
using namespace std;
typedef long long ll;

struct st {
	pair<long long int,long long int> all;
	long long int p_max;
	long long int p_min;
	long long int s_max;
	long long int s_min;
	long long int maxt;
	st() {
		p_max = p_min = s_max = s_min = maxt = 0;
		all.first = all.second = 0;
	}
};


//)) +1 (( -1
st merge(st a, st b) {
	st r;
	r.p_max = a.p_max;
	r.p_max = max(r.p_max, a.all.first + a.all.second + b.p_min);
	r.p_max = max(r.p_max, a.all.first - a.all.second + b.p_max);
	r.p_min = a.p_min;
	r.p_min = max(r.p_min, -a.all.first + a.all.second + b.p_min);
	r.p_max = max(r.p_max, 0LL);
	r.p_min = max(r.p_min, 0LL);
	
	r.s_max = b.s_max;
	r.s_max = max(r.s_max, b.all.first + b.all.second + a.s_min);
	r.s_max = max(r.s_max, -b.all.first + b.all.second + a.s_max);
	r.s_min = b.s_min;
	r.s_min = max(r.s_min, b.all.first - b.all.second + a.s_min);
	r.s_max = max(r.s_max, 0LL);
	r.s_min = max(r.s_min, 0LL);

	r.maxt = max(a.maxt, b.maxt);
	r.maxt = max(r.maxt, a.s_max + b.p_min);
	r.maxt = max(r.maxt, a.s_min + b.p_max);

	if (a.all.second >= b.all.first) {
		r.all = make_pair(a.all.first, a.all.second - b.all.first + b.all.second);
	}
	else {
		r.all = make_pair(a.all.first + b.all.first - a.all.second, b.all.second);
	}
	return r;
}

#define MAX 200002
st seg[MAX * 5];

void add(int b, int l, int r, int ll, char x) {
	if (l <= ll && ll < r) {
		if (l + 1 == r) {
			if (x == '(') {
				seg[b].all = make_pair(0, 1);
				seg[b].p_max = 1;
				seg[b].p_min = 1;
				seg[b].s_max = 1;
				seg[b].s_min = 0;
			}
			else {
				seg[b].all = make_pair(1, 0);
				seg[b].p_max = 1;
				seg[b].p_min = 0;
				seg[b].s_max = 1;
				seg[b].s_min = 1;
			}
			return;
		}
		add(b * 2 + 1, l, (l + r) >> 1, ll, x);
		add(b * 2 + 2, (l + r) >> 1, r, ll, x);
		seg[b] = merge(seg[b * 2 + 1], seg[b * 2 + 2]);
	}
}

int n;
int q;
vector<char> v;
char buf[300002];
int main() {
	cin >> n >> q;
	scanf("%s", buf);
	int N = 2 * (n - 1);
	for (int i = 0; i < 2 * (n - 1); i++) {
		v.push_back(buf[i]);
		add(0, 0, N, i, buf[i]);
	}
	printf("%lld\n", seg[0].maxt);
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		swap(v[a], v[b]);
		add(0, 0, N, a, v[a]);
		add(0, 0, N, b, v[b]);
		printf("%lld\n", seg[0].maxt);
	}
	return 0;
}