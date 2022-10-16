#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    vector<int> a(k+1,0);
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        a[x]++;
    }
    int ile=0;
    int cnt=0;
    for(int i=1;i<=k;i++)
    {
        if(a[i]%2==0) ile+=a[i];
        else
        {
            ile+=a[i]-1;
            cnt++;
        }
    }
    ile+=(cnt+1)/2;
    cout<<ile;

    return 0;
}