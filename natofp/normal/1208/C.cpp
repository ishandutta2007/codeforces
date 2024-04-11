#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=1005;
int a[nax][nax];

int main()
{
    int t=0;
    int n; cin>>n;
    for(int i=1;i<=n/2;i++)
    {
        for(int j=1;j<=n/2;j++)
        {
            a[i][j]=t*4;
            a[i+n/2][j]=t*4+1;
            a[i][j+n/2]=t*4+2;
            a[i+n/2][j+n/2]=t*4+3;
            t++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}