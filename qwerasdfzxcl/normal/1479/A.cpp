#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];

int main(){
    int n;
    scanf("%d", &n);
    a[0]=1e9, a[n+1]=1e9;
    int l=0, r=n+1;
    while(l<r-3){
        int m=(l+r)/2;
        printf("? %d\n", m);
        fflush(stdout);
        scanf("%d", &a[m]);
        printf("? %d\n", m+1);
        fflush(stdout);
        scanf("%d", &a[m+1]);
        printf("? %d\n", m-1);
        fflush(stdout);
        scanf("%d", &a[m-1]);
        if (a[m]<min(a[m-1], a[m+1])){
            printf("! %d\n", m);
            fflush(stdout);
            return 0;
        }
        if (a[m]>a[m-1]) r=m;
        else l=m;
    }
    for (int i=l+1;i<r;i++){
        printf("? %d\n", i);
        fflush(stdout);
        scanf("%d", &a[i]);
    }
    for (int i=l+1;i<r;i++){
        if (a[i]<min(a[i-1], a[i+1])){
            printf("! %d\n", i);
            fflush(stdout);
            return 0;
        }
    }
    return 1;
}