#include<stdio.h>
char a[10],b[10],c[10];
char q[10]="6789TJQKA";
inline int r(char c){
    int i;
    for(i=0;i<10;i++)if(q[i]==c)return i;
}
inline int solve(){
    if(b[1]==c[1]){
    return r(b[0])>r(c[0]);
    }
    if(b[1]==a[0])return 1;
    return 0;
}
int main(){
    scanf("%s%s%s",a,b,c);
    puts(solve()?"YES":"NO");
}