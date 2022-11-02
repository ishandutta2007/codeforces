#include<stdio.h>
int cnt[10000];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        cnt[a]++;
    }
    int s=n;
    for(i=1;i<=n;i++)if(cnt[i])s--;
    printf("%d\n",s);
}