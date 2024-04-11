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

#define modder 998244353
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll k,a,b;
    cin>>k>>a>>b;
    
    string s;
    cin>>s;
    ll n = s.length();
    ll divi=n/k;
    ll rem =n%k;
    if(rem!=0)
    {
        if(divi+1>b)
        {
            cout<<"No solution"<<endl;
            return 0;
        }
    }
    if(divi<a || divi>b)
    {
        cout<<"No solution"<<endl;
        return 0;
    }
    
    ll counter =0;
    
    for(ll i=0;i<rem;i++)
    {
        for(ll j=0;j<divi+1;j++)
        {
            cout<<s[counter];
            counter++;
        }
        cout<<endl;
    }
    for(ll i=rem;i<k;i++)
    {
        for(ll j=0;j<divi;j++)
        {
            cout<<s[counter];
            counter++;
        }
        cout<<endl;
    }
    
    
    return 0;
}