#include <iostream>

using namespace std;

const int m=1000000007;

int pow(int a,int b)
{
    if(b==0) return 1;
    int ret=pow(a,b/2);
    ret=ret*1ll*ret%m;
    if(b&1) ret=ret*1ll*a%m;
    return ret;
}

int main()
{
    long long n;
    cin>>n;
    n%=(m-1);
    n=((long long)(pow(2,n)))+pow(4,n);
    if(n&1) n+=m;
    cout<<(n/2)%m;
    return 0;
}