#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool czy(double n)
{
    double x=n;
    double a=sqrt(x);
    long long int k=a;
    if(k*k==(long long int)x) return true;
    return false;
}

bool czyp(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{

 int n; cin>>n;
 double * a=new double[n];
 for(int i=0;i<n;i++) cin>>a[i];
 for(int i=0;i<n;i++)
 {
     if(a[i]==1) {cout<<"NO"<<endl; continue;}
     if(czy(a[i]))
     {
        int t=sqrt(a[i]);
        if(czyp(t)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
     }
     else cout<<"NO"<<endl;
 }
    return 0;
}