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
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int  N = 200000;
char stk[N]; int sp;
int cur;
char buf[N];
set<pair<int, int> > S;

int s = -1, e = -1, ans = 0;
int stk2[N]; int sp2;
int dp[N]; int dp2[N];
int num[N];
void solve(int s, int e) {
	int cur = 0;
	for (int i = s;; i++) {
		dp[i] = cur;
		S.insert(make_pair(cur, i));
		if (i == e) break;
		if (buf[i] == '(' || buf[i] == '[') cur++;
		else cur--;
	}
	sp2 = 0;
	for (int i = e; i >= s; i--) {
		while (sp2 > 0) {
			int t = stk2[sp2 - 1];
			if (dp[t] >= dp[i])sp2--;
			else break;
		}
		if (sp2 == 0) dp2[i] = inf;
		else dp2[i] = stk2[sp2 - 1];
		stk2[sp2++] = i;
	}
	for (int i = s; i < e; i++) {
		auto it = S.lower_bound(make_pair(dp[i], dp2[i]));
		it--;
		if (it->second == i) continue;
		int ni = it->second;
		int g = num[ni] - num[i];
		if (g > ans) {
			::s = i;
			::e = ni;
			ans = g;
		}
	}
	S.clear();
	for (int i = s; i <= e; i++)dp[i] = dp2[i] = 0;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", buf);
	int n = strlen(buf);
	FF(i, n)num[i] = num[i - 1] + (buf[i - 1] == '[');
	cur = 0;
	F(i, n) {
		if (buf[i] == '(' || buf[i]=='[') {
			stk[sp++] = buf[i];
			continue;
		}
		else if(buf[i]==')'){
			if (sp == 0 || stk[sp - 1] != '(') {
				solve(cur, i);
				if (cur == i) {
					cur = i + 1; sp = 0;
					continue;
				}
				cur = i;
				i--; sp = 0;
				continue;
			}
			else sp--;
		}
		else {
			if (sp == 0 || stk[sp - 1] != '[') {
				solve(cur, i);
				if (cur == i) {
					cur = i + 1; sp = 0;
					continue;
				}
				cur = i;
				i--; sp = 0;
				continue;
			}
			else sp--;
		}
	}
	solve(cur, n);
	printf("%d\n", ans);
	for (int i = s; i < e; i++)printf("%c", buf[i]);
	puts("");
}