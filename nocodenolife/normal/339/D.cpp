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

ll pow2[19];
ll tree[262200];
ll n,m;

void query()
{
    ll idx,val;
    cin>>idx>>val;
    ll op=0;
    
    idx = idx+pow2[n]-1;
    tree[idx] = val;
    
    while(idx>0)
    {
        idx/=2;
        if(op==0)
        {
            tree[idx] = tree[2*idx]|tree[2*idx+1];
        }
        else
        {
            tree[idx] = tree[2*idx]^tree[2*idx+1];
        }
        op++;
        op%=2;
    }
    
    cout<<tree[1]<<endl;
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
    
    pow2[0]=1;
    for(ll i=1;i<19;i++)
    {
        pow2[i]=pow2[i-1]*2;
    }
 
    cin>>n>>m;
    for(ll i=pow2[n];i<pow2[n+1];i++)
    {
        cin>>tree[i];
    }
    
    ll op = 0;
    //0 means or, 1 means xor;
    for(ll i=n-1;i>=0;i--)
    {
        for(ll j=pow2[i];j<pow2[i+1];j++)
        {
            if(op==0)
            {
                tree[j] = tree[2*j]|tree[2*j+1];
            }
            else
            {
                tree[j] = tree[2*j]^tree[2*j+1];
            }
        }
        op++;
        op%=2;
    }
    
    for(ll i=0;i<m;i++)
    {
        query();
    }
    
    
 
    return 0;
}