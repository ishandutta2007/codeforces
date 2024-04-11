#include<stdio.h>
int cnt[1010];
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
	int a;
	scanf("%d",&a);
	cnt[a]++;
    }
    int a1=0,a2=0;
    for(int i=0;i<1010;i++)if(cnt[i]){
	a2++;
	a1=(a1>cnt[i]?a1:cnt[i]);
    }
    printf("%d %d\n",a1,a2);
}