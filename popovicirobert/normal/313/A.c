#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d" ,&n);
    if(n>=0)
      printf("%d" ,n);
    else
       if(n/10>(n/100)*10+n%10)
          printf("%d" ,n/10);
        else
           printf("%d" ,(n/100)*10+n%10);
    return 0;
}