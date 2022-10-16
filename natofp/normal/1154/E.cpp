#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;

int pos[nax];
int prawo[nax];
int lewo[nax];
vector<bool> czy(nax,true);
vector<int> druzyna(nax,0);
int ile;

int main()
{
    int n,k; cin>>n>>k;
    int * a=new int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        pos[a[i]]=i;
    }
    prawo[n]=-1;
    for(int i=n-1;i>=1;i--)
    {
        prawo[i]=i+1;
    }
    lewo[1]=-1;
    for(int i=2;i<=n;i++) lewo[i]=i-1;
    ile=n;
    int nr=1;
    int naj=n;
    while(ile>0)
    {
        if(nr==3) nr=1;
        //for(int i=1;i<=n;i++) cout<<druzyna[i];
        //cout<<endl;
        for(int i=naj;i>=1;i--)
        {
            if(czy[i]==true)
            {
                naj=i;
                break;
            }
        }
        int pozycja=pos[naj];
        int mid=pozycja;
        int ilezlewej=0;
        while(ilezlewej<k)
        {
            pozycja=lewo[pozycja];
            if(pozycja==-1) break;
            ilezlewej++;
            druzyna[pozycja]=nr;
            czy[a[pozycja]]=false;
            ile--;
        }
        if(pozycja==-1) lewo[mid]=-1;
        else lewo[mid]=lewo[pozycja];
        pozycja=mid;
        int ilezprawej=0;
        while(ilezprawej<k)
        {
            pozycja=prawo[pozycja];
            if(pozycja==-1) break;
            ilezprawej++;
            //cout<<pozycja<<" "<<a[pozycja]<<endl;
            druzyna[pozycja]=nr;
            czy[a[pozycja]]=false;
            ile--;
        }
        if(pozycja==-1) prawo[mid]=-1;
        else prawo[mid]=prawo[pozycja];
        prawo[mid[lewo]]=mid[prawo];
        lewo[mid[prawo]]=mid[lewo];
        czy[naj]=false;
        druzyna[mid]=nr;
        ile--;
        nr++;
    }
    for(int i=1;i<=n;i++) cout<<druzyna[i];
    cout<<endl;
    return 0;
}