#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
using namespace std;
const int N = 1 << 20;
int n, k, a[N];
int cnt[27];
char s[N];
void Main() {
	cin >> n >> k;
	cin >> (s + 1) ;
	me(cnt, 0);
	L(i, 1, n) {
		cnt[s[i] - 'a'] += 1;
	}
	L(i, 1, k) {
		int cur = -1;
		L(i, 0, min(25, n / k - 1)) if(cnt[i]) {
			cur = i, cnt[i] -= 1;
		} else break;
		++cur;
		cout << ((char) (cur + 'a'));
	}
	cout << '\n';
} 
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}