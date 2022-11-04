#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,w[2]={0,0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)w[0]++;
        if(a<b)w[1]++;
    }
    if(w[0]>w[1])printf("Mishka");
    if(w[0]<w[1])printf("Chris");
    if(w[0]==w[1])printf("Friendship is magic!^^");
    return 0;
}