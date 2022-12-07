#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll g=1; g<=n; g++)

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define F first
#define S second
#define debug(x)    cerr << #x << " = " << x << endl;
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m,l,r;
    cin>>n>>m;
    vector<pair<ll,ll>> points;
    vector<pair<ll,ll>> fin_points;
    ForA1(n)
    {
        cin>>l>>r;
        points.push_back({l,r});
    }
    sort(points.begin(),points.end());
    
    ll maxi =-1;
    ForA1(n)
    {
        if(i+1<n && points[i].first == points[i+1].first)
            continue;
        if(points[i].second<=maxi)
            continue;
        
        fin_points.push_back(points[i]);
        maxi = points[i].second;
    }
    
    n = fin_points.size();
    ll helper[n][18];
    maxi+=100000000; 
    ForA1(n)
    {
        r = fin_points[i].second;
        l = upper_bound(fin_points.begin(),fin_points.end(),make_pair(r,maxi)) - fin_points.begin();
        l--;
        if(l!=-1 && fin_points[l].first <=r && fin_points[l].second >r)
        {
            helper[i][0] = l;
        }
        else
        {
            helper[i][0] = -1;
        }
    }
    for(int j=1;j<18;j++)
    {
        ForA1(n)
        {
            if(helper[i][j-1]==-1)
                helper[i][j] = -1;
            else
                helper[i][j] = helper[helper[i][j-1]][j-1];
        }
    }
    ll x;
    ll res;
    ll j;
    for(ll qi = 0; qi < m; ++qi) {
		cin >> l>> r;
		x = upper_bound(fin_points.begin(),fin_points.end(),make_pair(l,maxi)) - fin_points.begin();
		x--;
		res = -1;
		if (x != -1) {
			res = 1;
			for (int h = 17; h >= 0; --h) {
				j = helper[x][h];
				if(j==-1)
				    continue;
				if (fin_points[j].second <= r) {
					res += (1<<h);
					x = j;
				}
			}
			if (fin_points[x].second < r) {
				++res;
				x = helper[x][0];
			}
			if (x==-1 || fin_points[x].second < r)
			    res = -1;
		}
		cout << res << endl;
	}
    
    
    return 0;
}