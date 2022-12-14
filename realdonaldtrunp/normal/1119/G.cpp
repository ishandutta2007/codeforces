#include"bits/stdc++.h"
#include "chrono"
using namespace std;
typedef long long ll;

#define MAX 1000002

int n;
int m;

vector<pair<long long int, int> > v;

struct st {
	vector<int> atk;
	long long int team;
};
vector<st> vv;
int pa[MAX];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		long long int a;
		scanf("%lld", &a);
		v.push_back(make_pair(a, i));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	vv.push_back(st());
	vv.back().team = n;
	int lef = 0;
	while (lef < v.size()) {
		int cc = 0;
		for (int j = lef; j < v.size(); j++) {
			if (cc == vv.size()) {
				break;
			}
			while (cc < vv.size()) {
				if (v[j].first >= vv[cc].team) {
					v[j].first -= vv[cc].team;
					vv[cc].atk.push_back(j);
					cc++;
					continue;
				}
				if (v[j].first <= 0&&j+1<v.size()) {
					lef++;
					break;
				}
				if (j == v.size() - 1) {
					v[j].first -= vv[cc].team;
					vv[cc].atk.push_back(j);
					cc++;
					continue;
				}
				//split
				long long int aban = vv[cc].team - v[j].first;
				vv[cc].team = v[j].first;
				v[j].first = 0;
				vv.push_back(vv[cc]);
				vv[cc].atk.push_back(j);
				vv.back().team = aban;
				lef++;
				cc++;
				break;
			}
			if (v[j].first > 0) {
				break;
			}
			if (v[j].first <= 0) {
				lef = j+1;
			}
		}
	}
	while (vv.size() < m) {
		vv.push_back(st());
		vv.back().team = 0;
	}
	int A = vv[0].atk.size();
	cout << A << endl;
	for (int i = 0; i < vv.size(); i++) {
		if (i)printf(" ");
		printf("%lld", vv[i].team);
	}
	puts("");
	
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < vv.size(); j++) {
			if (j)printf(" ");
			if (vv[j].atk.size() > i) {
				printf("%d", v[vv[j].atk[i]].second+1);
			}
			else {
				printf("%d", m);
			}
		}
		puts("");
	}
	return 0;
}