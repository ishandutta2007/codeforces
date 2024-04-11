#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, cnt[200000]={}, lim[200000]={}, sze[200000]={};
vector<int> ans[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0, a; i<n; ++i) {
		cin >> a;
		cnt[a-1]++;
	}
	for (int i=0; i<k; ++i)
		cin >> lim[i];
	
	int num=0;
	int lastcurr;
	for (int i=k-1; ~i; --i) {
		int curr=0;
		if (i<k-1&&lim[i]==lim[i+1])
			curr=lastcurr;
		while (cnt[i]) {
			if (sze[curr]==lim[i])
				curr++;
			else {
				sze[curr]++;
				ans[curr].push_back(i);
				cnt[i]--;
			}
		}
		lastcurr=curr;
		num=max(num, curr+1);
	}
	printf("%d\n", num);
	for (int i=0; i<num; ++i) {
		if (sze[i]==0)
			break;
		printf("%d", sze[i]);
		for (int j=0; j<sze[i]; ++j)
			printf(" %d", ans[i][j]+1);
		printf("\n");
	}
	return 0;
}