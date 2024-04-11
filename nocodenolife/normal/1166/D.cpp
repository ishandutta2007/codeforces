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

    int q;
    cin>>q;

    ll powe[52];
    ll sume[52];
    powe[0] = 1; sume[0]=1;
    powe[1] = 1; sume[1]=2;

    for(ll i=2;i<52;i++)
    {
    	powe[i] = powe[i-1]*2;
    	sume[i] = sume[i-1] + powe[i];
    }

    ll a,b,m;
    ll ans,i,t1,t2;
    ll tb,j,n,val,prevsum,prevval;
    ll arr[55];
    ForN3(q)
    {
    	cin>>a>>b>>m;

    	if(a==b)
    	{
    		cout<<1<<" "<<a<<endl;
    		continue;
    	}

    	for(n=2;n<=50;n++)
    	{
    		t1 = powe[n-1]*a + sume[n-2];
    		if(b<t1)
    		{
    			cout<<-1<<endl;
    			break;
    		}

    		t2 = powe[n-1]*a + m*sume[n-2];
    		//cout<<t2<<endl;
    		if(b<=t2)
    		{
    			tb = b-t1;
    			for(j=1;j<=n-1;j++)
    			{
    				i = tb/powe[n-1-j];
    				i = min(m-1,i);
    				tb -= i*powe[n-1-j];
    				arr[j] = i+1;
    			}

    			prevsum = a;
    			cout<<n<<" "<<a<<" ";
    			
    			for(i=2;i<=n;i++)
    			{
    				val = prevsum + arr[i-1];
    				prevsum += val;
    				cout<<val<<" "; 
    			}
    			cout<<endl;
    			break;
    		}
    	}
    }

    return 0;
}