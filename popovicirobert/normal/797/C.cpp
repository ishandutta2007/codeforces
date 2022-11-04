#include <bits/stdc++.h>
#define MAXN 100000
#define SIGMA 26
char A[MAXN+1];
std::vector <char> B;
std::vector <char> sol;
int fr[SIGMA];
int main(){
   FILE*fi,*fout;
   int i,n,cnt,min,j;
   //fi=fopen("A.in" ,"r");
   //fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%s" ,&A);
   n=strlen(A);
   for(i=0;i<n;i++){
     fr[A[i]-'a']++;
     A[i]-='a';
   }
   i=0;
   while(i<n){
     int min=SIGMA+1;
     cnt=0;
     for(j=0;j<A[i];j++){
       cnt+=fr[j];
       if(fr[j])
         min=std::min(min,j);
     }
     if(cnt>0){
       while(!B.empty()&&B.back()<=min){
          sol.push_back(B.back());
          B.pop_back();
       }
       j=i;
       while(A[j]>min){
          fr[A[j]]--;
          B.push_back(A[j]);
          j++;
       }
       i=j;
     }
     else{
       fr[A[i]]--;
       while(!B.empty()&&B.back()<=A[i]){
          sol.push_back(B.back());
          B.pop_back();
       }
       B.push_back(A[i]);
       i++;
     }
   }
   while(!B.empty()){
      sol.push_back(B.back());
      B.pop_back();
   }
   for(auto it:sol)
     fprintf(fout,"%c" ,it+'a');
   //fclose(fi);
   //fclose(fout);
   return 0;
}