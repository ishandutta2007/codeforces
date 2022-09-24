#include<cstdio>

int n,t[20200];

int main(){
  int i,j,k,sum,ans;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",t+i);
  ans=0;
  for(i=0;i<n;i++)ans+=t[i];

  for(i=3;i<=n;i++){
    if(n%i==0){
      for(j=0;j<n/i;j++){
	sum=0;
	for(k=0;k<n;k+=n/i){
	  sum+=t[j+k];
	}
	if(ans<sum)ans=sum;
      }
    }
  }
  printf("%d\n",ans);

  return 0;
}