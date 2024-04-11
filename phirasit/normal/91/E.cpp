#include <stdio.h>
#include <algorithm>
#include <vector>

#define N 100010
#define A first
#define B second

using namespace std;

typedef pair<int, int> PII;

vector<int> curve[4*N];
PII rng[4*N];

long long First[N], H[N];
int n, q;

int cmp(int idx1, int idx2) {
	if(H[idx1] != H[idx2]) {
		return H[idx1] > H[idx2];
	}else {
		return First[idx1] > First[idx2];
	}
}
double find_x(int i, int j) {
	double dF = First[j] - First[i], dH = H[i] - H[j];
	return dF / dH;
}
void init(int idx, int a, int b) {
	if(a < b) {
		int mid = (a + b) / 2;
		init(2*idx, a, mid);
		init(2*idx+1, mid+1, b);
		curve[idx] = curve[2*idx];
		for(int i = 0;i < curve[2*idx+1].size();i++) {
			curve[idx].push_back(curve[2*idx+1][i]);
		}
	}else {
		curve[idx].push_back(a);
	}
	sort(curve[idx].begin(), curve[idx].end(), cmp);
	vector<int> tmp;
	for(int i = 0;i < curve[idx].size();i++) {
		int sz = tmp.size();
		if(sz == 0 || First[tmp[tmp.size()-1]] < First[curve[idx][i]]) {
			while(sz >= 2 && find_x(curve[idx][i], tmp[sz-1]) >= find_x(tmp[sz-1], tmp[sz-2])) {
				tmp.pop_back();
				sz = tmp.size();
			}
			tmp.push_back(curve[idx][i]);
		}
	}
	curve[idx] = tmp;
	rng[idx] = PII(a, b);
}
long long calc(int idx, long long t) {
	return First[idx] + H[idx] * t;
}
int query(int idx, int a, int b, int t) {
	if(a <= rng[idx].A && rng[idx].B <= b) {
		int ma = 0, mb = curve[idx].size() - 1;
		while(ma < mb) {
			int mid = (ma + mb) / 2;
			int idx_a = curve[idx][mid];
			int idx_b = curve[idx][mid+1];
			if(calc(idx_a, t) > calc(idx_b, t)) {
				mb = mid;
			}else {
				ma = mid + 1;
			}
		}
		return curve[idx][ma];
	}
	if(rng[idx].B < a || b < rng[idx].A) {
		return -1;
	}
	int x = query(2*idx, a, b, t);
	int y = query(2*idx+1, a, b, t);
	if(x == -1) {
		return y;
	}
	if(y == -1) {
		return x;
	}
	return calc(x, t) > calc(y, t) ? x : y;
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) {
		scanf("%I64d%I64d", &First[i], &H[i]);
	}
	init(1, 1, n);
	while(q--) {
		int l, r, t;
		scanf("%d%d%d", &l, &r, &t);
		printf("%d\n", query(1, l, r, t));
	}
	return 0;
}