#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int n,m;
int main(){
  int i,s,f,t,x;
  cin>>n>>m;
  for(i=0;i<n;i++){
    scanf("%d%d%d",&s,&f,&t);
    if(s==f){
      printf("%d\n",t);
    }else{
      x=t/(m-1);
      if(x%2){
	if(x*(m-1)+(m-s)<t)x++;
      }else{
	if(x*(m-1)+s-1<t)x++;
      }
      t=x*(m-1);
      if(x%2){
	if(f<s)printf("%d\n",t+m-f);
	else printf("%d\n",t+m-1+f-1);
      }else{
	if(s<f)printf("%d\n",f+t-1);
	else printf("%d\n",t+m-1+(m-f));
      }
    }
  }
  return 0;
}