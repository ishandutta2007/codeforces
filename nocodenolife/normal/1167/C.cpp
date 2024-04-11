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

    int n,m;
    cin>>n>>m;

    int arr[m+1] = {0};
    int v[n+1]={0};

    set<int> sets[m+1];
    int len;
    int x;
    std::set<int> merger;
    int fir;
    int sec;
    set <int> :: iterator itr; 
    set <int> :: iterator itr2;

    sets[0].insert(0);
    ForN1(m)
    {
    	merger.clear();
    	cin>>len;
    	ForA2(len)
    	{
    		cin>>x;
    		if(v[x]!=0)
    		{
    			merger.insert(v[x]);
    		}
    		else
    		{
    			v[x] = i;
    			sets[i].insert(x);
    		}
    	}

    	fir = i;
    	for (itr = merger.begin(); itr != merger.end(); ++itr) 
    	{ 
        	sec = *itr;
        	if(sets[sec].size() > sets[fir].size())
        	{
        		x = sec;
        		sec =fir;
        		fir = x;
        	}

        	for (itr2 = sets[sec].begin(); itr2 != sets[sec].end(); ++itr2) 
	    	{ 
	        	v[*itr2] = fir;
	        	sets[fir].insert(*itr2);
    		} 
    	} 
    }

    ForN1(n)
    {
    	cout<<sets[v[i]].size()<<" ";
    }
    cout<<endl;

    return 0;
}