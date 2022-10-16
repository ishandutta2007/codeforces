#include <bits/stdc++.h>
#define ll long long int

using namespace std;

pair<int,int> tt[1111];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<int> a;
    vector<int> b;
    for(int i=1;i<=n;i++)
    {
        int x,y; cin>>x>>y;
        tt[i]={x,y};
    }
    while(1)
    {
        int ile[4];
        for(int i=0;i<4;i++) ile[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(abs(tt[i].first)%2==0 && abs(tt[i].second)%2==0) ile[0]++;
            if(abs(tt[i].first)%2==0 && abs(tt[i].second)%2==1) ile[1]++;
            if(abs(tt[i].first)%2==1 && abs(tt[i].second)%2==0) ile[2]++;
            if(abs(tt[i].first)%2==1 && abs(tt[i].second)%2==1) ile[3]++;
        }
        int u=0;
        for(int i=0;i<4;i++)
        {
            if(ile[i]>0) u++;
        }
        if(u>1) break;
        if(ile[0])
        {
            for(int i=1;i<=n;i++)
            {
                tt[i].first/=2;
                tt[i].second/=2;
            }
        }
        else if(ile[1])
        {
            for(int i=1;i<=n;i++)
            {
                tt[i].second--;
            }
        }
        else if(ile[2])
        {
            for(int i=1;i<=n;i++)
            {
                tt[i].first--;
            }
        }
        else if(ile[3])
        {
            for(int i=1;i<=n;i++)
            {
                tt[i].second--;
                tt[i].first--;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int x=abs(tt[i].first);
        int y=abs(tt[i].second);
        if(x%2==y%2) a.push_back(i);
        else b.push_back(i);
    }
    if(a.size()!=0 && b.size()!=0)
    {
        cout<<a.size()<<endl;
        for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
        return 0;
    }
    if(a.size()==0)
    {
        vector<int> c;
        vector<int> d;
        for(int i=0;i<b.size();i++)
        {
            int idx=b[i];
            pair<int,int> akt=tt[idx];
            if(abs(akt.first)%2==0) c.push_back(idx);
            else d.push_back(idx);
        }
        if(c.size()!=0 && d.size()!=0)
        {
            cout<<c.size()<<endl;
            for(int i=0;i<c.size();i++) cout<<c[i]<<" ";
            return 0;
        }
    }
    if(b.size()==0)
    {

        {
            vector<int> c;
            vector<int> d;
            for(int i=0;i<a.size();i++)
            {
                int idx=a[i];
                pair<int,int> akt=tt[idx];
                if(abs(akt.first)%2==0) c.push_back(idx);
                else d.push_back(idx);
            }
            if(c.size()!=0 && d.size()!=0)
            {
                cout<<c.size()<<endl;
                for(int i=0;i<c.size();i++) cout<<c[i]<<" ";
                return 0;
            }
        }
    }

    return 0;
}