#include <bits/stdc++.h>

int main(){
   FILE*fi,*fout;
   long long n,k,a,b,a1,b1,aux,flag,con,i,x,con1;
  // fi=fopen("C.in" ,"r");
  // fout=fopen("C.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%I64d%I64d%I64d%I64d" ,&n,&k,&a,&b);
   flag=0;
   if(a>b){
     aux=a;
     a=b;
     b=aux;
     flag=1;
   }
   if(b>(a+1)*k)
     fprintf(fout,"NO");
   else{
     if(a==b)
       for(i=1;i<=n;i++)
         if(i%2)
           fprintf(fout,"G");
         else
           fprintf(fout,"B");
     else{
       a1=a;
       b1=b;
       con1=0;
       while(a1>0||b1>0){
         con=0;
         x=0;
         if(b%(a+1)>con1){
           con1++;
           x=1;
         }
         while(b1>0&&con<b/(a+1)+x){
            con++;
            if(flag==0)
              fprintf(fout,"B");
            else
              fprintf(fout,"G");
            b1--;
         }
         a1--;
         if(a1>-1){
         if(flag==0)
           fprintf(fout,"G");
         else
           fprintf(fout,"B");
           }
       }
     }
   }
  // fclose(fi);
 //  fclose(fout);
   return 0;
}