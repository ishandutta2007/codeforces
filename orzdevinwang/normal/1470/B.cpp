#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
const int N = 1e6 + 7;
int n, m, a[N], cnt[N], mp[N];
void Main() {
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
		L(j, 2, sqrt(a[i])) while(a[i] % (j * j) == 0) a[i] /= (j * j); 
	}
	int ansa = 0, ansb = 0;
	L(i, 1, n) {
		mp[a[i]] ++;
		ansa = max(ansa, mp[a[i]]); 
	}
	L(i, 1, n) if(mp[a[i]] % 2 == 0 || a[i] == 1) ansb ++;
	ansb = max(ansb, ansa);
	cin >> m;
	while(m--) {
		ll w; cin >> w;
		if(!w) printf("%d\n", ansa);
		else printf("%d\n", ansb);
	}
	L(i, 1, n) mp[a[i]] --;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T; while(T--) Main();
	return 0;
}