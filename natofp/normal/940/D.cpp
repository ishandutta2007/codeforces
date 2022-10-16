#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int * a;
    int * b;
    a=new int[n];
    b=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') b[i]=1;
        else b[i]=0;
    }
    long long int l=-1000000000;
    long long int r=1000000000;
    for(int i=4;i<n;i++)
    {
        if(b[i-1]==1 && b[i-2]==1 &&b[i-3]==1 &&b[i-4]==1 && b[i]==0)
        {
            int najm=a[i];
            for(int j=1;j<5;j++)
            {
                if(a[i-j]<najm) {najm=a[i-j];}
            }
            if(najm-1<r) r=najm-1;
        }
        if(b[i-1]==0 && b[i-2]==0 &&b[i-3]==0 &&b[i-4]==0 && b[i]==1)
        {
            int najw=a[i];
            for(int j=1;j<5;j++)
            {
                if(a[i-j]>najw) {najw=a[i-j];}
            }
            if(najw+1>l) l=najw+1;
        }
    }
    cout<<l<<" "<<r;
    delete [] a;
    delete [] b;
    return 0;
}