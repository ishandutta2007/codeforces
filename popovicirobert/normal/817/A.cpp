#include <bits/stdc++.h>

int main() {
   // FILE * fi, * fout;
    int x1,y1,x2,y2,x,y;
    //fi = fopen("A.in" ,"r");
    //fout = fopen("A.out" ,"w");
    //fi=stdin;
   // fout=stdout;
    scanf("%d%d%d%d" ,&x1,&y1,&x2,&y2);
    scanf("%d%d" ,&x,&y);
    if(std::abs(y1-y2)%y==0&&std::abs(x1-x2)%x==0){
      if((std::abs(y1-y2)/y)%2==(std::abs(x1-x2)/x)%2)
        printf("YES");
      else
        printf("NO");
    }
    else
      printf("NO");
    //fclose(fi);
    //fclose(fout);
    return 0;
}