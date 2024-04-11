#include <bits/stdc++.h>
using namespace std;

int N;
bool has[1005];

int roundtable(int x) {
	if (x <= N) return x;
	else return (x - 1) % N + 1;
}

vector<int> ordering;

int main() {
	scanf("%d", &N);
	int prevcnt = 0;
	int mxfac = -1;
	int mxcnt = -1;
	for (int i = 1; i <= N; i++) {
		int other = N / i;
		if (i > other) continue;
		int value = 0;
		for (int j = 0; j < N; j++) if (j % i != 0) value++;
		if (value > mxcnt) {
			mxcnt = value;
			mxfac = i;
		}
	}
	
	if (mxcnt <= 0) {
		printf("0\n");
		fflush(stdout);
		return 0;
	}
	
	for (int j = 0; j < N; j++) {
		if (j % mxfac != 0) 
			ordering.push_back(j+1);
	}

	while (1) {
		vector<int> query;
		for (int i = 0; i < ordering.size(); i++) {
			if (!has[ordering[i]] && query.size() < mxfac) {
				query.push_back(ordering[i]);
				has[ordering[i]] = 1;
			}
		}
		printf("%d", query.size());
		for (int i = 0; i < query.size(); i++) printf(" %d", query[i]);
		printf("\n");
		fflush(stdout); 
		
		
		int x;
		scanf("%d", &x);
		for (int i = 0; i < query.size(); i++) has[roundtable(x + i)] = 0;
		int newcnt = 0;
		for (int i = 1; i <= N; i++) {
			if (has[i]) newcnt++;
		}
		if (newcnt <= prevcnt || newcnt >= mxcnt) {
			printf("0\n");
			fflush(stdout);
			return 0;
		}
		prevcnt = newcnt;
	}
}