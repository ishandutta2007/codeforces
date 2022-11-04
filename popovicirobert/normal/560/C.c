#include <stdio.h>
#include <stdlib.h>
int getmin(int a,int b){
    if(a>b) return b;
    return a;
}
int getmax(int a,int b){
    if(a>b) return a;
    return b;
}
int main()
{
    int l1,l2,l3,l4,l5,l6,x,con,i;
    scanf("%d%d%d%d%d%d" ,&l1,&l2,&l3,&l4,&l5,&l6);
    con=0;
    if(l2>l6){
        x=l1;
       for(i=0;i<l6;i++){
          con=con+2*x+1;
          x++;
       }
       for(i=0;i<l2-l6;i++)
           con+=2*x;
        x=l4;
        for(i=0;i<l3;i++){
            con=con+2*x+1;
            x++;
        }
    }
    else{
       x=l1;
       for(i=0;i<l2;i++){
          con=con+2*x+1;
          x++;
       }
       for(i=0;i<l6-l2;i++)
           con+=2*x;
        x=l4;
        for(i=0;i<l5;i++){
            con=con+2*x+1;
            x++;
        }
    }
    printf("%d" ,con);
    return 0;
}