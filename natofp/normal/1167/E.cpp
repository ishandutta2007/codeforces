#include <iostream>
#include <bits/stdc++.h>

using namespace std;


const int nax=1e6+5;
vector<int> pos[nax];
int pref[nax];



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    int * a=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pos[a[i]].push_back(i);
        if(i==1) pref[i]=a[i];
        else pref[i]=max(pref[i-1],a[i]);
    }
    long long int res=0;
    int suf=x;
    int last=n+1;
    if(pos[suf].empty()==false)
    {
        last=pos[suf][0];
    }
    while(1)
    {
        suf--;
        if(suf==0) break;
        if(pos[suf].empty()==true) continue;
        if(pos[suf].back()>last) break;
        last=pos[suf][0];
    }
    suf++;
    last=-1;
    for(int i=1;i<=x;i++)
    {
        int r=max(i,suf-1);
        if(last!=-1) r=max(r,pref[last]);
        res+=x-r+1;
        if(pos[i].empty()==false)
        {
            if(pos[i][0]<last) break;
            last=pos[i].back();
        }
    }
    cout<<res;
    return 0;
}