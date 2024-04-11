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

char buf[101010];

int val[101010];
int pref[101010];
int n;
void calc() {
	pref[0] = val[0];
	FF(i, n - 1) pref[i] = pref[i - 1] + val[i];
}
int get(int l, int r) {
	if (l == 0) return pref[r];
	else return pref[r] - pref[l - 1];
}
int ccnt[26];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int m; ni(m);
	scanf("%s", buf);
	n = strlen(buf);
	F(cc, 26) {
		char c = 'a' + cc;
		bool good = true;
		int cnt = 0;
		F(i, m - 1) {
			cnt += (buf[i] == c);
		}
		F(i, n - m + 1) {
			if (i) cnt -= (buf[i - 1] == c);
			cnt += (buf[i + m - 1] == c);
			if (cnt + get(i, i + m - 1) == 0) {
				good = false;
				break;
			}
		}
		if (!good) {
			cnt = 0;
			F(i, n) {
				if (buf[i] == c) {
					cnt++;
					val[i]++;
				}
			}
			calc();
			ccnt[cc] = cnt;
			continue;
		}
		else {
			vector<int> pos;
			F(i, n) if (buf[i] == c)pos.push_back(i);
			int sz = pos.size();
			int cur = 0;
			F(i, n - m + 1) {
				if (get(i, i + m - 1) == 0) {
					while (cur < sz && pos[cur] <= i + m - 1) cur++;
					ccnt[cc]++;
					i = pos[cur - 1];
				}
			}
			break;
		}
	}
	F(i, 26) {
		F(j, ccnt[i]) {
			printf("%c", 'a' + i);
		}
	}
	puts("");
	return 0;
}