#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 5e3+1000;

int Dp[N][N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, m;
	string s, t;
	cin>>n >>m >>s >>t;
	s = "#" + s;
	t = "#" + t;
	
	int res = 0;
	
	rep(i,1,n+1) rep(j,1,m+1)
	{
		Dp[i][j] = 0;
		
		if (s[i]==t[j]) {
			Dp[i][j] = max(Dp[i][j], Dp[i-1][j-1]+2);
		} 
		
		Dp[i][j] = max(Dp[i][j], Dp[i-1][j]-1);
		Dp[i][j] = max(Dp[i][j], Dp[i][j-1]-1);
		
		res = max(res, Dp[i][j]);
	}
	cout<<res<<"\n";
}