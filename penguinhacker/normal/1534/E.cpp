#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#define debug(x) cerr << "[" << #x << "] = [" << x << "]\n"

template<class T> ostream& operator<< (ostream& out, vector<T> v) {
	out << '[';
	for (int i = 0; i < v.size(); ++i) {
		if (i > 0) {
			out << ", ";
		}
		out << v[i];
	}
	return out << ']';
}

template<class T> ostream& operator<< (ostream& out, set<T> v) {
	return out << vector<T>(v.begin(), v.end());
}

template<class A, unsigned int sz> ostream& operator<< (ostream& out, ar<A, sz> a) {
	out << '[';
	for (int i = 0; i < sz; ++i) {
		if (i > 0) out << ", ";
		out << a[i];
	}
	return out << ']';
}

template<class A, class B> ostream& operator<< (ostream& out, pair<A, B> p) {
	return out << '[' << p.first << ", " << p.second << ']';
}

template<class A, class B> ostream& operator<< (ostream& out, map<A, B> mp) {
	return out << vector<pair<A, B>>(mp.begin(), mp.end());
}

int n, k, d[501], p[501];
vector<int> last[501];
vector<vector<int>> ans;

void bfs() {
	queue<vector<int>> q;
	q.push({});
	//debug(v);
	while(q.size()) {
		vector<int> v=q.front();
		q.pop();
		vector<int> v2;
		vector<bool> seen(n);
		for (int i : v)
			seen[i]=1;
		for (int i=0; i<n; ++i)
			if (!seen[i])
				v2.push_back(i);
		for (int i=0; i<=min(k, (int)v.size()); ++i) { // take i from v
			int nc=v.size()-i+(k-i);
			if (!(d[nc]==-1&&k-i<=v2.size()))
				continue;
			vector<int> nv;
			vector<int> path;
			for (int j=0; j<i; ++j)
				path.push_back(v[j]);
			for (int j=i; j<v.size(); ++j)
				nv.push_back(v[j]);
			for (int j=0; j<k-i; ++j) {
				nv.push_back(v2[j]);
				path.push_back(v2[j]);
			}
			assert(nv.size()==nc);
			assert(path.size()==k);
			d[nc]=d[v.size()]+1;
			p[nc]=v.size(), last[nc]=path;
			q.push(nv);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	memset(d, -1, sizeof(d));
	d[0]=0;
	bfs();
	if (d[n]==-1) {
		cout << -1;
		return 0;
	}
	int cur=n;
	while(cur) {
		ans.push_back(last[cur]);
		cur=p[cur];
	}
	reverse(ans.begin(), ans.end());
	int xum=0;
	for (vector<int>& v : ans) {
		cout << "?";
		for (int i : v)
			cout << " " << i+1;
		cout << endl;
		int x;
		cin >> x;
		xum^=x;
	}
	cout << "! " << xum;
	return 0;
}