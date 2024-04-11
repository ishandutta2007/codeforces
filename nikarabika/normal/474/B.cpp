#include <bits/stdc++.h>

using namespace std;

#define     _               std::ios_base::Init i; std::ios_base::sync_with_stdio(false); std::cin.tie(0);
#define     FOR(i, s, e)    for(ll i=s; i<=e; i++)
#define     rep(i, t)       for(ll i=0; i<t; i++)
#define     pb              push_back
#define     mp              make_pair
#define     p1              first
#define     p2              second

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int main()
{_
    int n, m;
    cin>>n;
    pair <int, int> a[n];
    int s=0;
    rep(i, n)
    {
        int t;
        cin>>t;
        a[i].p1=s+1;
        s+=t;
        a[i].p2=s;
    }
    cin>>m;
    rep(i, m)
    {
        int t;
        cin>>t;
        int s=0, e=n-1;
        while(s<e)
        {
            //cout<<e<<endl;
            int mid=(s+e)/2;
            if(a[mid].p1>t)
                e=mid-1;
            else if(a[mid].p2<t)
                s=mid+1;
            else
            {
                cout<<mid+1<<endl;
                s=-1;
                break;
            }
        }
        if(s>=0)
            cout<<s+1<<endl;
    }
    return 0;
}