#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <map>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int l[25];
int m[25];
int w[25];

piii upper[531441];
piii lower[1594323];
map<pii, int> lowermap;

int pow(int n) {
	if (n == 0) return 1;
	int tmp = pow(n / 2);
	tmp = tmp*tmp;
	if (n % 2) tmp *= 3;
	return tmp;
}

void solve(int s, int k, piii *arr) {
	int pp = pow(k);
	for (int i = 0; i < pp; i++) {
		int sv = i; int A = 0; int B = 0; int C = 0;
		for (int j = 0; j < k; j++) {
			if (sv % 3 == 0) {
				A += l[s + j];
				B += m[s + j];
			}
			else if(sv%3 ==1){
				B += m[s + j];
				C += w[s + j];
			}
			else {
				A += l[s + j];
				C += w[s + j];
			}
			sv /= 3;
		}
		arr[i] = mp(mp(A, B), C);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d %d", l + i, m + i, w + i);
	int unum = n / 2;
	int lnum = n - unum;
	solve(0, unum, upper);
	solve(unum, lnum, lower);
	int punum = pow(unum);
	int plnum = pow(lnum);
	for (int i = 0; i < plnum; i++) {
		pii x = mp(lower[i].first.first - lower[i].first.second, lower[i].first.first - lower[i].second);
		auto it = lowermap.find(x);
		if (it == lowermap.end()) {
			lowermap[x] = i;
		}
		else {
			if (lower[it->second].second < lower[i].second) {
				lowermap[x] = i;
			}
		}
	}
	int ansu = -1; int ansl = -1;
	int maxval = -1000000000;
	for (int i = 0; i < punum; i++) {
		pii x = mp(upper[i].first.second - upper[i].first.first, upper[i].second - upper[i].first.first);
		auto it = lowermap.find(x);
		if (it == lowermap.end()) continue;
		else {
			int j = it->second;
			if (maxval < upper[i].second + lower[j].second) {
				ansu = i;
				ansl = j;
				maxval = upper[i].second + lower[j].second;
			}
		}
	}
	if (ansu == -1) {
		puts("Impossible"); return 0;
	}
	for (int i = 0; i < unum; i++) {
		if (ansu % 3 == 0) puts("LM");
		else if (ansu % 3 == 1) puts("MW");
		else puts("LW");
		ansu /= 3;
	}
	for (int i = 0; i < lnum; i++) {
		if (ansl % 3 == 0) puts("LM");
		else if (ansl % 3 == 1) puts("MW");
		else puts("LW");
		ansl /= 3;
	}
}