#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++){
        int l, r;
        scanf("%d%d", &l, &r);
        if(r<2*l) printf("YES\n");
        else printf("NO\n");
    }
}