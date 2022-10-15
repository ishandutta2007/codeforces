#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL))
#define ll long long int
#define pb push_back
#define mod 1000000007
#define mp make_pair
ll gcd(ll a,ll b){if(a==0)return b;return gcd(b%a,a);}          
ll lcm(ll a,ll b){return (max(a,b)/gcd(a,b))*min(a,b);}
vector<pair<ll,ll>> bc;
vector<ll> nc;
void factorize(ll n) 
{ 
    int count = 0;  
    while (!(n % 2)) { 
        n >>= 1;
        count++; 
    } 
    if (count)
    {
        bc.pb(mp(2,count));    
    }
    for (long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
        {
            bc.pb(mp(i,count));
        }
    } 
    if (n > 2) 
    {
        bc.pb(mp(n,1));
    }
    
} 
 
void factorial(ll n)
{
    ll i;
    for(i=0;i<bc.size();i++)
    {
        ll x=0;
        ll t=n;
        while(t)
        {
            x+=t/(bc[i].first);
            t/=bc[i].first;
        }
        nc.pb(x);
    }
}
 
int main()
{ 
    ll n,b,i;
    cin>>n>>b;
    factorize(b);
    factorial(n);
    ll min=(nc[0])/(bc[0].second);
    for(i=1;i<bc.size();i++)
    {
        if((nc[i]/bc[i].second)<min)
            min=nc[i]/bc[i].second;
    }
    cout<<min;
}