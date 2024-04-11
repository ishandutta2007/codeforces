#include <cstdio>

int main(){
    int i,n,j,flag,m;
    char a;
    scanf("%d %d " ,&n,&m);
    flag=1;
    for(i=1;i<=n;i++){
       for(j=1;j<=m;j++){
          a=fgetc(stdin);
          if(a=='C'||a=='M'||a=='Y')
            flag=0;
          a=fgetc(stdin);
       }
    }
    if(flag==1)
      printf("#Black&White");
    else
      printf("#Color");
    return 0;
}