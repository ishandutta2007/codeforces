#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, q, l[c], r[c], t[c], db[c], ans[c], bal=1, jobb, ert;
vector<pair<long long, int> > sz;
void add(int a, int b) {
    int x=t[a];
    if (x<c) {
        if (db[x]==x) {
            ert--;
        }
        db[x]+=b;
        if (db[x]==x) {
            ert++;
        }
    }
}
long long gilbertOrder(int x, int y, int pow, int rot) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rot) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rot + rotateDelta[seg]) & 3;
	long long subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=q; i++) {
        cin >> l[i] >> r[i];
        long long s=gilbertOrder(l[i]-1, r[i]-1, 21, 0);
        sz.push_back({s, i});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<q; i++) {
        int id=sz[i].second;
        while (jobb<r[id]) {
            jobb++;
            add(jobb, 1);
        }
        while (bal>l[id]) {
            bal--;
            add(bal, 1);
        }
        while (jobb>r[id]) {
            add(jobb, -1);
            jobb--;
        }
        while (bal<l[id]) {
            add(bal, -1);
            bal++;
        }
        ans[id]=ert;
    }
    for (int i=1; i<=q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}