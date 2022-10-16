#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int wyr(long long int a,long long int n)
{
    if(a<0) return a+n;
    if(a>=n) return a-n;
    return a;
}

int main()
{
    long long  int n;
    cin>>n;
    vector<long long int> b;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        b.push_back(x);
    }
    long long int * a;
    a=new long long int[n];
    long long int l=1;
    long long int t=b[0];
    for(int i=1;i<n;i++) {if(b[i]==t) l++;}
    if(l==n)
    {
        if(t!=0) {cout<<"NO"; return 0;}
        else
        {
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++) cout<<"1"<<" ";
            return 0;
        }
    }
    else
    {
        long long int i=0;
        while(b[wyr(i-1,n)]>=b[i]) i++;
        a[i]=b[i];
        for(int j=1;j<n;j++)
        {
            long long int t=i-j;
            if(t<0) t+=n;
            a[t]=b[t];
            long long int m=b[wyr(t-1,n)];
            m++;
            m-=a[t];
            long long int x=m/a[wyr(t+1,n)];
            if(m%a[wyr(t+1,n)]!=0) x++;
            a[t]+=x*a[wyr(t+1,n)];

        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}