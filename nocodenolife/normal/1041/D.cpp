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

typedef struct _Point
{
    ll beg;
    ll end;
}Point;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n,h;
    cin>>n>>h;

    ll begin,end;
    Point region[n];
    for(ll i=0;i<n;i++)
    {
        cin>>begin>>end;
        region[i].beg = begin;
        region[i].end = end;
    }

    begin = region[0].beg;
    end = region[0].end + h;

    ll counter = 1;
    while(counter<n && region[counter].beg < end)
    {
        end+= region[counter].end - region[counter].beg;
        counter++;
    }

    ll answer = end-begin;

    for(ll i=1;i<n;i++)
    {
        end += region[i].beg - region[i-1].end;
        begin = region[i].beg;
        while(counter<n && region[counter].beg < end)
        {
            end+= region[counter].end - region[counter].beg;
            counter++;
        }
        ll nexter = end-begin;
        if(nexter>answer)
            answer = nexter;
    }
    cout<<answer<<endl;
    return 0;
}