#include<stdio.h>
#include<string.h>
char na[110][100];
int cnt[110][3];
char t[100];
inline int gn(){
    scanf("%s",t);
    int i;
    for(i=0;i<8;i++){
        if(i%3==2)continue;
        if(t[i]!=t[0])break;
    }
    if(i==8)return 0;
    int p=0;
    for(i=1;i<8;i++){
        if(i%3==2)continue;
        if(t[i]>=t[p])break;
        p=i;
    }
    if(i==8)return 1;
    return 2;
}
int n;
inline void run(int x){
    int ma=-1,i,f=1;
    for(i=0;i<n;i++)if(ma<cnt[i][x])ma=cnt[i][x];
    for(i=0;i<n;i++){
        if(cnt[i][x]==ma){
            if(f)f=0;
            else printf(",");
            printf(" %s",na[i]);
        }
    }
    puts(".");
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int k;
        scanf("%d%s",&k,na[i]);
        while(k--)cnt[i][gn()]++;
    }
    printf("If you want to call a taxi, you should call:");
    run(0);
    printf("If you want to order a pizza, you should call:");
    run(1);
    printf("If you want to go to a cafe with a wonderful girl, you should call:");
    run(2);
}