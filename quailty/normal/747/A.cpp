#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=sqrt(n);i>=1;i--)
        if(n%i==0)return 0*printf("%d %d",i,n/i);
}