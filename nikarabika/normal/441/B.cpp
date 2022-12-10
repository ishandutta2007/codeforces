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

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int A[3002];

int MAX(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int MIN(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int main()
{_
    ull n, v;
    cin>>n>>v;
    rep(i, n)
    {
        int t1, t2;
        cin>>t1>>t2;
        A[t1]+=t2;
    }
    ull res=0;
    pair <int, int> a;
    a=mp(0, 0);
    FOR(i, 1, 3001)
    {
        int c, d;
        a.first=a.second;
        a.second=A[i];
        int t1=a.first;
        int t2=a.second;
        c=MIN(t1, v);
        d=MIN(v-c, t2);
        a.second=MAX(t2-d, 0);
        res+=c+d;
    }
    cout<<res<<endl;
    ep;
}