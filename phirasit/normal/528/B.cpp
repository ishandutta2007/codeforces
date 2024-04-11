#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define N 200010
#define A first
#define B second

using namespace std;

typedef pair<int, int> pll;

vector<int> T;
set<int> S;
map<int, int> pos;

pll d[N];
int n;

int R[N];
class E {
	public :
		int type, x, i;
		E(int _t, int _x, int _i) {
			this->type = _t;
			this->x = _x;
			this->i = _i;
		}
};
vector<E> V;

int cmp(E e1, E e2) {
	return e1.x != e2.x ? e1.x < e2.x : e1.type < e2.type;
}
int main() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> d[i].A >> d[i].B;
		V.push_back(E(1, d[i].A - d[i].B, i));
		V.push_back(E(-1, d[i].A + d[i].B, i));
	}
	sort(V.begin(), V.end(), cmp);
	int res = 0;
	for(E e : V) {
		if(e.type == 1) {
			R[e.i] = res + 1;
		}else {
			res = max(res, R[e.i]);
		}
	}
	cout << res << endl;
	return 0;
}