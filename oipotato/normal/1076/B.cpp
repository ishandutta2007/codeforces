#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    int maxc=sqrt(n)+1;
    for(int i=2;i<=maxc;i++)
        if (n%i==0){ cout<<((n-i)/2)+1<<endl; return 0; }
    cout<<1<<endl;
}