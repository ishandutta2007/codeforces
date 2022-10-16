#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,h;
vector<int> a;

bool czy(int ile)
{
    int t=h;
    vector<int> akt;
    for(int i=0;i<ile;i++)
    {
        akt.push_back(a[i]);
    }
    sort(akt.begin(),akt.end());
    reverse(akt.begin(),akt.end());
    for(int i=0;i<ile;i++)
    {
        if(i!=ile-1)
        {
            int x=max(akt[i],akt[i+1]);
            if(x>t) return false;
            t-=x;
            i++;
            continue;
        }
        if(akt[i]>t) return false;
        return true;
    }
}

int main()
{
    cin>>n>>h;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    int i=1;
    while(i<=n && czy(i)==true) i++;
    i--;
    cout<<i;
    return 0;
}