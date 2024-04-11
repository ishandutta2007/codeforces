#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,p,x;
    bool a[300001]={};
    scanf("%d",&n);
    p=n;
    printf("1 ");
    while(n--){
        scanf("%d",&x),a[x]=1,p++;
        while(a[--p]);
        printf("%d ",p-n+1);
    }
}