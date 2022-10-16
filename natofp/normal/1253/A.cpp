#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=1e5+5;
int a[nax];
int b[nax];
int dd[nax];
int n;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++) dd[i]=b[i]-a[i];
        int ile=0;
        int last=-1;
        for(int i=1;i<=n;i++)
        {
            if(dd[i]<0) ile+=1111;
            if(dd[i]==0)
            {
                last=0; continue;
            }
            if(dd[i]!=last)
            {
                last=dd[i];
                ile++;
            }
        }
        if(ile<=1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}