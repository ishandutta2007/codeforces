#include <cstdio>

int main(){
   // FILE*fi,*fout;
    int h,m,a,nr;
  //  fi=fopen("B.in" ,"r");
  //  fout=fopen("B.out" ,"w");
    scanf("%d:%d%d" ,&h,&m,&a);
    nr=(h*60+m+a)%1440;
    if(nr/60<10)
        printf("0%d:" ,nr/60);
    else
        printf("%d:" ,nr/60);
    if(nr%60<10)
        printf("0%d" ,nr%60);
    else
        printf("%d" ,nr%60);
 //   fclose(fi);
  //  fclose(fout);
    return 0;
}