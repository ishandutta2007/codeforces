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

bool is(int);

int main()
{_
    int n;
    cin>>n;
    int m=n;
    for(int i=1; i*i<=m; i++)
    {
        if(m%i==0)
        {
            if(is(i) || is(m/i))
            {
                cout<<"YES"<<endl;
                ep;
            }
        }
    }
    cout<<"NO"<<endl;
    ep;
}

bool is(int a)
{
    while(a!=0)
    {
        if(a%10 != 4 && a%10 != 7)
            return false;
        a/=10;
    }
    return true;
}