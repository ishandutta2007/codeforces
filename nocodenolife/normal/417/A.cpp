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

#define modder 1000000007
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
    
    ll c,d,n,m,k;
    cin>>c>>d>>n>>m>>k;
    
    ll toget = (n*m) - k;
    if(toget<=0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    ll answer = 0;
    double mai = (c+0.0)/(n+0.0);
    double addi = d+0.0;
    
    if(addi<mai)
    {
        answer+= toget*d;
        cout<<answer<<endl;
        return 0;
    }
    
    m = toget/n;
    toget -= n*m;
    answer+= c*m;
    
    answer+= min(c,toget*d);
    
    cout<<answer<<endl;
    
    return 0;
}