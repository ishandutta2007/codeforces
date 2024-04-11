#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a,long long int b)
{
    while(b)
    {
        long long int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main()
{
    long long int n,m,k;
    cin>>n>>m>>k;
    long long int c=gcd(n*m,k);
    long long int h,a,b;
    h=gcd(n,k);

    a=n/h;

    b=m*h*2/k;

    k/=c;
    if(k!=1 && k!=2) {cout<<"NO"; return 0;}


    if(k==1)
    {
        if(b>m)
        {
            b/=2;
            a*=2;
        }


    }



    if(a<=n && b<=m)
    {
        cout<<"YES"<<endl;
        cout<<0<<" "<<0<<endl;
        cout<<a<<" "<<0<<endl;
        cout<<0<<" "<<b<<endl;
    }

    else cout<<"NO"<<endl;
    return 0;
    }