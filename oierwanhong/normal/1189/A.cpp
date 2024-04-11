//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
char a[5011];
int main()
{
    ll n,c0=0,c1=0;
    std::cin>>n>>(a+1);
    for(ll i=strlen(a+1);i;--i)
        if(a[i]=='1')++c1;
        else ++c0;
    if(c1!=c0)std::cout<<1<<std::endl<<(a+1);
    else std::cout<<2<<std::endl<<a[1]<<" "<<(a+2);
    return 0;
}