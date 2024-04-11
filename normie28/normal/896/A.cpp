#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const string pref = "What are you doing while sending \"";
const string mid = "\"? Are you busy? Will you send \"";
const string suf = "\"?";
const string whole = "What are you doing at the end of the world? Are you busy? Will you save us?";
long long fa, fb[100], fc[100], fd[100], f[100];
int n;
char Solve(int x, long long k) {
		if (x > n) {
			if (k >= fa) return Solve(x - 1, k - fa);
			return Solve(x - 1, k);
		}
		if (x == 0) return whole[k];
		if (k < fa) return pref[k];
		if (k < fb[x]) return Solve(x - 1, k - fa);
		if (k < fc[x]) return mid[k - fb[x]];
		if (k < fd[x]) return Solve(x - 1, k - fc[x]);
		return suf[k - fd[x]];
}
int main() {		
	fa = (long long) pref.length();
	f[0] = whole.length();	
	for (n = 1; fb[n - 1] < 1e18; ++n) {
		fb[n] = fa + f[n - 1];
		fc[n] = fb[n] + ((long long) mid.length());
		fd[n] = fc[n] + f[n - 1];
		f[n] = fd[n] + 2LL;				
	}
	--n;	
	int t; cin>>t;
	int x; long long k;
	while (t--) {
			cin>>x>>k;
			--k;
			if (x <= n && k >= f[x]) cout<<"."; else
			cout<<Solve(x,k);	
	}
}