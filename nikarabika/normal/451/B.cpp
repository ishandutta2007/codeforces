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

int main()
{_
    int n;
    cin>>n;
    int arr[n];
    bool inc=true;
    int a, b;
    int c=0;
    cin>>b;
    arr[0]=b;
    int s=1, e=1;
    rep(i, n-1)
    {
        cin>>a;
        arr[i+1]=a;
        if(inc)
        {
            if(a<b)
            {
                if(c==0)
                {
                    inc=false;
                    s=i+1;
                    e=s+1;
                    c++;
                }
                else
                {
                    cout<<"no"<<endl;
                    ep;
                }
            }
        }
        else
        {
            if(a<b)
                e++;
            else
                inc=true;
        }
        b=a;
    }
    if(e<n)
        if(arr[s-1]>arr[e])
        {
            cout<<"no"<<endl;
            ep;
        }
    if(s>1)
        if(arr[e-1]<arr[s-2])
        {
            cout<<"no"<<endl;
            ep;
        }
    cout<<"yes"<<endl
        <<s<<' '<<e<<endl;
    ep;
}