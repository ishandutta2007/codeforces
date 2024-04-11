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

    int n,q,mini,x;
    cin>>n>>q;
    
    int arr[n+1];
    int lst[n+1][19];
    int go[n+1][19];
    
    ForN1(n)
        cin>>arr[i];
    
    for(int i=0;i<19;i++)
    {
        lst[n][i]=n+1;
        go[n][i]=n+1;
    }
    for(int i=n;i>1;i--)
    {
        for(int j=0;j<19;j++)
        {
            if(arr[i] & 1<<j)
            {
                lst[i-1][j] = i;
            }
            else
            {
                lst[i-1][j] = lst[i][j];
            }
            //cout<<lst[i-1][j]<<" ";
        }
        //cout<<endl;
    }
    
    for(int i=n-1;i>=1;i--)
    {
        for(int j=0;j<19;j++)
        {
            mini = n+1;
            for(int k=0;k<19;k++)
            {
                if(arr[i] & 1<<k)
                {
                    x = lst[i][k];
                    if(x==n+1)
                        continue;
                    if(arr[x] & 1<<j)
                        mini = min(mini, x);
                    else
                        mini = min(mini, go[x][j]);
                }
            }
            go[i][j] = mini;
            //cout<<go[i][j]<<" ";
        }
        //cout<<endl;
    }
    
    int maxi;
    bool val;
    ForA1(q)
    {
        cin>>mini>>maxi;
        if(arr[mini]&arr[maxi])
        {
            cout<<"Shi"<<endl;
            continue;
        }
        val = false;
        for(int j=0;j<19;j++)
        {
            if(arr[maxi]&1<<j)
            {
                if(go[mini][j]<=maxi)
                {
                    val = true;
                    break;
                }
            }
        }
        if(val)
        {
            cout<<"Shi"<<endl;
        }
        else
        {
            cout<<"Fou"<<endl;
        }
    }
    
    
    return 0;
}