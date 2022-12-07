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
    
    

    string s;
    cin>>s;
    ll k;
    cin>>k;
    string ans="";
    ll rem=0,snow=0;
    ll len = s.length();

    ForA1(len)
    {
        if(s[i]=='*')
            snow++;
        if(s[i]=='?')
            rem++;
    }

    if(k< len-2*(rem+snow))
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(snow==0 )
    {
        if(k>len-rem)
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
        ll toremove = len-rem-k;
        // cout<<len<<" "<<rem<<endl;
        ll i=0;
        while(i<len)
        {
            if(s[i]=='?')
            {
                i++;
                continue;
            }
            if(s[i+1]=='?' && toremove>0)
            {
                i+=2;
                toremove--;
                continue;
            }
            ans+=s[i];
            i++;
        }

        cout<<ans<<endl;
        return 0;
    }
    else
    {
        ll toadd = k + (2*rem) + (2*snow) - len;
        ll i=0;
        while(i<len)
        {
            if(s[i+1]=='?')
            {
                i+=2;
                continue;
            }
            if(s[i+1]=='*')
            {
                while(toadd>0)
                {
                    ans+=s[i];
                    toadd--;
                }
                i+=2;
                continue;
            }
            ans+=s[i];
            i++;
        }

        cout<<ans<<endl;
    }



    return 0;
}