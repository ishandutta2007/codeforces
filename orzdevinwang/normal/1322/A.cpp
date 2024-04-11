#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int n;
char s[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> (s + 1);
	int cnt = 0, ret = 0;
	L(i, 1, n) {
		int o = cnt;
		cnt += s[i] == '(' ? 1 : -1;
		if(o < 0 || cnt < 0) ret += 1;
	}
	if(cnt == 0) cout << ret << '\n';
	else cout << -1 << '\n';
	return 0;
}