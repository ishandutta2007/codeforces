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

set <char> s;
map <char, int> m;

int main()
{_
    ull n, k;
    cin>>n>>k;
    rep(i, n)
    {
        char c;
        cin>>c;
        s.insert(c);
        m[c]++;
    }
    const int sz=s.size();
    ull a[sz];
    {
        int j=0;
        while(!s.empty())
        {
            a[j]=m[*s.begin()];
            j++;
            s.erase(*s.begin());
        }
    }
    sort(a, a+sz);
    ull sum=0;
    for(int i=sz-1; k>0; i--)
    {
        //cout<<k<<endl;
        if(a[i]>=k)
        {
            sum+=k*k;
            k=0;
        }
        else
        {
            sum+=a[i]*a[i];
            k-=a[i];
        }
    }
    cout<<sum<<endl;
    ep;
}