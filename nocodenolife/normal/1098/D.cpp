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

ll findinterval(ll num)
{
	ll ret = 0;
	ll max = 2;

	while(num>max)
	{
		max*=2;
		ret++;
	}

	return ret;
}
int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    multiset <ll> ma_chuda[31];

    ll bsdk[31] = {0};

    ll q,num,interval,ans,tot=0;
    cin>>q;
    char c;
    while(q>0)
    {	
    	cin>>c>>num;
    	interval = findinterval(num);
    	if(c=='+')
    	{
    		tot++;
    		ma_chuda[interval].insert(num);
    		for(ll i=interval;i<31;i++)
    		{
    			bsdk[i]+=num;
    		}
    	}
    	else
    	{
    		tot--;
    		ma_chuda[interval].erase(ma_chuda[interval].find(num));
    		for(ll i=interval;i<31;i++)
    		{
    			bsdk[i]-=num;
    		}
    	}
    	ans = tot;
    	if(ma_chuda[0].size()>0)
    	{
    		ans--;
    	}
    	for(ll i=1;i<31;i++)
    	{
    		if(ma_chuda[i].size()==0)
    			continue;
    		num = *(ma_chuda[i].begin());
    		if(num>2*bsdk[i-1])
    		{
    			ans--;
    			// cout<<i<<" "<<num<<" ";
    		}
    	}
    	cout<<ans<<endl;
    	q--;
    }
    // cout<<bsdk[4];
    // cout<<3;
    return 0;
}