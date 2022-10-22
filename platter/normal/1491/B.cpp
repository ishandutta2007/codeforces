#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int n,q;
int cnt=0;

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,u,v;
        scanf("%d %d %d",&n,&u,&v);
        bool flag=false;
        bool f=false;
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            if (i) {
                if (arr[i-1]!=arr[i]) {
                    flag=true;
                }
                if (arr[i-1]>arr[i]+1||arr[i]>arr[i-1]+1) {
                    f=true;
                }
            }
        }
        if (f) {
            printf("0\n");
            continue;
        }
        printf("%d\n",flag?min(u,v):min(u+v,2*v));
    }
}