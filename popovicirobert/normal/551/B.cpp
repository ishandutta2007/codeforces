#include <bits/stdc++.h>
#define MAXN 100000
char A[MAXN+1],B[MAXN+1],C[MAXN+1];
int vfa[30];
int vfb[30];
int vfc[30];
int main(){
   FILE*fi,*fout;
   int i,na,nb,nc,a,b,flag,min,sol,j;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   scanf("%s%s%s" ,&A,&B,&C);
   na=strlen(A);
   for(i=0;i<na;i++)
     vfa[A[i]-'a']++;
   nb=strlen(B);
   for(i=0;i<nb;i++)
     vfb[B[i]-'a']++;
   nc=strlen(C);
   for(i=0;i<nc;i++)
     vfc[C[i]-'a']++;
   sol=0;
   a=b=0;
   for(i=0;i<=na;i++){
      min=na+1;
      flag=0;
      for(j=0;j<26;j++)
       if(vfb[j]>0){
            if(1LL*vfb[j]*i<=vfa[j]){
              if(vfc[j])
              min=std::min((vfa[j]-i*vfb[j])/vfc[j],min);
            }
            else
               flag=1;
       }
       else if(vfc[j])
          min=std::min(vfa[j]/vfc[j],min);
      if(!flag&&sol<min+i){
        sol=min+i;
        a=i;
        b=min;
      }
   }
   while(a>0){
      a--;
      for(i=0;i<nb;i++){
        printf("%c" ,B[i]);
        vfa[B[i]-'a']--;
      }
   }
   while(b>0){
      b--;
      for(i=0;i<nc;i++){
         printf("%c" ,C[i]);
         vfa[C[i]-'a']--;
      }
   }
   for(i=0;i<26;i++)
     while(vfa[i]>0){
        printf("%c" ,i+'a');
        vfa[i]--;
     }
  // fclose(fi);
  // fclose(fout);
   return 0;
}