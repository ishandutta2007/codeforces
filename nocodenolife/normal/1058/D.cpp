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

    ll n,m,k;
    cin>>n>>m>>k;

    ll ini_n = n;
    ll ini_m = m;

    ll temp = __gcd(n,k);
    k/=temp;
    n/=temp;

    temp = __gcd(m,k);
    k/=temp;
    m/=temp;

    if(k==1)
    {
        cout<<"YES"<<endl;
        if(2*n <= ini_n)
        {
            cout<<"0 0"<<endl;
            cout<<"0 "<<m<<endl;
            cout<<2*n<<" 0"<<endl;
        }
        else{
            cout<<"0 0"<<endl;
            cout<<"0 "<<2*m<<endl;
            cout<<n<<" 0"<<endl;
        }

        return 0;
    }
    if(k==2)
    {
        cout<<"YES"<<endl;
        cout<<"0 0"<<endl;
        cout<<"0 "<<m<<endl;
        cout<<n<<" 0"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;
    return 0;
}