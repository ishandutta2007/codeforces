#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {return pair<int, int>(a.first+b.first, a.second+b.second);}
template<class A, class B> ostream& operator<< (ostream& out, pair<A, B> a) {
	out << '[' << a.first << ", " << a.second; return out << ']';
}
template<class A> ostream& operator<< (ostream& out, vector<A> v) {
	out << '[';
	for (int i=0; i<v.size(); ++i) {
		out << v[i];
		if (i<v.size()-1) out << ", ";
	}
	return out << "]\n";
}

const int mxN=200001;
int n;
ll ans=0;
pair<int, int> a[mxN];

template<class T> struct FenwickTree {
	ll bit[mxN+1];
	FenwickTree() {memset(bit, 0, sizeof(bit));}
	void upd(int i, T val) {for (++i; i<=n; i+=i&-i) bit[i]+=val;}
	T sum(int i) {T res=0; for (++i; i>0; i-=i&-i) res+=bit[i]; return res;}
	T sum(int l, int r) {return sum(r)-sum(l-1);}
};

void solve(vector<pair<ll, int>> v) {
	vector<int> d;
	for (auto x: v) d.push_back(x.second);
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (auto &x: v) x.second=lower_bound(d.begin(), d.end(), x.second)-d.begin();
	FenwickTree<ll> cnt, sum;
	for (int i=0; i<v.size(); ++i) {
		ans+=cnt.sum(v[i].second)*v[i].first-sum.sum(v[i].second);
		cnt.upd(v[i].second, 1);
		sum.upd(v[i].second, v[i].first);
	}
	//cout << v << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i].first;
	for (int i=0; i<n; ++i) cin >> a[i].second;
	sort(a, a+n);
	vector<pair<ll, int>> pos, neg;
	ll sum=0, cnt=0;
	for (int i=0; i<n; ++i) {
		if (a[i].second>=0) {
			pos.push_back(a[i]);
			ans+=cnt*a[i].first-sum;
		}
		else {
			neg.emplace_back(1e8-a[i].first, -a[i].second);
			sum+=a[i].first, ++cnt;
		}
	}
	solve(pos);
	reverse(neg.begin(), neg.end()); solve(neg);
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/