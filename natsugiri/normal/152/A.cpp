#include<cstdio>

int main(){
  int n,m,i,j,t,a[111];
  char s[111][111];
  scanf("%d%d",&n,&m);
  for(j=0;j<n;j++){
    scanf("%s",s[j]);
    a[j]=0;
  }
  for(i=0;i<m;i++){
    t=0;
    for(j=0;j<n;j++)if(t<s[j][i])t=s[j][i];
    for(j=0;j<n;j++)if(s[j][i]==t)a[j]++;
  }
  t=0;
  for(j=0;j<n;j++)if(a[j])t++;
  printf("%d\n",t);
  return 0;
}