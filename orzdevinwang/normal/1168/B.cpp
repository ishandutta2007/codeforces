#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 7;
int cheak(int *d, int n) {
	bool flag = 0;
	for(int j = 1; j <= n; j++) 
		for(int k = 1; k <= (n - j) / 2; k++) 
			if(d[j] == d[j + k] && d[j] == d[j + k * 2]) 
				flag = 1;
	return flag;
}
int n, a[N];
long long ans;
char s[N];
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++) a[i] = s[i] - '0'; 
	for(int i = 1; i <= n; i++) {
		int maxn = min(n, i + 8);
		for(int j = i; j <= maxn; j++) ans += cheak(a + i - 1, j - i + 1);
		ans += n - maxn;
	}
	printf("%lld\n", ans);
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//int n, d[111], ans;
//int main() {
//	scanf("%d", &n);
//	for(int i = 0; i < (1 << n); i++) {
//		for(int j = 1; j <= n; j++) d[j] = ((i >> (j - 1)) & 1);
//		bool flag = 1;
//		for(int j = 1; j <= n; j++) 
//			for(int k = 1; k <= (n - j) / 2; k++) 
//				if(d[j] == d[j + k] && d[j] == d[j + k * 2]) 
//					flag = 0;
//		ans += flag; 
//	}
//	printf("%d\n", ans);
//	return 0;
//}