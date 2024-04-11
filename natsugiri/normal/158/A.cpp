#include<cstdio>
int main(){
  int n,k,a[111],i,ans;
  ans=0;
  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++)scanf("%d",a+i);
  for(i=0;i<n;i++){
    if(a[i]>0&&a[i]>=a[k-1])ans++;
  }
  printf("%d\n",ans);
  return 0;
}