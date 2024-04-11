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

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main()
{_
    int a[2], n;
    cin>>a[0]>>a[1]>>n;
    bool x=false;
    if(n==0)
    {
        cout<<1<<endl;
        ep;
    }
    while(n!=0)
    {
        //cout<<n<<endl;
        n-=gcd(n, a[x]);
        if(x)
            x=false;
        else
            x=true;
    }
    if(!x)
        cout<<1<<endl;
    else
        cout<<0<<endl;
    ep;
}