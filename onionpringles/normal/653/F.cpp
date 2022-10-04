#pragma warning(disable:4996)

#include <stdio.h>
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
#define F(i,n) for(int i = 0; i < n; i++)
#define FF(i,n) for(int i = 1; i <= n; i++)
#define println(x) printf("%d\n", x);
#define print(x) printf("%d ", x);

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int MAXN = 500005;
class SuffixArray {
public:
	int tmpA[7 * MAXN / 10]; //length of tmpA, tmpB must be at least num+1
	int tmpB[7 * MAXN / 10];
	int cnt[MAXN + 2];
	int SAV[MAXN];
	int mem[5 * MAXN];
	int* mem_pt = mem;
	int* m_calloc(size_t sz) {
		int* ret = mem_pt;
		mem_pt = mem_pt + sz;
		return ret;
	}
	inline void rsort(int* a, int* b, int* dat, int n, int k) { //n is the equal to the array length of a, b
		for (int i = 0; i <= k + 1; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++) {
			SAV[i] = dat[a[i]];
			cnt[SAV[i] + 1]++;
		}
		int sv = 0;
		for (int i = 1; i <= k + 1; i++) {
			cnt[i] += sv;
			sv = cnt[i];
		}
		for (int i = 0; i < n; i++) {
			b[cnt[SAV[i]]++] = a[i];
		}
	}

	//str must consist of integers from 1 to k
	//the size of str must be about n+3
	void make(int* str, int* SA, int n, int k) {
		if (n == 0) return;

		int num1 = (n + 2) / 3;
		int num2 = n / 3;
		int num = num1 + num2;
		str[n] = str[n + 1] = str[n + 2] = 0;

		int *newSA = m_calloc(num);
		int *newstr = m_calloc(num + 3);
		for (int i = 0, j = 0; i < n; i++) {
			if (i % 3) tmpA[j++] = i;
		}
		if (n % 3 == 1) tmpA[num - 1] = n;
		int kp = k + 1;
		long long p2 = (long long)kp*kp;
		long long p3 = p2*kp;

		if (kp > 2000000 || num <= p3) {

			rsort(tmpA, tmpB, str + 2, num, k);
			rsort(tmpB, tmpA, str + 1, num, k);
			rsort(tmpA, tmpB, str, num, k);

			int cnt = 1;
			if (tmpB[0] % 3 == 1) newstr[tmpB[0] / 3] = 1;
			else newstr[tmpB[0] / 3 + num1] = 1;
			for (int i = 1; i < num; i++) {
				int cur = tmpB[i];
				int past = tmpB[i - 1];
				if (str[past] != str[cur] || str[past + 1] != str[cur + 1] || str[past + 2] != str[cur + 2]) cnt++;
				if (cur % 3 == 1) newstr[cur / 3] = cnt;
				else newstr[cur / 3 + num1] = cnt;
			}
			if (cnt == num) {
				for (int i = 0; i < num; i++) newSA[newstr[i] - 1] = i;
			}
			else make(newstr, newSA, num, cnt);
		}
		else {
			int j = 0;
			for (int i = 1; i <= n; i += 3) {
				newstr[j++] = str[i] * (int)p2 + str[i + 1] * (int)kp + str[i + 2] + 1;
			}
			for (int i = 2; i<n; i += 3) {
				newstr[j++] = str[i] * (int)p2 + str[i + 1] * (int)kp + str[i + 2] + 1;
			}

			make(newstr, newSA, num, (int)p3);
		}


		for (int i = 0, j = 0; i < num; i++) {
			if (newSA[i] < num1) tmpA[j++] = 3 * newSA[i];
		}
		rsort(tmpA, tmpB, str, num1, k);
		for (int i = 0, j = 0; i < num; i++) tmpA[newSA[i]] = i;
		tmpA[num] = -1;

		int it1 = 0; //tmpB
		int it2 = 0; //newSA
		if (n % 3 == 1) it2++;
		int j = 0;
		while (1) {
			if (it1 == num1) {
				for (; it2 < num; it2++) {
					if (newSA[it2] < num1) SA[j++] = 3 * newSA[it2] + 1;
					else SA[j++] = 3 * (newSA[it2] - num1) + 2;
				}
				break;
			}
			else if (it2 == num) {
				for (; it1 < num1; it1++) SA[j++] = tmpB[it1];
				break;
			}
			else if (newSA[it2] < num1) {
				int ind1 = tmpB[it1];
				int ind2 = 3 * newSA[it2] + 1;
				if (str[ind1] < str[ind2] || str[ind1] == str[ind2] && tmpA[ind1 / 3] < tmpA[num1 + ind2 / 3]) {
					SA[j++] = ind1;
					it1++;
				}
				else {
					SA[j++] = ind2;
					it2++;
				}
			}
			else {
				int ind1 = tmpB[it1];
				int ind2 = 3 * (newSA[it2] - num1) + 2;
				if (ind2 == n - 1) {
					if (str[ind1] < str[ind2]) {
						SA[j++] = ind1;
						it1++;
					}
					else {
						SA[j++] = ind2;
						it2++;
					}
				}
				else if (str[ind1] < str[ind2] || str[ind1] == str[ind2] && str[ind1 + 1] < str[ind2 + 1] || str[ind1] == str[ind2] && str[ind1 + 1] == str[ind2 + 1]
					&& tmpA[ind1 / 3 + num1] < tmpA[(ind2 + 1) / 3]) {
					SA[j++] = ind1;
					it1++;
				}
				else {
					SA[j++] = ind2;
					it2++;
				}
			}
		}
		//		fputs("ret\n",stderr);
		return;
	}
}sa;

char buf[500010];
int str[500010];
int SA[500010];
int rnk[500010];
int lcp[500010];
int dyn[500010];
vector<pii> pts[1000010];

int upper_bound(int val, vector<pii>& x) {
	int l = 0; int u = x.size();
	while (l != u) {
		int m = (l + u) / 2;
		if (x[m].first > val) u = m;
		else l = m + 1;
	}
	return u;
}

int get(int l, int r) {
	if (l >= r) return 0;
	int val = dyn[l] + 500001;
	int u = upper_bound(l, pts[val - 1]);
	if (u != pts[val - 1].size()) {
		r = min(r, pts[val - 1][u].first);
	}

	int lu = upper_bound(l, pts[val]);
	int ru = upper_bound(r, pts[val]);
	return ru - lu;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	scanf("%s", buf);

	F(i,n) {
		str[i] = (buf[i] == '(')?1:2;
	}
	sa.make(str, SA, n, 2);

	F(i,n) {
		rnk[SA[i]] = i;
	}

	int k = 0;
	F(i,n) {
		if (rnk[i] == n - 1) {
			k = 0; continue;
		}
		int ni = SA[rnk[i] + 1];
		while (i + k < n && ni + k < n && str[i + k] == str[ni + k]) k++;
		lcp[i] = k;
		if (k) k--;
	}
	dyn[0] = 0;
	FF(i,n) dyn[i] = dyn[i - 1] + ((buf[i - 1] == '(') ? 1 : -1);
	F(i,n+1) {
		int val = dyn[i] + 500001;
		pts[val].push_back(mp(i, pts[val].size()));
	}
	ll ans = 0;
	F(i,n){
		ans += get(i, n) - get(i, i+lcp[i]);
	}
	printf("%I64d", ans);
	return 0;
}