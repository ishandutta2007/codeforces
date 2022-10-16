#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        bool ok = true;
        string a,b; cin>>a>>b;
        vector<pair<int,int> > x,y;
        int as=a.length();
        int bs=b.length();
        int res=1;
        for(int i=1;i<as;i++)
        {
            if(a[i]==a[i-1]) res++;
            else
            {
                x.push_back({a[i-1]-'a',res});
                res=1;
            }
        }
        x.push_back({a[as-1]-'a',res});
        res=1;
        for(int i=1;i<bs;i++)
        {
            if(b[i]==b[i-1]) res++;
            else
            {
                y.push_back({b[i-1]-'a',res});
                res=1;
            }
        }
        y.push_back({b[bs-1]-'a',res});
        if(x.size()!=y.size())
        {
            cout<<"NO"<<"\n"; continue;
            ok = false;
        }
        int k=x.size();
        for(int i=0;i<k;i++)
        {
            if(x[i].first!=y[i].first)
            {
                cout<<"NO"<<"\n";
                ok = false;
                i=1e9;
                continue;
            }
            else
            {
                if(y[i].second<x[i].second)
                {
                    cout<<"NO"<<"\n";
                    ok = false;
                    i=1e9;
                    continue;
                }
            }
        }
        if(ok)
        {
            cout<<"YES"<<"\n";
        }


    }
    return 0;
}