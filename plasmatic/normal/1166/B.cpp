//============================================================================
// Name        : problem2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Scan and Debug
void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F f, R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)

const int MAX = 100001, MINV = 5;
const char EXT = 'g', VOWS[5] = {'a', 'e', 'i', 'o', 'u'};
int k, n = -1, m = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scan(k);

	for (int i = 1; i <= k; i++) {
		if (k % i == 0) {
			int ot = k / i;
			if (i >= MINV && ot >= MINV) {
				n = i;
				m = ot;
				break;
			}
		}
	}

	if (n == -1 && m == -1) {
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++)
			printf("%c", VOWS[(i + j) % 5]);
	}
	printf("\n");

	return 0;
}