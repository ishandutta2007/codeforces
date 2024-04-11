#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;

using namespace std;

const int dd = (int)2e5 + 7;

struct p {
	int x, y, x2, y2;
} A[dd];

int pxl[dd], pyl[dd], pxr[dd], pyr[dd];
int sxl[dd], syl[dd], sxr[dd], syr[dd];

void check(int x, int x2, int y, int y2) {
	if (x <= x2 && y <= y2) {
		cout << x << " " << y << "\n";
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> A[i].x >> A[i].y >> A[i].x2 >> A[i].y2;
	}
	pxl[0] = A[0].x, pxr[0] = A[0].x2; 
	pyl[0] = A[0].y, pyr[0] = A[0].y2;
	for (int i = 1; i < n; ++i) {
		pxl[i] = max(pxl[i - 1], A[i].x);
		pxr[i] = min(pxr[i - 1], A[i].x2);
		pyl[i] = max(pyl[i - 1], A[i].y);
		pyr[i] = min(pyr[i - 1], A[i].y2);
	}

	sxl[n - 1] = A[n - 1].x, sxr[n - 1] = A[n - 1].x2; 
	syl[n - 1] = A[n - 1].y, syr[n - 1] = A[n - 1].y2;
	for (int i = n - 2; i >= 0; --i) {
		sxl[i] = max(sxl[i + 1], A[i].x);
		sxr[i] = min(sxr[i + 1], A[i].x2);
		syl[i] = max(syl[i + 1], A[i].y);
		syr[i] = min(syr[i + 1], A[i].y2);
	}

	check(pxl[n - 2], pxr[n - 2], pyl[n - 2], pyr[n - 2]);
	check(sxl[1], sxr[1], syl[1], syr[1]);

	for (int i = 1; i < n - 1; ++i) {
		check(max(pxl[i - 1], sxl[i + 1]), min(pxr[i - 1], sxr[i + 1]), max(pyl[i - 1], syl[i + 1]), min(pyr[i - 1], syr[i + 1]));
	}
	return 0;
}