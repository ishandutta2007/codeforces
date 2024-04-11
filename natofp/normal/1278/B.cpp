#include <bits/stdc++.h>
#define ll long long int
using namespace std;


void solve()
{
    ll a,b; cin>>a>>b;
    if(a>b) swap(a,b);
    if(a==b)
    {
        cout<<0<<endl;
        return;
    }
    ll dif=b-a;
    ll idx=1;
    while(1)
    {
        ll sum=idx*(idx+1)/2;
        if(sum>=dif && sum%2==dif%2)
        {
            cout<<idx<<endl;
            break;
        }
        idx++;
    }
}

int main()
{
   int t; cin>>t;
   while(t--)
   {
       solve();
   }


    return 0;
}