#include <stdio.h>
int n,x,a[1024],b[1024],v[1024]={1};
main(){
  scanf("%d%d",&n,&x);
  for(int i=1;i<=n;++i)scanf("%d",&a[i]),++b[a[i]];
  int t=0;
  for(int i=1;i<=n;++i)if(!b[i]){
    int z=0,f=0;
    for(int j=i;j>0;j=a[j],++z)if(f|=j==x)++t;
    if(!f)for(int j=n;j>=z;--j)v[j]|=v[j-z];
  }
  for(int i=0;i<n;++i)if(v[i])printf("%d\n",i+t);
}