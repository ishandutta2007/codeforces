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

    ll n,m;
    cin>>n>>m;

    ll mapped[n];
    ll temp;
    for(ll i=0;i<n;i++)
    {
        cin>>temp;
        temp--;
        mapped[temp] = i;
    }
    ll possible[n]={0};
    ll arr[n];
    for(ll j=1;j<m;j++)
    {
        for(ll i=0;i<n;i++)
        {
            cin>>temp;
            temp--;
            arr[i] = mapped[temp];
        }
        for(ll i=0;i<n-1;i++)
        {
            if(arr[i+1]!=arr[i]+1)
            {
                possible[arr[i]]=1;
            }
        }
        possible[arr[n-1]]=1;
    }

    ll answer = n;

    ll consec=0;
    for(ll i=0;i<n-1;i++)
    {
        if(possible[i]==0)
        {
            consec++;
        }
        else
        {
            answer+= (consec*(consec+1))/2;
            consec=0;
        }
    }
    answer+= (consec*(consec+1))/2;

    cout<<answer<<endl;


    return 0;
}