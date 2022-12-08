#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int T , n , m;
int a[N] , b[N] , c[N];
int nxt[N] , first[N];

int f[N] , F[N];

int A[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 1; i <= max(n , m); i++)
			f[i] = F[i] = A[i] = nxt[i] = first[i] = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		for(int i = 1; i <= m; i++)
			cin >> c[i];
		for(int i = 1; i <= m; i++) {
			nxt[i] = first[c[i]];
			first[c[i]] = i;
		}
		int flag = false;
		for(int i = 1; i <= n; i++)
			if(a[i] != b[i]) {
				if(first[b[i]] == 0) {
					flag = true;
					break;
				}
				A[first[b[i]]] = i;
				f[first[b[i]]] = 1;
				first[b[i]] = nxt[first[b[i]]];
			}
		if(flag) {
			cout << "NO" << endl;
			continue;
		}
		int lst = 0;
		for(int i = 1; i <= n; i++)
			F[b[i]] = i;
		for(int i = 1; i <= m; i++)
			if(f[i]) lst = i;
		for(int i = lst + 1; i <= m; i++)
			if(F[c[i]]) lst = i;
		if(!A[lst]) A[lst] = F[c[lst]];
		for(int i = lst + 1; i <= m; i++) {
			if(F[c[i]]) A[i] = F[c[i]];
			else flag = true;
		}
		if(flag) {
			cout << "NO" << endl;
			continue;
		}
		for(int i = 1; i <= lst; i++)
			if(!f[i]) A[i] = A[lst];
		cout << "YES" << endl;
		for(int i = 1; i <= m; i++)
			cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}