#include<bits/stdc++.h>
using namespace std;



int ss[1100000];
int sum[1100000];
int a[1100000];
int main() {
	//freopen("d.in","r",stdin);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		ss[x]++;
	}
	if (k == 0) {
		long long ans = 0;
		for (int i = 0; i <= 10000; i++) {
			ans += 1LL*ss[i]*(ss[i]-1)/2;
		}
		cout << ans << endl;
		return 0;
	}
	for (int i = 0; i < 1<<15; i++) {
		sum[i] = 0;
		for (int j = 0; j < 15; j++) {
			if (i & (1<<j)) sum[i]++;
		}
	}
	
	long long ans = 0;
	for (int i = 0; i <= 10000; i++)
		for (int j = i+1; j <= 10000; j++) {
			if (sum[i^j] == k && ss[i] != 0 && ss[j] != 0) {
				ans += 1LL*ss[i]*ss[j];
				//cout << i << " " << j << " "<< ss[i] << " " << ss[j] <<endl;
				
			}
		}
		cout << ans << endl;
}