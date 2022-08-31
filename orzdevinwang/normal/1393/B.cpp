#include<bits/stdc++.h>
#define N 110000
using namespace std;
int n, m, x, a[N], mp[N];
int cnta, cntb;
char opt[10];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x), mp[x]++;
		if(mp[x] % 2 == 0) cnta++;
		if(mp[x] % 4 == 0) cntb++;
	}
	scanf("%d", &m); 
	while(m--) {
		scanf("%s%d", opt, &x);
		if(opt[0] == '+') {
			mp[x]++;
			if(mp[x] % 2 == 0) cnta++;
			if(mp[x] % 4 == 0) cntb++;
		}
		else {
			if(mp[x] % 2 == 0) cnta--;
			if(mp[x] % 4 == 0) cntb--;
			mp[x]--;
		}
//		cout << cnta << " " << cntb << endl;
		if(cntb == 0 || cnta < 4) printf("NO\n");
		else printf("YES\n");
	} 
	return 0;
}