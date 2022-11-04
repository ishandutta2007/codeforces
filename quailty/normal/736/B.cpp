#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
bool isPrime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(isPrime(n))printf("1");
    else if(n%2==0 || isPrime(n-2))printf("2");
    else printf("3");
    return 0;
}