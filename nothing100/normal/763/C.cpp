#include<bits/stdc++.h>
#define MAXN 10000010
#define mo 20101009
#define inf 1000000000
#define LL long long
using namespace std;
int n,m,a[100010],tot,f,k;
map<int,int>hav;
int check(int x){
    int tmp=1,sta=a[0];
    while (hav[(sta+x)%m]){
        tmp++;
        sta=(sta+x)%m;
    }
    sta=a[0];
    while (hav[(sta-x+m)%m]){
        tmp++;
        sta=(sta-x+m)%m;
    }
    if (tmp==n){
        if (!f) printf("%d %d\n",sta,x);
        else printf("%d %d\n",(sta-x+m)%m,m-x);
        return 1;
    }
    return 0;
}
int main(){
    scanf("%d%d",&m,&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        hav[a[i]]++;
    }
    if (2*n>m){
        f=1;
        n=0;
        for (int i=0;i<m;i++)
        if (hav[i]) hav[i]=0;
        else{
            hav[i]=1;
            a[n++]=i;
        }
    }
    if (n==0){
        printf("0 1\n");
        return 0;
    }
    else if (n==1){
        if (!f) printf("%d 1\n",a[0],1);
        else printf("%d 1\n",(a[0]+1)%m,1);
        return 0;
    }
    for (int i=1;i<n;i++){
        if (check((a[i]-a[0]+m)%m)) return 0;
    }
    printf("-1\n");
}