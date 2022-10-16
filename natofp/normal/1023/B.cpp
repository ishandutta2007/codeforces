#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool check(string a)
{
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='*') return true;
    }
    return false;
}

int main()
{
    long long int n,k;
    cin>>n>>k;
    long long w=abs((n+1)-k);
    cout<<max((n-w)/2,0LL);


    return 0;
}