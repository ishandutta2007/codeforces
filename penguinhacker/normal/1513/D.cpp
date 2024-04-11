#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class T> struct RMQ1 { //min range query (default)
	vector<vector<T>> st;
	vector<int> log;
	T combine(T a, T b) {return min(a, b);}
	void init(vector<T> a) {
		int n = a.size();
		log = vector<int>(n + 1);
		for (int i = 2; i <= n; ++i) log[i] = log[i >> 1] + 1;
		int k = log[n];
		st = vector<vector<T>>(n, vector<T>(k + 1));
		for (int i = 0; i < n; ++i) st[i][0] = a[i];
		for (int j = 1; j <= k; ++j) for (int i = 0; i + (1 << j) - 1 < n; ++i)
			st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j-1]);
	}
	T qry(int l, int r) {
		int k = log[r - l + 1];
		return combine(st[l][k], st[r - (1 << k) + 1][k]);
	}
};

template<class T> struct RMQ2 { //min range query (default)
	vector<vector<T>> st;
	vector<int> log;
	T combine(T a, T b) {return __gcd(a, b);}
	void init(vector<T> a) {
		int n = a.size();
		log = vector<int>(n + 1);
		for (int i = 2; i <= n; ++i) log[i] = log[i >> 1] + 1;
		int k = log[n];
		st = vector<vector<T>>(n, vector<T>(k + 1));
		for (int i = 0; i < n; ++i) st[i][0] = a[i];
		for (int j = 1; j <= k; ++j) for (int i = 0; i + (1 << j) - 1 < n; ++i)
			st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j-1]);
	}
	T qry(int l, int r) {
		int k = log[r - l + 1];
		return combine(st[l][k], st[r - (1 << k) + 1][k]);
	}
};

int n, p, a[200000], l[200000], r[200000], id[200000], par[200000];

int find(int i) {
	return i^par[i]?par[i]=find(par[i]):i;
}

void merge(int a, int b) {
	a=find(a), b=find(b);
	assert(a^b);
	par[b]=a;
}

void solve() {
	cin >> n >> p;
	for (int i=0; i<n; ++i)
		cin >> a[i], id[i]=i;
	sort(id, id+n, [](int x, int y) {return a[x]<a[y];});
	RMQ1<int> r1;
	RMQ2<int> r2;
	r1.init(vector<int>(a, a+n));
	r2.init(vector<int>(a, a+n));
	for (int i=n-1; ~i; --i) {
		int x=id[i];
		int lb=0, rb=x;
		while(lb<rb) {
			int mid=(lb+rb)/2;
			if (r1.qry(mid, x)==a[x]&&r2.qry(mid, x)==a[x])
				rb=mid;
			else
				lb=mid+1;
		}
		l[x]=lb;
		lb=x, rb=n-1;
		while(lb<rb) {
			int mid=(lb+rb+1)/2;
			if (r1.qry(x, mid)==a[x]&&r2.qry(x, mid)==a[x])
				lb=mid;
			else
				rb=mid-1;
		}
		r[x]=lb;
	}
	iota(par, par+n, 0);
	set<int> s;
	for (int i=0; i<n-1; ++i)
		s.insert(i);
	ll ans=0;
	for (int i=0; i<n; ++i) {
		int x=id[i];
		if (a[x]>=p)
			break;
		int lb=l[x], rb=r[x];
		for (auto it=s.lower_bound(lb); it!=s.end()&&*it<rb;) {
			merge(*it, *it+1);
			it=s.erase(it);
			ans+=a[x];
		}
	}
	ans+=(ll)p*s.size();
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}