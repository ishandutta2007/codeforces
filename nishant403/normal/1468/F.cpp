#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

void solve()
{
	int n;
	cin >> n;

	int res = 0;

	map< pii, int> mp;

	f(i,n)
	{
        int a,b,c,d;
		cin >> a >> b >> c >> d; 

        pii go = {d-b,c-a};
        int gc = __gcd(d-b,c-a);
        if(gc < 0) gc*=-1;
        go.F/=gc;
        go.S/=gc;
        pii gg = go;
        gg.F*=-1;
        gg.S*=-1;
        res+=mp[gg];
        mp[go]++;
	}

	cout << res << '\n';
}

signed main()
{
	fast;

	int t = 1;

	cin >> t;

	while (t--)

		solve();
}