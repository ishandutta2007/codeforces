#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n,x,y;
    cin>>n>>x>>y;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        ll l=0,r=1e17;
        while(r-l>1){
            ll m=(l+r)/2;
            ll num=max((m/x)*x,(m/y)*y);
            if(num/x+num/y<a)
                l=m;
            else
                r=m;
        }
        ll num=max((r/x)*x,(r/y)*y);
        if(num%x==0)
            if(num%y==0)
               cout<<"Both"<<'\n';
            else
               cout<<"Vova"<<'\n';
        else
            cout<<"Vanya"<<'\n';
    }
}