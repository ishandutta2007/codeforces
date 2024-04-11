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

#define mod 998244353 
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

struct subset 
{ 
    ll parent; 
    ll rank; 
}; 

ll find(struct subset subsets[], ll i) 
{ 
    // find root and make root as parent of i (path compression) 
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 
  
    return subsets[i].parent; 
} 
  
// A function that does union of two sets of x and y 
// (uses union by rank) 
void Union(struct subset subsets[], ll x, ll y) 
{ 
    ll xroot = find(subsets, x); 
    ll yroot = find(subsets, y); 
  
    // Attach smaller rank tree under root of high rank tree 
    // (Union by Rank) 
    if (subsets[xroot].rank < subsets[yroot].rank) 
    {
        subsets[xroot].parent = yroot; 
        subsets[yroot].rank  += subsets[xroot].rank;
        subsets[xroot].rank = -1;
    }
    else
    {
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank  += subsets[yroot].rank;
        subsets[yroot].rank = -1;
    }
  
    // If ranks are same, then make one as root and increment 
    // its rank by one 
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
    
    ll n;
    cin>>n;
    
    struct subset *comp0s = (struct subset*) malloc( n * sizeof(struct subset) ); 
    struct subset *comp1s = (struct subset*) malloc( n * sizeof(struct subset) ); 
    
    for (ll v = 0; v < n; ++v) 
    { 
        comp0s[v].parent = v; 
        comp0s[v].rank = 1; 
        comp1s[v].parent = v; 
        comp1s[v].rank = 1; 
    } 
    
    ll a,b,c;
    ForA1(n-1)
    {
        cin>>a>>b>>c;
        a--;b--;
        if(c==0)
        {
            Union(comp0s,a,b);
        }
        else
        {
            Union(comp1s,a,b);
        }
    }
    
    ll ans =0;
    ForA1(n)
    {
        a = comp0s[i].rank;
        b = comp1s[i].rank;
        if(a>0)
            ans+= (a * (a-1));
        if(b>0)
            ans+= (b * (b-1));
        
        a = comp0s[find(comp0s,i)].rank;
        b = comp1s[find(comp1s,i)].rank;
        ans+= (a-1)*(b-1);
    }
    
    cout<<ans<<endl;
    return 0;
}