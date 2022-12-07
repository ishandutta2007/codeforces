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

    string s;
    cin>>s;

    std::vector<int> v;

    ll temp = 0;
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]=='a')
        {
            temp++;
        }
        if(s[i]=='b')
        {
            if(temp!=0)
            {
                v.push_back(temp);
                temp=0;
            }
        }
    }
    v.push_back(temp);

    ll ans = 1;

    for(ll i=0;i<v.size();i++)
    {
        ans*=(v[i]+1);
        ans%=modder;
    }
    ans--;
    ans+=modder;
    ans%=modder;
    cout<<ans<<endl;
    return 0;
}