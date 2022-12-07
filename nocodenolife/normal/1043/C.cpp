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

    string s;
    cin>>s;

    ll n = s.length();
    ll arr[n] = {0};

    ll start=-1;
    char mini = 'z';

    for(ll i=0;i<n;i++)
    {
        if(s[i]<=mini)
        {
            mini = s[i];
            start = i;
        }
    }
    ll toreach = start-1;
    arr[start] = 1;

    while(toreach!=-1)
    {
        mini = 'z';
        for(ll i=0;i<=toreach;i++)
        {
            if(s[i]<=mini)
            {
                mini = s[i];
                start = i;
            }
        }
        if(start==toreach)
        {
            toreach--;
        }
        else{
            arr[start] = 1;
            arr[toreach] = 1;
            toreach = start -1;
        }
    }

    for(ll i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}