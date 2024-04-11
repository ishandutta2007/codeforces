#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int M = 1000000;

int x[M];
int y[M];
int slv[M];
int tmp1[M];
int tmp2[M];
int tmp3[M];
int tmp4[M];

void solve(int d, int u, int l, int r, int s, int e) {
	if (e - s <= 1) return;
	int hmid = (u + d) / 2;
	int vmid = (l + r) / 2;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	for (int i = s; i <= e;i++) {
		int c = slv[i];
		if (x[c] <= vmid) {
			if (y[c] <= hmid) {
				tmp1[cnt1++] = c;
			}
			else tmp2[cnt2++] = c;
		}
		else {
			if (y[c] <= hmid) tmp4[cnt4++] = c;
			else tmp3[cnt3++] = c;
		}
	}
	int j = s;
	for (int i = 0; i < cnt1; i++) slv[j++] = tmp1[i];
	for (int i = 0; i < cnt2; i++) slv[j++] = tmp2[i];
	for (int i = 0; i < cnt3; i++) slv[j++] = tmp3[i];
	for (int i = 0; i < cnt4; i++) slv[j++] = tmp4[i];
	solve(d, hmid, l, vmid, s, s + cnt1 - 1);
	s += cnt1;
	solve(hmid+1, u, l, vmid, s, s+cnt2-1);
	s += cnt2;
	solve(hmid+1, u, vmid+1, r, s,s+cnt3-1);
	s += cnt3;
	solve(d, hmid, vmid+1, r, s,s+cnt4-1);
	
	return;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		slv[i] = i;
		scanf("%d %d", x + i, y + i);
	}
	solve(0, M, 0, M, 0, n-1);
	for (int i = 0; i < n; i++) printf("%d ", slv[i] + 1);
	return 0;
}