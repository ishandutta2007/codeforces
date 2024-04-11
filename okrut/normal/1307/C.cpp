#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

ll R['z'+1]['z'+1], Cnt['z'+1];

int main ()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	
	for (char c: s)
	{
		rep(i,0,'z'+1) R[i][(int)c]+=Cnt[i];
		Cnt[(int)c]++;
	}
	ll res = 0;
	rep(i,0,'z'+1) rep(j,0,'z'+1) res = max(res, R[i][j]);
	rep(i,0,'z'+1) res = max(res, Cnt[i]);
	cout<<res <<"\n";
}