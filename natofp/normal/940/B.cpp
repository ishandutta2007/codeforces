#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,k,A,B;
    cin>>n>>k>>A>>B;
    int x=n;
    long long int licznik=0;
    if(k==1) {cout<<(n-1)*A; return 0;}

    else
    {

        while(x>1)
        {
            if(x%k!=0 && x>k) {licznik+=(x%k)*A; x-=x%k;}
            else if (x%k!=0 && x<k) {licznik+=(x-1)*A; break;}
            else if ((x-x/k)*A>B) {x/=k; licznik+=B;}
            else {licznik+=(x-1)*A; break;}
        }
    }
    cout<<licznik;
    return 0;
}