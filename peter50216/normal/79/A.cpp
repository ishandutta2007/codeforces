#include<stdio.h>
int a,b;
int s(){
    int x=0;
    while(a&&x<=120){
    x+=100;a--;
    }
    while(b&&x<=210){
    x+=10;b--;
    }
    if(x==220)return 0;
    return 1;
}
int t(){
    int x=0;
    if(b>=22){
    b-=22;
    return 0;
    }else if(b>=12){
    if(a==0)return 1;
    b-=12;
    a--;
    return 0;
    }else if(b>=2){
    if(a<=1)return 1;
    b-=2;
    a-=2;
    return 0;
    }else return 1;
}
int main(){
    scanf("%d%d",&a,&b);
    while(1){
    if(s()){
        puts("Hanako");
        return 0;
    }
    if(t()){
        puts("Ciel");
        return 0;
    }
    }
}