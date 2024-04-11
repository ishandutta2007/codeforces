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

    ll l;
    cin>>l;
    string x;
    ll val=0;
    vector<int> vals;
    ll multi=1;
    ll maxi = 4294967295;
    ll notused =0;
    ll t;
    ForA1(l)
    {
        cin>>x;
        if(x=="for")
        {
            cin>>t;
            notused++;
            vals.push_back(t);
        }
        else if(x=="end")
        {
            if(notused>0)
            {
                vals.pop_back();
                notused--;
            }
            else
            {
                multi /= vals[vals.size()-1];
                vals.pop_back();
            }
        }
        else
        {
            t = vals.size()-1;
            while(notused>0)
            {
                multi*=vals[t];
                t--;
                notused--;
                if(multi>maxi)
                {
                    cout<<"OVERFLOW!!!"<<endl;
                    return 0;
                }
            }
            val += multi;
            if(val>maxi)
            {
                cout<<"OVERFLOW!!!"<<endl;
                return 0;
            }
        }
    }
    cout<<val<<endl;
    return 0;
}