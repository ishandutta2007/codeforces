#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <bitset>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
struct PSeg {
public:
	struct Vertex {
		const static T NEUTRAL = 0; //CHANGE
		static T action(const T& lhs, const T& rhs) {
			return lhs + rhs; //CHANGE
		}
		T val;
		Vertex* lptr, *rptr;
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
	int querySum(Vertex* myhead, int l, int r) {
		if (l > r || l < 0)return 0;
		return queryHelp(myhead, l, r, 0, myhead->size - 1);
	}
	int queryPos(Vertex* myhead, int k) {
		return qhelp(myhead, k, 0, n - 1);
	}
private:
	vector<T> a;
	Vertex* build(int l, int r) {
		if (l == r)
			return new Vertex(a[l]);
		int mid = (l + r) / 2;
		Vertex* lptr = build(l, mid), *rptr = build(mid + 1, r);
		return new Vertex(Vertex::NEUTRAL, lptr, rptr);
	}
	Vertex* updateHelp(Vertex *cur, int l, int r, int pos, const T& val) {
		if (l == r)
			return new Vertex(val);
		int mid = (l + r) / 2;
		Vertex* lptr = cur->lptr, *rptr = cur->rptr;
		if (pos <= mid)
			lptr = updateHelp(lptr, l, mid, pos, val);
		else
			rptr = updateHelp(rptr, mid + 1, r, pos, val);
		return new Vertex(Vertex::NEUTRAL, lptr, rptr);
	}
	int queryHelp(Vertex* cur, int l, int r, int crl, int crr) {
		if (crr<l || crl>r)
			return 0;
		else if (crr <= r && crl >= l)
			return cur->val;
		else {
			int mid = (crl + crr) / 2;
			return queryHelp(cur->lptr, l, r, crl, mid) +
				queryHelp(cur->rptr, l, r, mid + 1, crr);
		}
	}
	int qhelp(Vertex* cur, int k, int l, int r) {
		if (l == r) {
			if (!k)
				return l - (cur->val > 0);
			else
				return 1e9;
		}
		else {
			int mid = (l + r) / 2, lsm = cur->lptr->val;
			if(lsm<=k)
				return qhelp(cur->rptr, k - lsm, mid + 1, r);
			else
				return qhelp(cur->lptr, k, l, mid);
		}
	}
};

const int sz = 1e5 + 5;
int a[sz], nxt[sz], n;
PSeg<int>::Vertex* version[sz];

void input() {
	scanf("%d", &n);
	foru(i, 0, n)
		scanf("%d", &a[i]);
}

PSeg<int>* myseg;

int getNext(int i, int k) {
	int tmp = myseg->querySum(version[i], 0, i - 1);
	return myseg->queryPos(version[i], tmp + k) + 1;
}

int main() {
	fast;
	input();
	vector<int> v(n, 0);
	myseg = new PSeg<int>(v);
	foru(i, 0, n + 1)nxt[i] = -1;
	ford(i, n - 1, 0) {
		if (nxt[a[i]] != -1)myseg->update(nxt[a[i]], 0);
		myseg->update(i, 1);
		version[i] = myseg->head;
		nxt[a[i]] = i;
	}
	for (int k = 1; k <= n; k++) {
		int pos = 0, ret = 0;
		while (pos < n) {
			ret++;
			pos = getNext(pos, k);
		}
		printf("%d ", ret);
	}
	return 0;
}