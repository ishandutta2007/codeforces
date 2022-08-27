#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7;
int n, m, a[N], lst[26];
char s[N];
void Main() {
	cin >> (s + 1);
	n = strlen(s + 1);
	me(lst, 0);
	L(i, 1, n) {
		lst[s[i] - 'a'] = i;
	}
	int cur = n + 1;
	L(i, 0, 25) if(lst[i]) cur = min(cur, lst[i]);
	L(j, cur, n) cout << s[j];
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