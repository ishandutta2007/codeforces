#include <cstdio>


int main(){
  // FILE*fi,*fout;
   int a,b,c;
 //  fi=fopen("A.in" ,"r");
 //  fout=fopen("A.out" ,"w");
   scanf("%d%d%d" ,&a,&b,&c);
   if((c==0&&a==b)||(c!=0&&(b-a)%c==0&&(b-a)/c>=0))
      printf("YES");
   else
       printf("NO");
  // fclose(fi);
 //  fclose(fout);
   return 0;
}