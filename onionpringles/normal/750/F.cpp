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

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
vector<int> adj[1 << 7];
int chk[1 << 7];
bool ask(int i) {
	printf("? %d\n",i);
	fflush(stdout);
	chk[i] = 1;
	int k; ni(k);
	F(ii, k) {
		int x; ni(x); adj[i].push_back(x);
	}
	return adj[i].size() == 2;
}
void end(int i) {
	printf("! %d\n", i);
	fflush(stdout);
	return;
}
void solve() {
	int h; ni(h);
	F(i, 1 << h) adj[i].clear();
	F(i, 1 << h) chk[i] = 0;
	int c; int vc;
#define ASK(i) {if(ask((i))){end((i));return;}}
	ASK(1);
	if (adj[1].size() == 1) {
		vc = adj[1][0];
		c = 1;
	}
	else {
		int pst = 1;
		int cur = adj[1][0];
		vector<int> V1, V2;
		while (1) {
			ASK(cur);
			V1.push_back(cur);
			if (adj[cur].size() == 1)break;
			int nx;
			if (adj[cur][0] == pst)nx = adj[cur][1];
			else nx = adj[cur][0];
			pst = cur;
			cur = nx;
		}
		pst = 1;
		cur = adj[1][1];
		while (1) {
			ASK(cur);
			V2.push_back(cur);
			if (adj[cur].size() == 1)break;
			int nx;
			if (adj[cur][0] == pst)nx = adj[cur][1];
			else nx = adj[cur][0];
			pst = cur;
			cur = nx;
		}
		c = min(V1.size(), V2.size());
		if (V1.size() == V2.size()) {
			vc = adj[1][2];
			c++;
		}
		else if (V1.size() > V2.size()) {
			int ii = (V1.size() - V2.size() - 2) / 2;
			int vv = V1[ii];
			c += ii + 2;
			F(t, 3)if (!chk[adj[vv][t]])vc = adj[vv][t];
		}
		else {
			swap(V1, V2);
			int ii = (V1.size() - V2.size() - 2) / 2;
			int vv = V1[ii];
			c += ii + 2;
			F(t, 3)if (!chk[adj[vv][t]])vc = adj[vv][t];
		}
	}
	while (1) {
		if (c == h - 1) {
			end(vc); return;
		}
		if (c == h - 2) {
			ASK(vc);
			F(t, 3)if (!chk[adj[vc][t]])ASK(adj[vc][t]);
		}
		if (c == h - 3) {
			vector<int> V;
			ASK(vc);
			F(t, 3) if (!chk[adj[vc][t]]) {
				ASK(adj[vc][t]);
				for (auto &x : adj[adj[vc][t]])if (x != vc)V.push_back(x);
			}
			F(t, 3) ASK(V[t]);
			end(V[3]);
			return;
		}
		int cur = vc;
		vector<int> V;
		while (1) {
			V.push_back(cur);
			ASK(cur);
			if (adj[cur].size() == 1)break;
			int nx;
			if (chk[adj[cur][0]])nx = adj[cur][1];
			else nx = adj[cur][0];
			cur = nx;
		}
		int A = V.size() - c;
		A /= 2;
		int ii = A;
		A++;
		int vv = V[ii];
		F(t, 3)if (!chk[adj[vv][t]])vc = adj[vv][t];
		c += A;
	}
}

int main() {
#ifndef __GNUG__
//	freopen("input.txt", "r", stdin);
#endif
	int T; ni(T);
	while (T--) {
		solve();
	}
}