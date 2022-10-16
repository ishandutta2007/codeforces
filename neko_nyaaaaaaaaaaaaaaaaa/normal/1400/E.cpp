#include<bits/stdc++.h>
int i,j=1,a[5010],f[5010][5010];
main(){
for(std::cin>>i;j<=i;j++)std::cin>>a[j];
for(;i;i--)for(j=0;j<i;j++)f[i-1][j]=a[j]<a[i]?std::min(f[i][j]+1,f[i][i]+a[i]-a[j]):f[i][i];
std::cout<<**f;
}