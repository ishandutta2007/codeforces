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

vector<int> rounds[500005];
ll cum[500005];
int which[500005];
int n,m,q;

ll findRound(ll val)
{
	ll mini = 0;
	ll maxi = n-1;
	ll mid;
	while(maxi>mini)
	{
		mid = maxi+mini;
		mid/=2;
		if(cum[mid]==val)
			return mid;

		if(cum[mid]>val)
		{
			maxi = mid;
		}
		else
		{
			mini = mid+1;
		}
	}
	return maxi;
}

ll findAns(ll val)
{
	ll roun = findRound(val);
	if(roun>0)
		val -= cum[roun-1];
	//val th value in round[roun]
	ll mini = 1;
	ll maxi = m;
	ll mid;
	auto it = rounds[roun].begin();
	ll x;
	while(maxi>mini)
	{
		//cout<<mini<<" "<<maxi<<endl;
		mid = maxi+mini;
		mid/=2;
		it = upper_bound (rounds[roun].begin(), rounds[roun].end(), mid);
		x = (it - rounds[roun].begin());
		x = mid-x;
		if(x==val)
		{
			if(which[mid]>roun)
			{
				maxi = mid-1;
			}
			else
			{
				return mid;
			}
		}

		if(x>val)
		{
			maxi = mid-1;
		}
		else if(x<val)
		{
			mini = mid+1;
		}
	}
	return maxi;
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

    cin>>n>>m>>q;

    mem(cum);
    mem(which);

    int city;
    ForA1(n)
    {
    	cin>>city;
    	rounds[which[city]].push_back(city);
    	cum[which[city]]++;
    	which[city]++;
    }

    ForA1(n)
    {
    	sort(rounds[i].begin(),rounds[i].end());
    }

    cum[0] = m-cum[0];
    ForN1(n-1)
    {
    	cum[i] = m-cum[i];
    	cum[i]+=cum[i-1];
    }

    /*ForA1(n)
    {
    	cout<<cum[i]<<endl;
    }
    cout<<endl;*/

    ll val;
    ll roun;
    ForA3(q)
    {
    	cin>>val;
    	val -=n;
    	if(val>cum[n-1])
    	{
    		val-=cum[n-1];
    		val%=m;
    		if(val==0)
    			val = m;
    		cout<<val<<endl;
    		continue;
    	}
    	//cout<<findRound(val)<<" ";
    	roun = findAns(val);
    	cout<<roun<<endl;
    }

    return 0;
}