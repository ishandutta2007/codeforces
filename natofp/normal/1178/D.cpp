#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool ok(int x)
{
    if(x<=1) return false;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}

int main()
{
    int n; cin>>n;
    int m=n;
    while(ok(m)==false) m++;
    cout<<m<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" ";
        if(i!=n) cout<<i+1<<endl;
        else cout<<1<<endl;
    }
    int cnt=0;
    int ile=m-n;
    int akt=1;
    while(ile>0)
    {
        if(cnt==2)
        {
            akt+=2;
            cnt=0;
            continue;
        }
        cout<<akt<<" ";
        int j=akt+2;
        if(j>n) j-=n;
        cout<<j<<endl;
        akt++;
        ile--;
        cnt++;
    }
    return 0;
}