#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n; cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    int p=0;
    int s=0;
    int i=0;
    while(a[i]==1) i++;
    p=i;
    i=n-1;
    while(a[i]==1) i--;
    s=n-1-i;
    int ans=p+s;
    int akt=0;
    i=0;
    while(i<n)
    {
        if(a[i]==1) akt++;
        else
        {
            ans=max(ans,akt);
            akt=0;
        }
        i++;
    }
    ans=max(ans,akt);
    cout<<ans;
    return 0;
}