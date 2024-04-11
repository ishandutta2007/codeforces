#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
string dp[256][3], re[256][3], inf; 
bool cmp (string a, string b) {
	return sz(a) == sz(b) ? a < b : sz(a) < sz(b);
}
string Min (string a, string b) {
	return cmp(a, b) ? a : b;
}

char s[N];
void Main () {
	cin >> s;
	int ret = 0;
	R(i, 7, 0) ret <<= 1, ret += s[i] - '0';
	cout << dp[ret][2] << '\n'; 
}
int gc (int x) {
	int ret = 0;
	L(i, 0, 7) if(i >> x & 1) ret |= 1 << i;
	return ret; 
}
void init () {
	
	L(i, 0, 60) inf.push_back('|');
	L(i, 0, 255) L(j, 0, 2) dp[i][j] = inf;
	
	L(i, 0, 2) dp[gc(2)][i] = "x";
	L(i, 0, 2) dp[gc(1)][i] = "y";
	L(i, 0, 2) dp[gc(0)][i] = "z";
	L(o, 0, 20) {
		L(i, 0, 255) dp[i][0] = Min(dp[i][0], "!" + dp[255 ^ i][0]);
		L(i, 0, 255) L(j, 0, 255) dp[i & j][1] = Min(dp[i & j][1], dp[i][1] + "&" + dp[j][0]);
		L(i, 0, 255) L(j, 0, 255) dp[i | j][2] = Min(dp[i | j][2], dp[i][2] + "|" + dp[j][1]);
		L(i, 0, 255) dp[i][0] = Min(dp[i][0], "(" + dp[i][2] + ")");
		L(i, 0, 255) L(j, 1, 2) dp[i][j] = Min(dp[i][j], dp[i][j - 1]);
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	init ();
	while (T--) Main ();
	return 0;
}