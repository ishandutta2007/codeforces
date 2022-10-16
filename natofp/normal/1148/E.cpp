#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct point
{
    int akt;
    int cel;
    int nr;
};

const int nax=3e5+5;
int ruchy[5*nax][3];
int poz=1;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    vector<pair<int,int> > a;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        a.push_back({x,i});
    }
    vector<int> b;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<point> stos;
    for(int i=0;i<n;i++)
    {
        int akt=a[i].first;
        int cel=b[i];
        if(akt<cel)
        {
            point nowy;
            nowy.akt=akt;
            nowy.cel=cel;
            nowy.nr=a[i].second;
            stos.push_back(nowy);
        }
        else if(akt==cel) continue;
        int d=akt-cel;
        while(d>0)
        {
            if(stos.empty()==true)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            point ziomek=stos.back();
            stos.pop_back();
            int d2=ziomek.cel-ziomek.akt;
            int ile=min(d,d2);
            ruchy[poz][0]=ziomek.nr;
            ruchy[poz][1]=a[i].second;
            ruchy[poz][2]=ile;
            d-=ile;
            ziomek.akt+=ile;
            if(ziomek.akt!=ziomek.cel) stos.push_back(ziomek);
            poz++;
        }
    }
    if(stos.empty()==false)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    poz--;
    cout<<poz<<endl;
    for(int i=1;i<=poz;i++)
    {
        cout<<ruchy[i][0]<<" "<<ruchy[i][1]<<" "<<ruchy[i][2]<<"\n";
    }
    return 0;
}