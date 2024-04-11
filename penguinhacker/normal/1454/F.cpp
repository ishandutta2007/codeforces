#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int first_true(function<bool(int)> f, int lb, int rb) {
	while(lb < rb) {
		int mb = (lb + rb) / 2;
		if (f(mb)) rb = mb;
		else lb = mb + 1;
	} 
	return lb;
}
int last_true(function<bool(int)> f, int lb, int rb) {
	while(lb < rb) {
		int mb = (lb + rb + 1) / 2;
		if (f(mb)) lb = mb;
		else rb = mb - 1;
	} 
	return lb;
}

struct RMQ { //min range query (default)
	int** st; //sparse table
	int* log;
	int combine(int a, int b) {return min(a, b);} //change to max for range max query
	void build(int n, int a[]) {
		st=new int*[n];
		log=new int[n+1];
		log[1]=0;
		for (int i=2; i<=n; ++i) log[i]=log[i/2]+1;
		int k=log[n];
		for (int i=0; i<n; ++i) st[i]=new int[k+1];
		for (int i=0; i<n; ++i) st[i][0]=a[i];
		for (int j=1; j<=k; ++j) for (int i=0; i+(1<<j)-1<n; ++i)
			st[i][j]=combine(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	}
	int qry(int l, int r) {
		int k=log[r-l+1];
		return combine(st[l][k], st[r-(1<<k)+1][k]);
	}
};

int n, a[200000], suf[200000];
void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		suf[i] = a[i];
	}
	for (int i = n - 2; i >= 0; --i) {
		suf[i] = max(suf[i], suf[i + 1]);
	}
	RMQ rmq;
	rmq.build(n, a);
	int pre_max = 0;
	for (int i = 0; i < n - 2; ++i) {
		pre_max = max(pre_max, a[i]);

		int first1 = first_true([&](int x) {return rmq.qry(i + 1, x) <= pre_max;}, i + 1, n - 2);
		if (rmq.qry(i + 1, first1) != pre_max) continue;
		int last1 = last_true([&](int x) {return rmq.qry(i + 1, x) >= pre_max;}, i + 1, n - 2);
		assert(rmq.qry(i + 1, last1) == pre_max && last1 >= first1);

		int first2 = first_true([&](int x) {return suf[x] <= pre_max;}, i + 2, n - 1);
		if (suf[first2] != pre_max) continue;
		int last2 = last_true([&](int x) {return suf[x] >= pre_max;}, i + 2, n - 1);
		assert(suf[last2] == pre_max && last1 >= first1);

		pair<int, int> isect = {max(first1 - i, first2 - i - 1), min(last1 - i, last2 - i - 1)};

		//cout << i << " " << first1 << " " << last1 << " " << first2 << " " << last2 << "\n";

		if (isect.first <= isect.second) {
			int x = i + 1;
			int y = isect.first;
			int z = n - x - y;
			cout << "YES\n" << x << " " << y << " " << z << "\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}