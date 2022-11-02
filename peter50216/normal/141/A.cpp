#include<stdio.h>
char in[1000];
int cnt[1000];
inline void g(int c){
    scanf("%s",in);
    for(int i=0;in[i];i++)cnt[in[i]]+=c;
}
int main(){
    g(1);g(1);g(-1);
    int i;
    for(i=0;i<300;i++)if(cnt[i])break;
    puts(i<300?"NO":"YES");
}