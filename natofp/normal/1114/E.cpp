#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(123654);
    vector<int> a;
    int n; cin>>n;
    int wsk=27;
    for(int i=0;i<wsk;i++)
    {

        int k=rand()%1668;
        int rest=rand()%1243;
        int ask=k*16315+rest;
        ask%=n;
        ask++;
        cout<<"? "<<ask<<endl;
        fflush(stdout);
        int v; cin>>v;
        a.push_back(v);
    }
    sort(a.begin(),a.end());
    int nwd=abs(a[0]-a[1]);
    for(int i=0;i<wsk;i++)
    {
        for(int j=0;j<wsk;j++)
        {
            if(i==j) continue;
            nwd=__gcd(nwd,abs(a[i]-a[j]));
        }
    }
    int lo=0;
    int hi=1e9;
    while(lo+1<hi)
    {
        int mid=(lo+hi)/2;
        cout<<"> "<<mid<<endl;
        fflush(stdout);
        int x; cin>>x;
        if(x==1) lo=mid;
        else hi=mid;
    }
    while(1)
    {
        cout<<"> "<<lo<<endl;
        fflush(stdout);
        int x; cin>>x;
        if(x==0) {cout<<"! "<<lo-(n-1)*nwd<<" "<<nwd<<endl; fflush(stdout); return 0;}
        else lo++;
    }


        return 0;
}