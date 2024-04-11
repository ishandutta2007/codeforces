#include <bits/stdc++.h>
using namespace std;

int N;
char S[500005];

long long f(int s, int e) {
	if (s > e) return 0;
	if (s == e) return S[s] == '1';
	int m = (s + e) / 2;
	long long ans = f(s, m) + f(m+1, e);
	long long curchain = 0, mx = 0, leftextend = 0, rightextend = 0;
	bool lbroke = 0, rbroke = 0;
	vector<int> lefts, rights;
	
	for (int i = m; i >= s; i--) {
		if (S[i] == '1') {
			curchain++;
			if (!lbroke) leftextend++;
		}
		else {
			curchain = 0;
			lbroke = 1;
		}
		mx = max(mx, curchain);
		lefts.push_back(mx);
	}
	
	curchain = mx = 0;
	for (int i = m+1; i <= e; i++) {
		if (S[i] == '1') {
			curchain++;
			if (!rbroke) rightextend++;
		}
		else {
			curchain = 0;
			rbroke = 1;
		}
		mx = max(mx, curchain);
		rights.push_back(mx);
	}
	
	vector<long long> rprefixsum;
	long long cur = 0;
	for (int i = 0; i < rights.size(); i++) {
		cur += rights[i];
		rprefixsum.push_back(cur);
	}
	
	for (int i = 0; i < lefts.size(); i++) {
		long long lmax = lefts[i];
		long long actleftextend = min((long long)i + 1, leftextend);
		long long curans = 0;
		if (rightextend > 0) {
			if (lmax <= actleftextend + 1) {
				curans += ((actleftextend + 1) + (actleftextend + rightextend)) * rightextend / 2;
			} else if (lmax >= actleftextend + rightextend) {
				curans += lmax * rightextend;
			} else {
				int leftcount = (lmax - actleftextend);
				curans += lmax * leftcount + ((actleftextend + leftcount + 1) + (actleftextend + rightextend)) * (rightextend - leftcount) / 2;
			}
		}
		long long gmax = max(lmax, actleftextend + rightextend);
		int cut = upper_bound(rights.begin() + rightextend, rights.end(), gmax) - rights.begin();
		curans += gmax * (cut - rightextend);
		curans += rprefixsum.back() - ((cut == 0) ? 0 : rprefixsum[cut - 1]);
		//printf("lmax = %lld, leftextend = %lld, rightextend = %lld, %d, %lld\n", lmax, actleftextend, rightextend, i, curans);
		ans += curans;
	}
	//printf("(%d, %d) = %lld\n", s, e, ans);
	return ans;
}

int main() {
	scanf("%d", &N);
	scanf(" %s", S);
	printf("%lld\n", f(0, N-1));
}