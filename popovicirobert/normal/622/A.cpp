#include <cstdio>

int main(){
   // FILE*fi,*fout;
    long long n,x;
  //  fi=fopen("A.in" ,"r");
   // fout=fopen("A.out" ,"w");
    scanf("%I64d" ,&n);
    x=1;
    while((x*(x+1))/2<n)
       x++;
    x--;
    printf("%I64d" ,n-(x*(x+1))/2);
   // fclose(fi);
   // fclose(fout);
    return 0;
}