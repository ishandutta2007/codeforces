#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <vector>
#define mp(a,b) make_pair(a,b)
#define ni(a) scanf("%d", &(a))
#define F(i,n) for(int (i) = 0; (i) < (n); (i)++)

using namespace std;
typedef pair<int, int> pii;

pii a[100000];
long long upmin[100001];
long long maxlev[100001];
int res[100000];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, A, cf, cm; long long m;
	scanf("%d %d %d %d %I64d", &n, &A, &cf, &cm, &m);
	F(i, n) {
		int aa; ni(aa);
		a[i] = mp(aa, i);
	}
	sort(a, a + n);
	F(i, n + 1) {
		if (i == 0) upmin[0] = 0;
		else if (i == 1) upmin[i] = 0;
		else {
			upmin[i] = upmin[i - 1] + (long long)(i - 1)*(a[i - 1].first - a[i - 2].first);
		}
	}
	F(i, n + 1) {
		int j = n - i;
		if (i == 0) maxlev[j] = 0;
		else {
			maxlev[j] = maxlev[j + 1] + (A - a[j].first);
		}
	}
	int goodl, goodr;
	int curl, curr;
	curl = 0; curr = 0;
	long long maxval = -1; int goodminval;
	for (; curr < n + 1; curr++) {
		long long rem = m - maxlev[curr];
		if (rem < 0) continue;
		while (curl <= curr && upmin[curl] <= rem) {
			curl++;
		}
		curl--;
		long long curminval = A;
		if(curl>0)curminval =  a[curl - 1].first;
		rem -= upmin[curl];
		if (curl > 0) {
			long long q = rem / curl;
			curminval += q;
			curminval = min(curminval, (long long)A);
		}
		long long F = curminval * cm;
		long long M = (n - curr)*cf;
		if (maxval < M + F) {
			goodl = curl;
			goodr = curr;
			maxval = M + F;
			goodminval = curminval;
		}
	}
	F(i, n) {
		res[a[i].second] = a[i].first;
	}
	F(i,goodl) {
		res[a[i].second] = goodminval;
	}
	F(i,  n - goodr) {
		int j = n - 1 - i;
		res[a[j].second] = A;
	}
	printf("%I64d\n", maxval);
	F(i, n) printf("%d ", res[i]);
	return 0;
}