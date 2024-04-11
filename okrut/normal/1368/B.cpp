#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	ll k;
	cin>>k;
	
	vector <ll> cnt(10,1);
	
	ll curr = 1LL;
	
	for (int i=0; curr <k; i++)
	{
		int c = i%10;
		curr = curr/cnt[c];
		cnt[c]++;
		curr*=cnt[c];
	}
	
	string s = "codeforces", ans;
	rep(i,0,10) rep(j,0,cnt[i]) ans.pb(s[i]);
	cout<<ans <<"\n";
}