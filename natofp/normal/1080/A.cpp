#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int wynik=0;
    int a,b,c;
    a=2*n;
    b=5*n;
    c=8*n;
    wynik+=a/k+bool(a%k);
    wynik+=b/k+bool(b%k);
    wynik+=c/k+bool(c%k);
    cout<<wynik;    return 0;
}