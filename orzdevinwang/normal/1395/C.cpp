#include<bits/stdc++.h>
using namespace std;
int n, m, a[211], b[211];
bool cheak(int x) {
	for(int i = 1; i <= n; i++) {
		bool flag = 0;
		for(int j = 1; j <= m; j++) {
			if(((a[i] & b[j]) | x) == x) {
				flag = 1;
				break;
			}
		}
		if(!flag) return 0;
	}
	return 1;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int j = 1; j <= m; j++) scanf("%d", &b[j]);
	for(int i = 0; i <= 511; i++) 
		if(cheak(i)) printf("%d\n", i), exit(0);
	return 0;
}