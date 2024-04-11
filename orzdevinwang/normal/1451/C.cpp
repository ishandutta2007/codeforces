#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, k; char a[N], b[N];
int cnt[N];
void Main() {
	scanf("%d%d", &n, &k);
	scanf("%s%s", a + 1, b + 1);
	L(i, 0, 25) cnt[i] = 0;
	L(i, 1, n) cnt[a[i] - 'a'] ++;
	L(i, 1, n) cnt[b[i] - 'a'] --;
	int now = 0;
	L(i, 0, 25) {
		now += cnt[i];
		if(now < 0) return puts("No"), void();
		if(now % k) return puts("No"), void();
	}
	puts("Yes");
}
int T; 
int main() {
	scanf("%d", &T); while(T--) Main();
	return 0;
}