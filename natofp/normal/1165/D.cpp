#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=1e6+5;
const int mil=1e6;
vector<bool> czy(nax,false);

int main()
{
    int t; cin>>t;
    while(t--)
    {
        bool ok =true;
        int n; cin>>n;
        int * a=new int[n+1];
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        long long int liczba;
        liczba=(long long int)a[1]*a[n];
        for(int i=1;i<=n;i++) czy[a[i]]=true;
        for(int i=2;i<=1e6;i++)
        {
            if(liczba%i==0 && i!=liczba)
            {
                if(liczba/i>mil) {ok=false; break;}
                if(czy[i]==false) {ok=false; break;}
                if(czy[liczba/i]==false) {ok=false; break;}
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(liczba%a[i]!=0) {ok=false; break;}
        }
        if(ok) {cout<<liczba<<endl;}
        else cout<<-1<<endl;
        for(int i=1;i<=n;i++) czy[a[i]]=false;

    }
    return 0;
}