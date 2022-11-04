#include <bits/stdc++.h>
std::vector <int> sol;
int main(){
   FILE*fi,*fout;
   int i,n,k,aux,d,e;
 //  fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d" ,&n,&k);
   aux=n;
   d=2;
   while(d*d<=n){
      e=0;
      while(n%d==0){
         n/=d;
         sol.push_back(d);
         e++;
      }
      d++;
   }
   if(n>1)
     sol.push_back(n);
   if(sol.size()<k)
     fprintf(fout,"-1");
   else{
     for(i=1;i<k;i++){
        fprintf(fout,"%d " ,sol[i]);
        aux/=sol[i];
     }
     fprintf(fout,"%d" ,aux);
   }
   //fclose(fi);
   //fclose(fout);
   return 0;
}