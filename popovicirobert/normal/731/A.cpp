#include <cstdio>
inline int getmin(int a,int b){
    if(a<b) return a;
    return b;
}
int main(){
 //  FILE*fi,*fout;
   int ans;
   char a,x;
   //fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   a=fgetc(stdin);
   x='a';
   ans=0;
   while(a>='a'&&a<='z'){
      a-='a';
      x-='a';
      if(x<=a)
        ans=ans+getmin(a-x,26-a+x);
      else
        ans=ans+getmin(x-a,26-x+a);
      x=a+'a';
      a=fgetc(stdin);
   }
   printf("%d" ,ans);
 //  fclose(fi);
 //  fclose(fout);
   return 0;
}