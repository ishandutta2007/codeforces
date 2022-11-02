
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;


template<class T>
struct PSeg {
public:
	struct Vertex {
		const static T NEUTRAL = 0; //CHANGE
		static T action(const T& lhs, const T& rhs) {
			return lhs + rhs; //CHANGE
		}
		T val;
		Vertex* lptr, * rptr;
		int size = 0;
		Vertex(const T& myval) {
			val = myval;
			lptr = rptr = NULL;
			size = 1;
		}
		Vertex(const T& myval, Vertex* _lptr, Vertex* _rptr) {
			val = myval;
			lptr = _lptr;
			rptr = _rptr;
			val = action(val, _lptr->val);
			val = action(val, _rptr->val);
			size = lptr->size + rptr->size;
		}
	};
	int n;
	Vertex* head;
	PSeg() : n(0), head(NULL) {}
	PSeg(const vector<T>& arr) {
		this->a = arr;
		this->n = arr.size();
		head = build(0, n - 1);
	}
	Vertex* update(int pos, const T& val) { //updates current version
		Vertex* nhead = updateHelp(head, 0, n - 1, pos, val);
		head = nhead;
		return nhead;
	}
	Vertex* update(Vertex* myhead, int pos, const T& val) { //updates previous version
		return updateHelp(myhead, 0, myhead->size - 1, pos, val);
	}
	T query(int l, int r) {
		return queryHelp(head, l, r, 0, n - 1);
	}
	T query(Vertex* myhead, int l, int r) {
		if (l > r)return 0;
		return queryHelp(myhead, l, r, 0, myhead->size - 1);
	}
private:
	vector<T> a;
	Vertex* build(int l, int r) {
		if (l == r)
			return new Vertex(a[l]);
		int mid = (l + r) / 2;
		Vertex* lptr = build(l, mid), * rptr = build(mid + 1, r);
		return new Vertex(Vertex::NEUTRAL, lptr, rptr);
	}
	Vertex* updateHelp(Vertex* cur, int l, int r, int pos, const T& val) {
		if (l == r)
			return new Vertex(val);
		int mid = (l + r) / 2;
		Vertex* lptr = cur->lptr, * rptr = cur->rptr;
		if (pos <= mid)
			lptr = updateHelp(lptr, l, mid, pos, val);
		else
			rptr = updateHelp(rptr, mid + 1, r, pos, val);
		return new Vertex(Vertex::NEUTRAL, lptr, rptr);
	}
	T queryHelp(Vertex* cur, int l, int r, int crl, int crr) {
		if (crr<l || crl>r)
			return Vertex::NEUTRAL;
		else if (crr <= r && crl >= l)
			return cur->val;
		else {
			int mid = (crl + crr) / 2;
			return Vertex::action(queryHelp(cur->lptr, l, r, crl, mid),
				queryHelp(cur->rptr, l, r, mid + 1, crr));
		}
	}
};

const int sz = 6e5 + 5;
int n, m;
int a[sz];
vector<int> adj[sz];
int mn[sz], mx[sz];
vector<int> pvec;
vector<int> app[sz];
PSeg<int>::Vertex* version[sz];
PSeg<int>* myseg;

int main() {
    fast;
    cin >> n >> m;
    foru(i, 0, n)a[i] = n - i - 1, adj[n - i - 1].push_back(i);
    foru(i, 0, m)cin >> a[i + n], adj[--a[i + n]].push_back(i + n);
    foru(i, 0, n) 
        mn[i] = (adj[i].size() == 1 ? i : 0);
    pvec.resize(n + m);
    vector<int> prevs(n, -1);
    foru(i, 0, n + m) {
        pvec[i] = prevs[a[i]];
        prevs[a[i]] = i;
    }
	vector<int> pt(n + m, 0);
	foru(i, 0, n + m) {
		if (pvec[i] == -1)pt[i] = 1;
		else app[pvec[i]].push_back(i);
	}
	myseg = new PSeg<int>(pt);
	version[0] = myseg->head;
	foru(i, 0, n + m) {
		for (int x : app[i])myseg->update(x, 1);
		version[i + 1] = myseg->head;
	}
	foru(i, 0, n) {
		int msz = adj[i].size();
		foru(j, 1, msz) {
			int cur = adj[i][j], prv = adj[i][j - 1];
			mx[i] = max(mx[i], myseg->query(version[prv + 1], prv + 1, cur - 1));
		}
		if (adj[i].back() != n + m - 1)mx[i] = max(mx[i], myseg->query(version[adj[i].back() + 1], adj[i].back() + 1, n + m - 1));
	}
	foru(i, 0, n)cout << mn[i] + 1 << ' ' << mx[i] + 1 << '\n';
    return 0;
}