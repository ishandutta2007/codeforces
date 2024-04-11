#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool bs1(int l,int r,int wiersz)
{
    cout<<"? "<<wiersz<<" "<<l<<" "<<wiersz<<" "<<r<<endl;
    fflush(stdout);
    int res; cin>>res;
    if(res%2==1) return true;
    return false;
}

bool bs2(int l,int r,int kolumna)
{
    cout<<"? "<<l<<" "<<kolumna<<" "<<r<<" "<<kolumna<<endl;
    fflush(stdout);
    int res; cin>>res;
    if(res%2==1) return true;
    return false;
}

int main()
{
    int n; cin>>n;
    vector<int> kolumny;
    vector<int> wiersze;
    for(int i=1;i<=n;i++)
    {
        cout<<"? "<<i<<" "<<1<<" "<<i<<" "<<n<<endl;
        fflush(stdout);
        int res; cin>>res;
        if(res%2==1) wiersze.push_back(i);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<"? "<<1<<" "<<i<<" "<<n<<" "<<i<<endl;
        fflush(stdout);
        int res; cin>>res;
        if(res%2==1) kolumny.push_back(i);
    }
    if(kolumny.size()!=0 && wiersze.size()!=0)
    {
        cout<<"? "<<wiersze[0]<<" "<<kolumny[0]<<" "<<wiersze[0]<<" "<<kolumny[0]<<endl;
        fflush(stdout);
        int res; cin>>res;
        if(res==1)
        {
            cout<<"! "<<wiersze[0]<<" "<<kolumny[0]<<" "<<wiersze[1]<<" "<<kolumny[1]<<endl;
            fflush(stdout);
            return 0;
        }
        else
        {
            cout<<"! "<<wiersze[0]<<" "<<kolumny[1]<<" "<<wiersze[1]<<" "<<kolumny[0]<<endl;
            fflush(stdout);
            return 0;
        }
    }
    if(kolumny.size()==0)
    {
        int lo=1;
        int hi=n;
        while(lo+1<hi)
        {
            int mid=(lo+hi)/2;
            bool ok = bs1(lo,mid,wiersze[0]);
            if(ok==true) hi=mid;
            else lo=mid+1;
        }
        bool ok = bs1(lo,lo,wiersze[0]);
        int wyn;
        if(ok) wyn=lo;
        else wyn=lo+1;
        cout<<"! "<<wiersze[0]<<" "<<wyn<<" "<<wiersze[1]<<" "<<wyn<<endl;
        fflush(stdout);
        return 0;
    }
    if(wiersze.size()==0)
    {
        int lo=1;
        int hi=n;
        while(lo+1<hi)
        {
            int mid=(lo+hi)/2;
            bool ok = bs2(lo,mid,kolumny[0]);
            if(ok==true) hi=mid;
            else lo=mid+1;
        }
        bool ok = bs2(lo,lo,kolumny[0]);
        int wyn;
        if(ok) wyn=lo;
        else wyn=lo+1;
        cout<<"! "<<wyn<<" "<<kolumny[0]<<" "<<wyn<<" "<<kolumny[1]<<endl;
        fflush(stdout);
        return 0;
    }

    return 0;
}