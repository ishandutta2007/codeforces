#include<bits/stdc++.h>
int n,k;
int main()
{
    scanf("%i %i",&n,&k);
    k=(n-k)/2+1;
    for(int i=1;i<=n;i++)printf("%c","01"[i%k==0]);
}