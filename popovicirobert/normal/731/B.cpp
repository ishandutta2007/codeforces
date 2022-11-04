#include <cstdio>
int v[200001];
int main(){
   int i,n,flag;
   scanf("%d" ,&n);
   for(i=1;i<=n;i++)
     scanf("%d" ,&v[i]);
   flag=1;
   for(i=1;i<n;i++){
      if(v[i]%2==1){
         if(v[i+1]==0)
           flag=0;
         else
           v[i+1]--;
      }
   }
   if(v[n]%2==1)
     flag=0;
   if(flag==1)
     printf("YES");
   else
     printf("NO");
   return 0;
}