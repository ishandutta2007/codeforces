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
#define mem(x) memset(x,false,sizeof(x))
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

    ll m,n;
    cin>>m>>n;
    bool table[m][n];
    mem(table);
    ll s,x;
    
    ForA1(m)
    {
        cin>>s;
        ForA2(s)
        {
            cin>>x;
            x--;
            table[i][x] = true;
        }
    }
    /*ForA1(m)
    {
        ForA2(n)
            cout<<table[i][j];
        cout<<endl;
    }*/
    
    bool val;
    ForA1(m)
    {
        for(ll j=i+1;j<m;j++)
        {
            val = false;
            for(ll k=0;k<n;k++)
            {
                if(table[i][k]==true && table[j][k]==true)
                {
                    val = true;
                    break;
                }
            }
            if(val==false)
            {
                cout<<"impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"possible"<<endl;
    return 0;
}