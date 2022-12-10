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

int main()
{
    int a, b;
    cin>>a>>b;
    int r[3]={0, 0, 0};
    FOR(i, 1, 6)
    {
        int ap=abs(i-a), bp=abs(i-b);
        if(ap>bp)
            r[0]++;
        else if(ap<bp)
            r[2]++;
        else
            r[1]++;
    }
    cout<<r[2]<<' '<<r[1]<<' '<<r[0]<<endl;
    ep;
}