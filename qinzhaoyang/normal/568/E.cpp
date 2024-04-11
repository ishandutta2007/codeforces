#include <stdio.h>
#include <bits/stdc++.h>
#define lb lower_bound

using namespace std;

const int N = 1e5 + 10 , inf = 0x3f3f3f3f;

int n, m, a[N], b[N], l[N], p[N], f[N], g[N], v[N], A[N];

int main() {
	ios::sync_with_stdio(false); 
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	++n , a[n] = inf , memset(f , 0x3f , sizeof f);
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> b[i];
	sort(b + 1 , b + m + 1);
	for(int i = 1; i <= n; i++) {
		if(~a[i]) {
			int j = lb(f + 1 , f + n + 1 , a[i]) - f;
			l[i] = j , p[i] = g[j - 1] , f[j] = a[i] , g[j] = i;
		}
		else {
			for(int j = n , k = m; k >= 1; k--) {
				while(j && f[j] >= b[k]) j--;
				f[j + 1] = b[k] , g[j + 1] = i;
			}
		}
	}
	int i = l[n] , j = n , x = a[n];
	while(i--) {
		if(~a[j]) {
			if(a[p[j]] == -1) {
				int k = lb(b + 1 , b + m + 1 , x) - b - 1;
				x = b[k] , v[k] = 1 , A[p[j]] = x;
			}
			else x = a[p[j]];
			j = p[j];
		}
		else {
			bool ok = 0;
			for(int s = j - 1; s >= 1; s--)
				if(a[s] != -1 && l[s] == i && a[s] < x) {
					ok = 1 , x = a[j = s];
					break;
				}
			if(ok) continue;
			for(int s = j - 1; s >= 1; s--)
				if(a[s] == -1) {
					int k = lb(b + 1 , b + m + 1 , x) - b - 1;
					A[j = s] = x = b[k] , v[k] = 1;
					break;
				}
		}
	}
	for(int i = 1 , j = 1; i < n; i++) {
		if(a[i] == -1) {
			if(A[i]) continue;
			while(v[j]) j++;
			A[i] = b[j++]; 
		}
		else A[i] = a[i];
	}
	for(int i = 1; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}