#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5+100;
ll Dp[N];
const ll inf = 2e18;


int main ()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	rep(q,0,t)
	{
		int n, p, k;
		cin>>n >>p >>k;
		
		string s; ll x, y;
		cin>>s >>x >>y;
		s = "#" + s;
		rep(i,0,n+1) Dp[i] = inf;
		
		for (int i=n; i>0; i--) {
			if (i+k > n) Dp[i] = (s[i]=='0' ? x : 0);
			else {
				Dp[i] = Dp[i+k];
				
				Dp[i] += (s[i]=='0' ? x : 0);
			}
		}
		
		ll res = inf;
		ll d = 0;
		rep(i,p,n+1) {
			res = min(res, Dp[i] + d);
			d+=y;
		}
		cout<<res <<"\n";
		
	}
}