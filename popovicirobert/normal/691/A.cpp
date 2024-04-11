#include <cstdio>

int main(){
//    FILE*fi,*fout;
    int i,n,x,con;
  //  fi=("A.in" ,"r");
   // fout=fopen("A.out" ,"w");
     scanf("%d" ,&n);
     con=0;
     for(i=1;i<=n;i++){
        scanf("%d" ,&x);
        con+=x;
     }
     if(n==1){
        if(con==1)
            printf("YES");
        else
            printf("NO");
     }
     else{
         if(con==n-1)
            printf("YES");
        else
            printf("NO");
     }
  //  fclose(fi);
   // fclose(fout);
    return 0;
}