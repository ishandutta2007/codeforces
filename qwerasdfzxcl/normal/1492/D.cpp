#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int x[200200], y[200200];

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    m--;
    if (m==0){
        if (k==0){
            printf("Yes\n");
            printf("1");
            for (int i=0;i<n;i++) printf("0");
            printf("\n");
            printf("1");
            for (int i=0;i<n;i++) printf("0");
            printf("\n");
        }
        else printf("No\n");
        return 0;
    }
    if (n==0){
        if (k>=1){
            printf("No\n");
        }
        else{
            printf("Yes\n");
            for (int i=0;i<m+1;i++) printf("1");
            printf("\n");
            for (int i=0;i<m+1;i++) printf("1");
            printf("\n");
        }
        return 0;
    }
    if (k>=n+m){
        printf("No\n");
        return 0;
    }
    if (k<n){
        for (int i=0;i<m;i++){
            x[i]=1, y[i]=1;
        }
        y[m-1]=0;
        y[m-1+k]=1;
    }
    else{
        int tmp=n+m-1-k;
        for (int i=0;i<tmp;i++){
            x[n+m-1-i]=1;
            y[n+m-1-i]=1;
        }
        x[n+m-1-tmp]=0;
        y[n+m-1-tmp]=1;
        x[0]=1;
        for (int i=tmp+1;i<m;i++){
            x[n+m-1-i]=1;
            y[n+m-1-i]=1;
        }
    }
    printf("Yes\n");
    printf("1");
    for (int i=0;i<n+m;i++){
        printf("%d", x[i]);
    }
    printf("\n");
    printf("1");
    for (int i=0;i<n+m;i++) printf("%d", y[i]);
    return 0;
}