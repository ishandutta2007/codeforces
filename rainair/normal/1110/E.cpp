#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000000+5;
int a[MAXN],N,t[MAXN];
int c1[MAXN],c2[MAXN];

int main(){
    scanf("%d",&N);
    for(int i = 1;i <= N;i++) scanf("%d",a+i);
    for(int i = 1;i <= N;i++) scanf("%d",t+i);
    for(int i = 1;i <= N;i++) c1[i] = a[i]-a[i-1];
    for(int i = 1;i <= N;i++) c2[i] = t[i]-t[i-1];
    if(a[1] != t[1] || a[N] != t[N]){printf("No\n");return 0;}
    else{
        sort(c1+1,c1+N+1);sort(c2+1,c2+N+1);
       for(int i = 1;i <= N;i++) if(c1[i] != c2[i]){printf("No\n");return 0;}
        printf("Yes\n");
    }
    return 0;
}