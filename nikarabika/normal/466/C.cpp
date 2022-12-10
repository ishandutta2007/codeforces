#include <bits/stdc++.h>

using namespace std;

#define     _               std::ios_base::Init i; std::ios_base::sync_with_stdio(false); std::cin.tie(0);
#define     All(a)          a.begin(), a.end()
#define     FOR(i, s, e)    for(ll i=s; i<=e; i++)
#define     rep(i, t)       for(ll i=0; i<t; i++)
#define     sp              system("pause")
#define     ep              return 0
#define     cendl           cout<<endl
#define     pb              push_back
#define     pob             pop_back
#define     mp              make_pair
#define     p1              first
#define     L               first
#define     p2              second
#define     R               second

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int main()
{_
    int n;
    cin>>n;
    ll sum=0, a[n];
    rep(i, n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%3 != 0)
    {
        cout<<0<<endl;
        ep;
    }
    sum/=3;

    vector <int> dp;
    ll sum2=0;
    ull res=0;

    for(int i=n-1; i>0; i--)
    {
        sum2+=a[i];
        if(sum2==sum)
        {
            dp.pb(i-1);
        }
    }
    sum2=0;
    for(int i=0; i<n; i++)
    {
        sum2+=a[i];
        if(sum2==sum)
        {
            while(i>=*(dp.end()-1))
                dp.erase(dp.end()-1);
            res+=dp.size();
        }
    }
    cout<<res<<endl;
    ep;
}