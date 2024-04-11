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

    ll n,k;
    cin>>n>>k;

    ll heights[n];
    
    ForA1(n)
    {
        cin>>heights[i];
    }

    //ll counter = 0;
    sort(heights, heights+n);
    ll mini = heights[0];

    ForA1(n)
    {
        heights[i]-=mini;
    }
    ll answer = 0;
    ll index = n-1;
    ll cur = 1;
    ll next,req,more,reduce;
    while(index!=0)
    {
        req=0;
        while(req<k && index>0)
        {
            next = heights[index-1];
            req +=(heights[index]-next)*cur;
            cur++;
            index--;
        }
        if(req==0)
        {
            break;
        }
        if(req<=k)
        {
            answer++;
            continue;
        }

        index++;
        cur--;
        more = req-k;
        reduce = (more+cur-1)/cur;
        heights[index] = heights[index-1]+reduce;
        answer++;
    }
    cout<<answer<<endl;
    return 0;
}