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

bool notprm(int a)
{
    for(int i=2; i*i<=a; i++)
        if(a%i==0)
            return true;
    return false;
}

int main()
{_
    int n;
    cin>>n;
    int m=n/2;
    for(int i=4; i<=m; i++)
    {
        if(notprm(i) && notprm(n-i))
        {
            cout<<i<<' '<<n-i<<endl;
            ep;
        }
    }
    ep;
}