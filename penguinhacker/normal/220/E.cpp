#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000;
int n, a[mxN];
ll k, ans=0;
struct ft {
	int a[mxN];
	ft() {memset(a, 0, sizeof(a));}
	void upd(int pos, int val) {
		for (; pos<n; pos|=pos+1)
			a[pos]+=val;
	}
	int sum(int r) {
		int res=0;
		for (; r>=0; r=(r&(r+1))-1)
			res+=a[r];
		return res;
	}
	int sum(int l, int r) {
		//if (l>r) return 0;
		return sum(r)-sum(l-1);
	}
} l, r;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	vector<int> v(a, a+n);
	sort(v.begin(), v.end());
	int num=unique(v.begin(), v.end())-v.begin();
	v.resize(num);
	for (int i=0; i<n; ++i)
		a[i]=lower_bound(v.begin(), v.end(), a[i])-v.begin();

	ll inv=0;
	for (int i=0; i<n; ++i) {
		inv+=r.sum(a[i]+1, n-1);
		r.upd(a[i], 1);
	}
	//cout << inv << '\n';
	for (int lb=0, rb=0; lb<n-1; ++lb) {
		if (rb<=lb) {
			inv-=r.sum(0, a[rb]-1);
			inv-=l.sum(a[rb]+1, n-1);
			r.upd(a[rb], -1);
			rb=lb+1;
		}
		inv+=l.sum(a[lb]+1, n-1);
		inv+=r.sum(0, a[lb]-1);
		l.upd(a[lb], 1);
		while(rb<n-1&&inv>k) {
			//if (lb==0) cout << inv << ' ' << rb << '\n';
			inv-=r.sum(0, a[rb]-1);
			inv-=l.sum(a[rb]+1, n-1);
			r.upd(a[rb++], -1);
		}
		if (inv>k) break;
		ans+=n-rb;
		//cout << lb << ' ' << rb << '\n';
	}
	cout << ans;
	return 0;
}