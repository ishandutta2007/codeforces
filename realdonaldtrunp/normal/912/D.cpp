#include<iostream>
#include<cstdio>

#include "bits/stdc++.h"

using namespace std;

typedef long double ld;
typedef long long ll;

const ld pi = acos((ld)-1);
const int inf = (int) 1.01e9;
const ld eps = 1e-12;

#define sz(a) (int) (a).size()

#ifdef DEBUGGG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

vector<int> v;
vector<int> vv;

priority_queue<pair<long long int, int> > q;
int id[100002];

int im[100002];

void calc(int n,int r,vector<int> &vc) {
	memset(im, 0, sizeof(im));
	for (int i = 0; i < n; i++) {
		if (i + r <= n) {
			im[i]++;
		}
		if (i) {
			im[i] += im[i - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		int rg = i - r;
		int nw = im[i];
		if (rg >= 0) {
			nw -= im[rg];
		}
		vc.push_back(nw);
	}
}

int main() {
	//(i,j) min(min(i+1,r),min(n-i,r),min(j+1,r),min(m-i,r) )
	int n;
	int m;
	int r;
	int k;
	cin >> n >> m >> r >> k;
	calc(n, r,v);
	calc(m, r,vv);
	sort(v.begin(), v.end(),greater<int>() );
	sort(vv.begin(), vv.end(),greater<int>());
	int idx = 0;
	long long int ans = 0;
	int cnt = 0;
	int tmp = k;
	for (int i = 0; i < v.size(); i++) {
		q.push(make_pair(v[i] * vv[0], i));
		id[i]++;
	}
	while (k--) {
		auto t = q.top();
		q.pop();
		ans += t.first;
		if (id[t.second] < vv.size()) {
			q.push(make_pair(v[t.second] * vv[id[t.second]], t.second));
			id[t.second]++;
		}
	}
	long long int all = (long long int)(n - r+1)*(long long int)(m - r+1);
	double ou = ans;
	ou /= (double)(all);
	printf("%.16f\n", ou);
	return 0;
}