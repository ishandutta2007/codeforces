#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,m;
    cin>>n>>m;
    long long int a,b;
    a=max(0LL,n-2*m);
    b=0;

    if(m==0) {cout<<a<<" "<<n<<endl; return 0;}
    b=1;
    long long int i=1;

     while(m>0)
    {

        b++;
        m-=i;
        i++;

    }
    cout<<a<<" "<<n-b;

    return 0;
}