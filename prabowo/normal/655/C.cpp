#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k;
char s[N];
int pre[N];
int suf[N];

int solve () {
	int ret = 2000000000;
	for (int i=0; i<n; i++)
		pre[i] = pre[i - 1] + (s[i] == '0');
		
	for (int i=0; i<n; i=upper_bound(pre, pre+n, pre[i]) - pre) {
		// cout << i << endl;
		if (pre[i] <= k) continue;
		
		int l = pre[i] - k;
		int r = pre[i];
		int ans = 2000000000;
		
		int ki = lower_bound(pre, pre + n, pre[i] - k) - pre;
		int ka = i;
		
		while (l <= r) {			
			// cout << l << " " << r << endl;
			int mid1 = lower_bound(pre, pre + n, l + (r - l) / 3) - pre;
			int mid2 = lower_bound(pre, pre + n, l + (r - l) * 2 / 3) - pre;
			
			int dist1 = max(mid1 - ki, ka - mid1);
			int dist2 = max(mid2 - ki, ka - mid2);
			
			// cout << mid1 << " " << mid2 << endl;
			
			if (dist1 < dist2) {
				ans = min(ans, dist1);
				r = l + (r - l) * 2 / 3 - 1;
			} else {
				ans = min(ans, dist2);
				l = l + (r - l) / 3 + 1;
			}
		}
		
		ret = min(ret, ans);
	}
	
	return ret;
}

int main () {
	scanf ("%d %d", &n, &k);
	getchar();
	gets (s);
	
	printf ("%d\n", solve());
	
	return 0;
	for (int i=0; i<n; i++)
		pre[i] = pre[i - 1] + (s[i] == '0');
		
	for (int i=n-1; i>=0; i--) 	
		suf[i] = suf[i + 1] + (s[i] == '0');
		
	int mini = 2000000000;
	
	int mid = k >> 1;	
	for (int i=0; i<n; i++) {
		if (s[i] == '1') continue;
		
		if (k & 1) {		
			if ((pre[i - 1] >= mid + 1) && (suf[i + 1] >= mid)) {
				int l = lower_bound (pre, pre + n, pre[i] - mid - 1) - pre;
				int r = upper_bound (suf, suf + n, suf[i] - mid, greater<int>()) - suf - 1;
				
				mini = min(mini, max(i - l, r - i));
			}
			
			if (pre[i - 1] < mid) continue;
			if (suf[i + 1] < mid + 1) continue;
			
			int l =  lower_bound (pre, pre + n, pre[i] - mid) - pre;
			int r = upper_bound (suf, suf + n, suf[i] - mid - 1, greater<int>()) - suf - 1;
			
			mini = min(mini, max(i - l, r - i));
		} else {
			if (pre[i - 1] < mid) continue;
			if (suf[i + 1] < mid) continue;
			
			int l = lower_bound (pre, pre + n, pre[i] - mid) - pre;
			int r = upper_bound (suf, suf + n, suf[i] - mid, greater<int>()) - suf - 1;
			
			// printf ("%d %d %d\n", i, l, r);
			
			mini = min(mini, max(i - l, r - i));
		}
	}
	
	return 0;
}