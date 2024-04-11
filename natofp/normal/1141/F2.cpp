#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int res=0;

struct przedzial
{
    int suma;
    int l;
    int r;
};
vector<pair<int,int > > ans;
vector<int> pre(2222);
vector<przedzial> t;
int ile(int l,int r)
{
    if(l==0) return pre[r];
    return pre[r]-pre[l-1];
}

bool por(przedzial a,przedzial b)
{
    return a.suma<b.suma;
}

bool por2(przedzial a,przedzial b)
{
    if(a.r==b.r) return a.l<b.l;
    return a.r<b.r;
}

void ojeb()
{
    int k=1;
    sort(t.begin(),t.end(),por2);
    vector<pair<int,int> > xd;
    int r=t[0].r;
    xd.push_back({t[0].l,t[0].r});
    int wsk=0;
    int n=t.size();
    while(wsk<n)
    {
        while(wsk<n && t[wsk].l<=r) wsk++;
        if(wsk==n) break;
        k++;
        r=t[wsk].r;
        xd.push_back({t[wsk].l,t[wsk].r});
    }
    if(k>res)
    {
        res=k;
        ans=xd;
    }
}

int main()
{
    int n; cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }

    pre[0]=a[0];
    for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
    vector<przedzial> s;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            przedzial nowy;
            nowy.l=i;
            nowy.r=j;
            nowy.suma=ile(i,j);
            s.push_back(nowy);
        }
    }
    sort(s.begin(),s.end(),por);
    int wsk=0;
    while(wsk<s.size())
    {
        int val=s[wsk].suma;
        t.clear();
        while(wsk<s.size() && s[wsk].suma==val)
        {
            t.push_back(s[wsk]);
            wsk++;
        }
        ojeb();
    }
    cout<<res<<endl;
    for(int i=0;i<res;i++) cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    return 0;
}