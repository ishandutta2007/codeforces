#include <iostream>
#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int nax=505;
int a[nax][nax];

signed main()
{
    int n; cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    bool ok = false;
    for(int i=1;i<=n;i++)
    {
        if(a[1][i]==0) ok = true;
    }
    int sum=0;
    if(!ok)
    {
        for(int i=1;i<=n;i++) sum+=a[1][i];
    }
    else
    {
        for(int i=1;i<=n;i++) sum+=a[2][i];
    }
    int idx=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==0) idx=i;
        }
    }
    int sumka=0;
    for(int i=1;i<=n;i++)
    {
        sumka+=a[idx][i];
    }
    int ile=sum-sumka;
    for(int i=1;i<=n;i++)
    {
        if(a[idx][i]==0) a[idx][i]=ile;
    }
    ok = true;
    for(int i=1;i<=n;i++)
    {
        int akt1=0;
        int akt2=0;
        for(int j=1;j<=n;j++)
        {
            akt1+=a[i][j];
            akt2+=a[j][i];
        }
        if(akt1!=sum || akt2!=sum) ok = false;
    }
    int akt=0;
    for(int i=1;i<=n;i++)
    {
        akt+=a[i][i];
    }
    if(akt!=sum) ok = false;
    akt=0;
    for(int i=1;i<=n;i++)
    {
        akt+=a[i][n-i+1];
    }
    if(akt!=sum) ok = false;
    if(ok==false)
    {
        cout<<-1;
        return 0;
    }
    if(ile<=0)
    {
        cout<<-1;
        return 0;
    }
    else cout<<ile;
    return 0;
}