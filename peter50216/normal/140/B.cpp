#include<stdio.h>
int n;
int in[310][310];
int pl[310][310];
int al[310];
int alp[310];
int out[310];
int outc[310];
int main(){
   int i,j,k;
   scanf("%d",&n);
   for(i=1;i<=n;i++)for(j=1;j<=n;j++){
      scanf("%d",&in[i][j]);
      pl[i][in[i][j]]=j;
   }
   for(i=1;i<=n;i++){
      scanf("%d",&al[i]);
      alp[al[i]]=i;
   }
   for(i=1;i<=n;i++){
      out[i]=0;
      outc[i]=-1;
   }
   int lm=-1,lm2=-1;
   for(i=1;i<=n;i++){
      if(lm==-1)lm=i;
      else if(lm2==-1){
         if(alp[lm]>alp[i]){
            lm2=lm;lm=i;
         }else{
            lm2=i;
         }
      }else if(alp[lm]>alp[i]){
         lm2=lm;lm=i;
      }else if(alp[lm2]>alp[i]){
         lm2=i;
      }
      for(j=1;j<=n;j++){
         if(lm!=j){
            if(lm!=-1&&(outc[j]==-1||pl[j][outc[j]]>pl[j][lm])){
               out[j]=i;
               outc[j]=lm;
            }
         }else{
            if(lm2!=-1&&(outc[j]==-1||pl[j][outc[j]]>pl[j][lm2])){
               out[j]=i;
               outc[j]=lm2;
            }
         }
      }
   }
   for(i=1;i<=n;i++)printf("%d%c",out[i],(i==n)?'\n':' ');
}