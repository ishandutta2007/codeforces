#include <bits/stdc++.h>
using namespace std;

int ans[50];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d\n",&n);
        int ret;
        for(int i=1;;i++) {
            int val=(1<<(i+1))-1;
            if (val>=n) {
                ret=i;
                break;
            }
        }
        printf("%d\n",ret);
        int minus=(1<<(ret+1))-1-n;
        for(int i=1;i<ret;i++) {
            ans[i]=(1<<(i-1));
        }
        if (minus<=(1<<(ret-1)))
            ans[ret]=(1<<(ret-1))-minus;
        else {
            ans[ret]=minus%2;
            ans[ret-1]=(1<<(ret-2))-(minus-(1<<(ret-1))+1)/2;
        }
        for(int i=1;i<=ret;i++) {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
}