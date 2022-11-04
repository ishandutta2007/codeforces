#include <cstdio>

int main(){
    int t,s,x;
    scanf("%d%d%d" ,&t,&s,&x);
    x-=t;
    if(x<0)
       printf("NO");
    else
    if(x==1){
       if(s==1)
         printf("YES");
       else
         printf("NO");
    }
    else
      if(x%s==1||x%s==0)
        printf("YES");
      else
        printf("NO");
    return 0;
}