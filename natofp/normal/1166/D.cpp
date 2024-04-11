#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int a,b,m;

long long int potega[111];

const long long int INF=1e18;

void pre()
{
    potega[0]=1;
    for(int i=1;i<=60;i++)
    {
        potega[i]=potega[i-1]*2;
    }
}

bool proba(int k)
{
    vector<long long int> krotnosci(k+5);
    vector<long long int> liczby(k+5,1);
    liczby[0]=a;
    krotnosci[0]=max(0LL,potega[k-2]);
    for(int i=1;i<=k-1;i++)
    {
        if(i<k-1)
        krotnosci[i]=krotnosci[i-1]/2;
        else
        {
            krotnosci[i]=1;
        }
    }
    //for(int i=0;i<=k-1;i++) cout<<liczby[i]<<endl;
    long long int suma=0;
    if(INF/a<krotnosci[0]) return false;
    suma=krotnosci[0]*a;
    for(int i=1;i<k;i++)
    {
        suma+=krotnosci[i];
        if(suma>b) return false;
    }
    long long int brakuje=b-suma;
    for(int i=1;i<k;i++)
    {
        long long int ile=brakuje/krotnosci[i];
        long long int zwiekszam=min(m-1,ile);
        brakuje-=krotnosci[i]*zwiekszam;
        liczby[i]+=zwiekszam;
    }
    long long int akt=a;
    if(brakuje==0)
    {
        cout<<k<<" ";
        cout<<akt<<" ";
        for(int i=1;i<k;i++)
        {
            akt*=2;
            akt-=liczby[i-1];
            akt+=liczby[i];
            cout<<akt<<" ";
        }
        cout<<endl;
        return true;
    }
    return false;
}

void solve()
{
    if(a==b)
    {
        cout<<1<<" "<<a<<endl;
        return;
    }
    for(int k=2;k<=50;k++)
    {
        bool ok = proba(k);
        if(ok) return;
    }
    cout<<-1<<endl;
    return;
}

int main()
{
    pre();
    int q; cin>>q;
    while(q--)
    {
        cin>>a>>b>>m;
        solve();
    }
    return 0;
}