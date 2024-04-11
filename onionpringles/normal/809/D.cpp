#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <iterator>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)
#define FE(i,n) for(int i = 0; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
const int N = 303030;
class Node_t {
public:
	Node_t *l, *r, *p, *u;
	int val, modi;
	Node_t(int v = 0) :l(NULL), r(NULL), p(NULL), u(NULL), val(v) {}
} nds[N];
typedef Node_t* Np;
Np& L(Np nd) { return nd->l; }
Np& R(Np nd) { return nd->r; }
void push(Np nd) {
	if (L(nd))L(nd)->val += nd->modi, L(nd)->modi += nd->modi;
	if (R(nd))R(nd)->val += nd->modi, R(nd)->modi += nd->modi;
	nd->modi = 0;
}
template<typename A>
void rot(Np nd, A L, A R) {
	Np p = nd->p; Np g = p->p;
	nd->p = g; if (g) ((L(g) == p) ? L(g) : R(g)) = nd;
	p->p = nd;
	L(p) = R(nd); if (R(nd)) R(nd)->p = p;
	R(nd) = p;
}
void splay(Np nd) {
	while (nd->p) {
		Np p = nd->p;
		if (!(p->p)) {
			push(p); push(nd);
			if (L(p) == nd) rot(nd, L, R);
			else rot(nd, R, L);
		}
		else {
			Np g = p->p;
			push(g); push(p); push(nd);
			if (L(g) == p) {
				if (L(p) == nd) {
					rot(p, L, R); rot(nd, L, R);
				}
				else {
					rot(nd, R, L); rot(nd, L, R);
				}
			}
			else {
				if (R(p) == nd) {
					rot(p, R, L); rot(nd, R, L);
				}
				else {
					rot(nd, L, R); rot(nd, R, L);
				}
			}
		}
	}
	push(nd);
}
Np Ins(Np rt, Np nd) {
	if (rt == NULL) {
		return nd;
	}
	while (1) {
		push(rt);
		if (rt->val > nd->val) {
			if (L(rt))rt = L(rt);
			else {
				L(rt) = nd;
				nd->p = rt; break;
			}
		}
		else {
			if (R(rt))rt = R(rt);
			else {
				R(rt) = nd;
				nd->p = rt; break;
			}
		}
	}
	splay(nd);
	return nd;
}
Np getMax(Np r) {
	if (r == NULL)return r;
	while (R(r)) {
		push(r); r = R(r);
	}
	splay(r);
	return r;
}
Np Lb(Np& r, int v) {
	if (r == NULL)return NULL;
	r = getMax(r); if (r->val < v) return NULL;
	Np rt = r;
	Np res = NULL;
	while (rt) {
		push(rt);
		if (rt->val >= v) {
			res = rt;
			rt = L(rt);
		}
		else {
			rt = R(rt);
		}
	}
	splay(res);
	return r = res;
}
Np Merge(Np nd1, Np nd2) {
	if (!nd1) return nd2;
	nd1 = getMax(nd1);
	R(nd1) = nd2;
	if (nd2)nd2->p = nd1;
	return nd1;
}
Np Del(Np nd) {
	splay(nd);
	Np Le = L(nd);
	Np Ri = R(nd);
	if(Le) Le->p = NULL;
	if(Ri) Ri->p = NULL;
	return Merge(Le, Ri);
}
Np add1(Np x, Np y) {
	splay(x);
	Np left = L(x);
	L(x) = NULL;
	if (left)left->p = NULL;
	if (y) {
		splay(y);
		if (L(y)) {
			L(y)->val++;
			L(y)->modi++;
		}
		return Merge(left, y);
	}
	else {
		x->val++;
		x->modi++;
		return Merge(left, x);
	}
}
int getsz(Np nd) {
	if (!nd)return 0;
	else return getsz(L(nd)) + getsz(R(nd)) + 1;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	Np rt = NULL;
	F(i, n) {
		int l, r; nii(l, r);
		nds[i] = Node_t(l);
		Np Le = Lb(rt, l);
		Np Ri = Lb(rt, r);
		if (Le == NULL) {
			rt = Ins(rt, nds + i);
			continue;
		}
		rt = add1(Le, Ri);
		if(Ri) rt = Del(Ri);
		rt = Ins(rt, nds + i);
	}
	printf("%d\n", getsz(rt));
}