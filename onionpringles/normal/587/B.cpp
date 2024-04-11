#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <map>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;

const int mod = 1000000007;

int gooddyn[1000000];
int gooddyn2[1000000];
int baddyn[1000000];
int baddyn2[1000000];

int a[1000000];

map<int,int> goodmap;
map<int, int> badmap;
map<int, int> goodind;

inline int mul(int a, int b) {
	return (long long)a*b%mod;
}

inline int add(int a, int b) {
	return ((long long)a + b) % mod;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	long long l;
	scanf("%d %I64d %d", &n, &l, &k);
	long long goodnum = l / n;
	long long badnum = l%n;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		goodmap[a[i]]++;
		if (i < badnum) badmap[a[i]]++;
	}
	int res = 0;
	int gsz = goodmap.size();
	int jj = 0;
	for (auto &x : goodmap) {
		goodind[x.first] = jj;
		jj++;
	}
	for (int i = 0; i <= k; i++) {
		if (i == 0) {
			int j = 0;
			for (auto &x : goodmap) {
				gooddyn[j] = 1;
				j++;
			}
		}
		else {
			int j = 0;
			for (auto &x : goodmap) {
				gooddyn2[j] = mul(gooddyn[j], x.second);
				j++;
			}
			j = 0; int sum = 0;
			for (auto &x : goodmap) {
				sum = add(sum, gooddyn2[j]);
				gooddyn[j] = sum;
				j++;
			}
		}
		if (i>0 && goodnum >= i) {
			int gn = (goodnum - i + 1) % mod;
			res = add(res, mul(gooddyn[gsz - 1], gn));
		}
		if (badmap.size()) {
			int bsz = badmap.size();
			int j = 0;
			for (auto &x : badmap) {
				int ind = goodind[x.first];
				baddyn[j] = mul(x.second, gooddyn[ind]);
				j++;
			}
			for (int j = 1; j < bsz; j++) {
				baddyn[j] = add(baddyn[j], baddyn[j - 1]);
			}
			if (i<k && goodnum >= i) {
				res = add(res, baddyn[bsz - 1]);
			}
		}
		
	}
	printf("%d\n", res);
	return 0;
}