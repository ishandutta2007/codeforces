#include<cstdio>
#include<iostream>
typedef long long ll;
ll a[10];
int main()
{
    ll n;
    std::cin>>n;
    a[1]=a[7]=a[9]=1;
    if((a[n%10]||n>9&&n<30||a[n/10])&&n!=12)
        std::cout<<"NO";
    else std::cout<<"YES";
    return 0;
}