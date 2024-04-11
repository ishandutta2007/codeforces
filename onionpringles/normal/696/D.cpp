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

const int CHAR = 26;
const int N = 220;

#define CONVERT(c) (c)-'a'
class AhoCora {
public:
	struct Node {
		int ch[CHAR];
		int link;
		vector<int> dic;
	}nd[N];
	int Q[N]; int qs, qe;
	int size;
	int createNode() {
		int ret = size++;
		for (int i = 0; i<CHAR; i++) {
			nd[ret].ch[i] = -1;
		}
		return ret;
	}
	void init() {
		size = 0;
		createNode();
	}
	template<typename A>
	void add(A str, int sz, int id) {
		int cur = 0;
		for (int i = 0; i<sz; i++) {
			int c = CONVERT(str[i]);
			if (nd[cur].ch[c] == -1) {
				int nnd = createNode();
				nd[cur].ch[c] = nnd;
			}
			cur = nd[cur].ch[c];
		}
		nd[cur].dic.push_back(id);
	}
	inline int next(int u, int c) {
		while (u&&nd[u].ch[c]<0)
			u = nd[u].link;
		if (nd[u].ch[c]<0)return 0;
		else return nd[u].ch[c];
	}
	void computelink() {
		qs = qe = 0;
		nd[0].link = 0;
		for (int x, i = 0; i<CHAR; i++) {
			if ((x = nd[0].ch[i]) >= 0) {
				Q[qe++] = x;
				nd[x].link = 0;
			}
		}
		while (qs<qe) {
			int u = Q[qs++];
			for (int v, i = 0; i<CHAR; i++) {
				if ((v = nd[u].ch[i]) >= 0) {
					Q[qe++] = v;
					int m = nd[u].link;
					int L = nd[v].link = next(m, i);
					nd[v].dic.insert(nd[v].dic.end(), nd[L].dic.begin(), nd[L].dic.end());
				}
			}
		}
	}
}acc;


char buf[200][220];
int a[200];

const int M =5000;

int ndn;
int go[N][26];
int sa[N];
int dp[M+1][N];
int dpm[M+1];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ll l;
	ni(n); scanf("%I64d", &l);
	F(i, n) {
		ni(a[i]);
	}
	acc.init();
	F(i, n) {
		scanf("%s", buf[i]);
		acc.add(buf[i], strlen(buf[i]), i);
	}
	acc.computelink();
	int ndn = acc.size;
	F(i, ndn) {
		F(j, CHAR) {
			go[i][j] = acc.next(i, j);
		}
	}
	F(i, ndn) {
		for (auto &x : acc.nd[i].dic) sa[i] += a[x];
	}
	F(t, M+1)F(i, ndn)dp[t][i] = -1;
	dp[0][0] = 0;
	F(t, M) {
		F(i, ndn) {
			if (dp[t][i] == -1)continue;
			F(j, CHAR) {
				int ni = go[i][j];
				dp[t + 1][ni] = max(dp[t + 1][ni], dp[t][i] + sa[ni]);
			}
		}
	}
	F(i, M+1)dpm[i] = *max_element(dp[i], dp[i] + ndn);
	if (l <= M) {
		printf("%d\n", dpm[l]);
		return 0;
	}
	int ii = -1;
	for (int i = (M+1)/2; i < M; i++) {
		bool bad = false;
		int X = dpm[M] - dpm[i];
		for (int j = 0; j < M - i; j++) {
			if (dpm[i + j] - dpm[2 * i - M + j] != X) {
				bad = true; break;
			}
		}
		if (!bad) {
			ii = i; break;
		}
	}
	if (ii == -1) {
		assert(0);
	}
	int T = M - ii;
	int rem = (l-ii)%T;
	ll qq = (l - ii) / T;
	int X = dpm[M] - dpm[ii];
	printf("%I64d\n", X*qq + dpm[ii + rem]);
}