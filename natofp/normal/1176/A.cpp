#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q; cin>>q;
    while(q--)
    {
        long long int n;
        cin>>n;
        int a,b,c;
        a=0;
        b=0;
        c=0;
        int res=0;
        while(n%5==0)
        {
            n/=5; c++;
        }
        while(n%3==0)
        {
            n/=3;
            b++;
        }
        while(n%2==0)
        {
            n/=2;
            a++;
        }
        if(n!=1)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<a+2*b+3*c<<endl;
    }
    return 0;
}