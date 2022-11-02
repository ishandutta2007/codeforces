#include <bits/stdc++.h>
using namespace std;

int tipo[33];

int main() {
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++){
        printf("1\n");
        fflush(stdout);
        int a;
        scanf("%d",&a);
        if(a == 0) return 0;
        tipo[i] = a;
    }
    int lo = 1, hi = m;
    int c = -1;
    while(lo < hi){
        c++;
        c %= n;
        int mid = (lo+hi)/2;
        printf("%d\n",mid);
        fflush(stdout);
        int a;
        scanf("%d",&a);
        if(tipo[c] == -1) a = -a;
        if(a == 0)
            return 0;
        if(a == 1)
            lo = mid+1;
        else
            hi = mid-1;
        }
    printf("%d\n",hi);
}