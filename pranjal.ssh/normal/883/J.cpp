#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}


const int N = 1e5 + 10;
int A[N], B[N], P[N], ps[N];
ll bt[N];
int n, m;
int st[4*N+50];

void upd(int i, int x) {
	while (i <= n) bt[i]+=x, i += i&-i;
}
ll qry(int i) {
	ll ans = 0;
	while (i > 0) ans += bt[i], i -= i&-i;
	return ans;
}
int query(int no, int l, int r, int x) {
	if (st[no] < x) return -1;
	if (l == r) return l;
	int mid = (l+r)>>1;
	if (st[2*no+1] >= x) return query(2*no+1, mid+1, r, x);
	return query(2*no, l, mid, x);
}
void make(int no, int l, int r) {
	if (l == r) {
		st[no] = A[l];
	} else {
		int mid = (l + r) >> 1;
		make(2*no, l, mid), make(2*no+1, mid+1, r);
		st[no] = max(st[2*no], st[2*no+1]);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	vector<pair<int, int>> events;
	FOR (i, 1, n) cin >> A[i], events.emplace_back(i, A[i]);
	FOR (i, 1, m) cin >> B[i];
	FOR (i, 1, m) cin >> P[i];

	make(1, 1, n);


	FOR (it, 1, m) {
		int latest = query(1, 1, n, B[it]);
		if (latest != -1) {
			events.emplace_back(latest, -P[it]);
		}
	}

	sort(events.begin(), events.end());
	// pr(events);
	priority_queue<int> pq;
	ll tmkc = 0;
	FOR (i, 0, sz(events) - 1) {
		int j = i;
		while (j < sz(events) && events[j].F == events[i].F) ++j;
		FOR (it, i, j-1) {
			if (events[it].S > 0) tmkc += events[it].S;
			else {
				tmkc += events[it].S;
				pq.push(-events[it].S);
			}
		}
		while (tmkc < 0) tmkc += pq.top(), pq.pop();
		i = j - 1;
	}

	cout << pq.size();


	return 0;
}