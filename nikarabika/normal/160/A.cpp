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
#define     p2              second

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int main()
{_
    int n, sum=0;
    cin>>n;
    si a[n];
    rep(i, n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a, a+n);
    int sum2=0, c=0;
    sum/=2;
    for(int i=n-1; i>=0; i--)
    {
        sum2+=a[i];
        c++;
        if(sum2>sum)
            break;
    }
    cout<<c<<endl;
    ep;
}