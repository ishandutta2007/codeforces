#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
const int BLOCK=400;

deque<int> d[BLOCK+1];
int cnt[mxN+1][BLOCK+1];

void print(int n) {
	vector<int> res;
	for (int i=0; i<=BLOCK; ++i) {
		if (d[i].empty())
			break;
		for (int i: d[i]) {
			//cout << i << " ";
			res.push_back(i);
		}
		//cout << "\n";
	}
	assert(res.size()==n);
	for (int i: res)
		cout << i << " ";
	cout << "\n";
}

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		int a; cin >> a;
		int id=i/BLOCK;
		d[id].push_back(a);
		++cnt[a][id];
	}
	//print(n);
	//return 0;
	int m, ans=0; cin >> m;
	while(m--) {
		int type, l, r; cin >> type >> l >> r, --l, --r;
		l=(l+ans)%n, r=(r+ans)%n;
		if (l>r) swap(l, r);
		int lid=l/BLOCK, rid=r/BLOCK, li=l%BLOCK, ri=r%BLOCK;
		if (type==1) {
			int x=d[rid][ri];
			--cnt[x][rid];
			d[rid].erase(d[rid].begin()+ri);
			++cnt[x][lid];
			d[lid].insert(d[lid].begin()+li, x);
			for (int i=lid; i<rid; ++i) {
				x=d[i].back();
				--cnt[x][i];
				d[i].pop_back();
				++cnt[x][i+1];
				d[i+1].push_front(x);
			}
			//print(n);
		}
		if (type==2) {
			int k; cin >> k;
			k=(k+ans-1)%n+1;
			auto calc=[&](int id, int lb, int rb) {
				for (int i=lb; i<=rb; ++i)
					if (d[id][i]==k)
						++ans;
			};
			ans=0;
			if (lid==rid) {
				calc(lid, li, ri);
			}
			else {
				calc(lid, li, BLOCK-1);
				calc(rid, 0, ri);
				for (int i=lid+1; i<rid; ++i)
					ans+=cnt[k][i];
			}
			cout << ans << "\n";
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/