#include<stdio.h>

int main(){
  char s[128];
  while(scanf("%s",s)!=EOF){
    printf("NO\n");
    fflush(stdout);
  }
  return 0;
}