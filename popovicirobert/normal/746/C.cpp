#include <bits/stdc++.h>
inline int getmin(int a,int b){
   if(a<b) return a;
   return b;
}
int main(){
   FILE*fi,*fout;
   int s,x1,x2,t1,t2,p,d,ans;
  // fi=fopen("B.in" ,"r");
  // fout=fopen("B.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d%d%d%d%d%d" ,&s,&x1,&x2,&t1,&t2,&p,&d);
   ans=abs(x2-x1)*t2;
   if(x1<=x2){
      if(d==1){
         if(p<=x1)
            ans=getmin(ans,t1*(x2-p));
         else
            ans=getmin(ans,t1*(2*s-p+x2));
      }
      else
         ans=getmin(ans,t1*(p+x2));
   }
   else{
      if(d==1)
         ans=getmin(ans,t1*(s-p+s-x2));
      else{
         if(p>=x1)
            ans=getmin(ans,t1*(p-x2));
         else
            ans=getmin(ans,t1*(p+s+s-x2));
      }
   }
   fprintf(fout,"%d" ,ans);
  // fclose(fi);
  // fclose(fout);
   return 0;
}