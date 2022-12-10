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

#define     D               1000000007
#define     MOD(x)          x=((x%D)+D)%D

int main()
{_
    long long int a[6];
    int n;
    cin>>a[0]>>a[1];
    cin>>n;
    MOD(a[0]);
    MOD(a[1]);
    FOR(i, 2, 5)
    {
        a[i]=a[i-1]-a[i-2];
        MOD(a[i]);
    }
    cout<<a[(n-1)%6]<<endl;
    ep;
}