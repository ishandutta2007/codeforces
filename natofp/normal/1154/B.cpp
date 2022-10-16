#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int ile=5000;
    int cel1=a[0];
    for(int d=0;d<=500;d++)
    {
        int cel2=a[0]+d;
        bool ok1= true;
        bool ok2= true;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=cel1 && (a[i]-d)!=cel1 && (a[i]+d)!=cel1) ok1=false;
            if(a[i]!=cel2 && (a[i]-d)!=cel2 && (a[i]+d)!=cel2) ok2=false;
        }
        if(ok1==true || ok2==true)
        {
            ile=d; break;
        }
    }
    if(ile==5000) cout<<-1;
    else cout<<ile;

    return 0;
}