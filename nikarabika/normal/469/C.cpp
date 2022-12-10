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

void F(int n)
{
        if(n==4)
            cout<<"4 * 3 = 12"<<endl
                <<"1 * 2 = 2"<<endl
                <<"12 * 2 = 24"<<endl;
        else if(n==6)
        {
            cout<<"6 - 3 = 3"<<endl;
            F(5);
        }
        else if(n==5)
            cout<<"5 - 1 = 4"<<endl
                <<"3 * 4 = 12"<<endl
                <<"4 - 2 = 2"<<endl
                <<"2 * 12 = 24"<<endl;
        else
            cout<<"2 + 5 = 7"<<endl
                <<"4 * 6 = 24"<<endl
                <<"24 * 1 = 24"<<endl
                <<"7 - 7 = 0"<<endl
                <<"0 * 3 = 0"<<endl
                <<"24 + 0 = 24"<<endl;
}

int main()
{_
    int n;
    cin>>n;
    if(n<4)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        F((n%4)+4);
        for(int i=(n%4)+4+1; i<n; i+=2)
        {
            cout<<i+1<<" - "<<i<<" = 1"<<endl;
            cout<<"24 * 1 = 24"<<endl;
        }
    }
    ep;
}