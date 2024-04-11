#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<ll> a;
vector<ll> app;

void solve()
{
    int n; cin>>n;
    a.clear();
    app.clear();
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x; a.push_back(x);
    }
    ll suma=0;
    ll ksor=0;
    for(int i=0;i<n;i++)
    {
        suma+=a[i];
        ksor^=a[i];
    }
    ll dodaj=(1LL<<55)+ksor;
    app.push_back(dodaj);
    ksor^=dodaj;
    suma+=dodaj;
    ll trzeba=ksor*2-suma;
    app.push_back(trzeba/2);
    app.push_back(trzeba/2);
    cout<<app.size()<<"\n";
    for(int i=0;i<app.size();i++)
    {
        cout<<app[i]<<" ";
    }
    cout<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}