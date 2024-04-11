#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int suma(int n)
{
    int res=0;
    while(n>0)
    {
        res+=n%10;
        n/=10;
    }
    return res;
}

int main()
{
    int n; cin>>n;
    while(1)
    {
        int ile=suma(n);
        if(ile%4==0)
        {
            cout<<n<<endl;
            return 0;
        }
        else n++;
    }
    return 0;
}