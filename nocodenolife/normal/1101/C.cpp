#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

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

    int t;
    cin>>t;
    int maxr,l,r,flag;
    ForA3(t)
    {
    	ll n;
    	cin>>n;
    	std::map<pair<int,int>, int> ans;
    	vector<pair<int,int>> init;
    	vector<pair<int,int>> finit;
    	// finit.push_back(make_pair(-1,-1));
    	ForA1(n)
    	{
    		cin>>l>>r;
    		init.push_back(make_pair(l,r));
    		finit.push_back(make_pair(l,r));
    	}
    	sort(finit.begin(),finit.end());
        // finit.push_back(make_pair(10000000,10000000));
        // pair<int,int> ans;
        flag = -1;
        maxr = finit[0].second;
        ans[finit[0]]=1;
        for(ll i=1;i<n;i++)
        {
            if((finit[i].first > maxr))
            {
                flag=i;
                // ans = finit[i];
                // break;
            }
            if(flag==-1)
            {
                ans[finit[i]]=1;
            }
            else
            {
                ans[finit[i]]=2;
            }
            maxr = max(maxr,finit[i].second);
        }
        if(flag==-1)
        {
            cout<<-1<<endl;
        }
        else
        {
            for(ll i=0;i<n;i++)
            {
                cout<<ans[init[i]]<<" ";
            }
            cout<<endl;
        }

    }

    return 0;
}