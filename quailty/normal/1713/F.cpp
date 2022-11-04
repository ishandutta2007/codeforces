#include<bits/stdc++.h>
using namespace std;
const int MAXN=(1<<19)+5;
int f[MAXN];
int main()
{
    int n,m=0;
    scanf("%d",&n);
    while((1<<m)<n)m++;
    for(int i=0;i<n;i++)
        scanf("%d",&f[i]);
    for(int i=0;i<m;i++)
        for(int j=0;j<(1<<m);j++)
            if(~j>>i&1)f[j|(1<<i)]^=f[j];
    for(int i=n;i<(1<<m);i++)f[i]=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<(1<<m);j++)
            if(~j>>i&1)f[j]^=f[j|(1<<i)];
    for(int i=n-1;i>=0;i--)
        printf("%d%c",f[i]," \n"[i==0]);
    return 0;
}