#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll suma=a+b+c;
        ll naj=a;
        naj=max(naj,b);
        naj=max(naj,c);
        if(naj-1<=suma-naj) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}