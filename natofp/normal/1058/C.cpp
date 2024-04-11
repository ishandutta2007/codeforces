#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool check(char * a,int c,int n)
{
    int akt=0;
    int i=0;
    while(i<n && akt<c)
    {
        akt+=(a[i]-48);
        i++;
        if(akt>c) return false;
        if(akt==c) akt=0;
    }
    return true;
}

int main()
{
    int n; cin>>n;
    char * a;
    a=new char[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bool xd=true;
    for(int i=0;i<n;i++)
    {
        if(a[i]!='0') xd=false;
    }
    if(xd) {cout<<"YES"; return 0;}
    int sum=0;
    for(int i=0;i<n;i++) sum+=(a[i]-48);
    for(int i=1;i<sum;i++)
    {
        if(sum%i==0)
        {
            if(check(a,i,n)==true)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}