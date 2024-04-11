#include <iostream>
#include <set>

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

si s(ll a)
{
    si sum=0;
    while(a!=0)
    {
        sum+=a%10;
        a/=10;
    }
    return sum;
}

ull pow(int a, int b)
{
    ull t=1;
    rep(i, b)
        t*=a;
    return t;
}

int main()
{_
    int a, b, c;
    cin>>a>>b>>c;
    set <ll> res;
    ll t;
    FOR(i, 1, 81)
    {
        t=pow(i, a)*b+c;
        if(t<=0)
            continue;
        int sum=s(t);
        if(sum==i && t<1000000000)
            res.insert(t);
    }

    cout<<res.size()<<endl;
    while(res.size()>1)
    {
        ll x=*res.begin();
        cout<<x<<' ';
        res.erase(x);
    }
    if(!res.empty())
        cout<<*res.begin()<<endl;
    ep;
}