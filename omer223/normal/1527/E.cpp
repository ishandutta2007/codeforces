
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

/*
Author: Omer223
Purpose: Persistent segment tree using pointers.
Date: 28/03/2021
Confirmed: Yes, self tests and https://codeforces.com/contest/786/problem/C.
*/
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

const int sz = 1e5 + 5;
int n, k;
int a[sz], val[sz];
vector<int> prv[sz];
int crprv[sz];
PSeg<ll>::Vertex* version[sz];
PSeg<ll>* myseg;
ll dp[sz], prvdp[sz];
int nxt[sz];

inline ll cost(int i, int j) {
	if (i > j)return 0;//opt
	return myseg->query(version[i], i, j);
}

void dnc(int l, int r, int optl, int optr) {
	if (l > r)return;
	int mid = (l + r) / 2, st = min(mid,optr);
	ll bst = 1e17, tmp, crcost = cost(min(mid, optr), mid);
	int bsti = -1;
	for (int i = st; i >= optl; i--) {
		if (i == st) {
			crcost = cost(min(mid, optr), mid);
		}
		else {
			if (nxt[i] <= mid)crcost += (nxt[i] - i);
		}
		tmp = crcost + prvdp[i - 1];
		if (tmp <= bst) {
			bst = tmp;
			bsti = i;
		}
	}
	dp[mid] = bst;
	dnc(l, mid - 1, optl, bsti);
	dnc(mid + 1, r, bsti, optr);
}

int main() {
	fast;
	cin >> n >> k;
	foru(i, 0, n)cin >> a[i];
	foru(i, 0, sz)crprv[i] = -1;
	foru(i, 0, n) {
		if (crprv[a[i]] != -1) {
			val[i] = (i - crprv[a[i]]);
			prv[crprv[a[i]]].push_back(i);
		}
		else {
			val[i] = 0;
		}
		crprv[a[i]] = i;
	}
	vector<ll> v(n, 0);
	myseg = new PSeg<ll>(v);
	ford(i, n - 1, 0) {
		for (int x : prv[i]) myseg->update(x, val[x]);
		version[i] = myseg->head;
	}
	ll cumsum = 0;
	foru(i, 0, n) {
		cumsum += val[i];
		prvdp[i] = cumsum;
		dp[i] = 1e15;
	}
	foru(i, 0, sz)crprv[i] = -1;
	ford(i, n - 1, 0) {
		if (crprv[a[i]] != -1)nxt[i] = crprv[a[i]];
		else nxt[i] = 1e6;
		crprv[a[i]] = i;
	}
	foru(iter, 1, k) {
		dnc(iter, n - 1, iter, n - 1);
		foru(i, 0, n)prvdp[i] = dp[i];
	}
	cout << prvdp[n - 1];
	return 0;
}