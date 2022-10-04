#include <stdio.h>
#include <algorithm>
int main(){
int x,y;scanf("%d%d",&x,&y);int a=y,b=y,c=y;
int cnt=0;
while(a<x){
cnt++;
a = std::min(x,b+c-1);
std::swap(a,b);std::swap(b,c);
}
printf("%d\n",cnt);
}