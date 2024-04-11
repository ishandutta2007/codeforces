#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=4e5;
int n, q, a[mxN], lg[mxN+1], ans[mxN];

struct sparse_table {
	int st[mxN][19];
	void init() {
		for (int j=1; j<19; ++j)
			for (int i=0; i+(1<<j)-1<n; ++i)
				st[i][j]=min(st[i][j-1], st[i+(1<<j-1)][j-1]);
	}
	int qry(int l, int r) {
		int k=lg[r-l+1];
		return min(st[l][k], st[r-(1<<k)+1][k]);
	}
} st1, st2, st3;

void solve(vector<ar<int, 5>>& queries) {
	for (int i=0; i<n; ++i) {
		st1.st[i][0]=a[i];
		st2.st[i][0]=a[i]+2*i;
		st3.st[i][0]=a[i]-2*i;
	}
	st1.init();
	st2.init();
	st3.init();
	for (auto [r1, c1, r2, c2, i] : queries) {
		assert(r1>=r2);
		ans[i]=1+abs(r1-r2)+c2; // press home key
		int lim=min(c1, st1.qry(r2, r1));
		ans[i]=min(ans[i], r1-r2+abs(c2-lim));
		
		bool extra=lim<=c2;
		if (st1.qry(r2, r1)>=c2) { // end in [r2, r1]
			ans[i]=min(ans[i], extra+(r1-r2)+(st1.qry(r2, r1)-c2));
			if (st1.qry(r1, n-1)>=c2) { // check [r1, n-1]
				ans[i]=min(ans[i], extra+(r1-r2)-c2-2*r1+st2.qry(r1, n-1));
			} else {
				int lb=r1, rb=n-1;
				while(lb<rb) {
					int mid=(lb+rb)/2;
					if (st1.qry(r1, mid)<c2)
						rb=mid;
					else
						lb=mid+1;
				}
				assert(lb>r1&&a[lb]<c2);
				ans[i]=min(ans[i], extra+(r1-r2)-c2-2*r1+st2.qry(r1, lb-1));
				ans[i]=min(ans[i], extra+(r1-r2)+2*(lb-r1)+(c2-a[lb]));
			}
		} else {
			assert(r1>r2);
			int lb=r2, rb=r1;
			while(lb<rb) {
				int mid=(lb+rb)/2;
				if (st1.qry(r2, mid)<c2)
					rb=mid;
				else
					lb=mid+1;
			}
			assert(lb>r2&&a[lb]<c2);
			ans[i]=min(ans[i], extra+(r1-r2)+min(st1.qry(r2, lb-1)-c2, c2-a[lb]));
		}

		if (st1.qry(0, r2)>=c2) { // check [0, r2]
			ans[i]=min(ans[i], extra+(r1-r2)+2*r2-c2+st3.qry(0, r2));
		} else {
			int lb=0, rb=r2;
			while(lb<rb) {
				int mid=(lb+rb+1)/2;
				if (st1.qry(mid, r2)<c2)
					lb=mid;
				else
					rb=mid-1;
			}
			assert(lb<r2&&a[lb]<c2);
			ans[i]=min(ans[i], extra+(r1-r2)+2*r2-c2+st3.qry(lb+1, r2));
			ans[i]=min(ans[i], extra+(r1-r2)+2*(r2-lb)+(c2-a[lb]));
		}
	}
	reverse(a, a+n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=2; i<=n; ++i)
		lg[i]=lg[i/2]+1;
	cin >> q;
	vector<ar<int, 5>> q1, q2;
	for (int i=0; i<q; ++i) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2, --r1, --r2;
		if (r1>=r2)
			q1.push_back({r1, c1, r2, c2, i});
		else
			q2.push_back({n-1-r1, c1, n-1-r2, c2, i});
	}
	solve(q1);
	solve(q2);
	for (int i=0; i<q; ++i)
		cout << ans[i] << "\n";
	return 0;
}