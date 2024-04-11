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
{_
    int n, sum=0;
    cin>>n;
    int arr[7];
    rep(i, 7)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    n%=sum;
    //cout<<sum<<' '<<n<<endl;
    if(n==0)
    {
        for(int i=6; i>=0; i--)
        {
            if(arr[i]!=0)
            {
                cout<<i+1<<endl;
                ep;
            }
        }
    }
    rep(i, 8)
    {
        if(n<=0)
        {
            cout<<i<<endl;
            ep;
        }
        n-=arr[i];
    }
    ep;
}