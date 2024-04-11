#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n;
int a[100010] , nxt[100010] , col[100010];;
int f[100010];

int main()
{
//	freopen("shujv.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	ios::sync_with_stdio(false); 
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	n = unique(a + 1 , a + n + 1) - a - 1;
	for(int i = n; i >= 1; i--) {
		nxt[i] = col[a[i]];
		col[a[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		f[i] = max(f[i] , f[i - 1]);
		if(nxt[i - 1])
			f[nxt[i - 1]] = max(f[nxt[i - 1]] , f[i] + 1);
	}
	cout << n - f[n] << endl;
	return 0; 
}