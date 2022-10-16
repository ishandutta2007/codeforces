#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct programmer
{
    int skill;
    int nr;
};


bool comp(programmer a,programmer b)
{
    if(a.skill<b.skill) return true;
    else return false;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector <programmer> a(n);
    for(int i=0;i<n;i++)
    {
        a[i].nr=i;
        cin>>a[i].skill;
    }
    vector <int> wyniki(n);
    for(int i=0;i<n;i++)
        wyniki[i]=0;
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        if(a[x-1].skill>a[y-1].skill) wyniki[x-1]-=1;
        else if (a[x-1].skill<a[y-1].skill) wyniki[y-1]-=1;
    }
    sort(a.begin(),a.end(),comp);

    int licznik=0;

    for(int i=1;i<n;i++)
    {
        if(a[i].skill==a[i-1].skill) licznik++;
        else licznik=0;
        wyniki[a[i].nr]+=(i-licznik);
    }
    for(int i=0;i<n;i++)
        cout<<wyniki[i]<<" ";
    return 0;
}