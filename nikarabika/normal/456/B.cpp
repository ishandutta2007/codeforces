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

//char n[5], m[5];
char c[100001];

int main()
{_
    cin>>c;
    int a=0;
    for(int i=100000; i>=0; i--)
    {
        if(c[i]!=0)
        {
            if(i==0)
                a=c[0]-48;
            else
                a=c[i]+c[i-1]*10;
            break;
        }
    }
    if(a==0)
        cout<<4<<endl;
    else if((a-1)%4==3)
        cout<<4<<endl;
    else
        cout<<0<<endl;
    ep;
}