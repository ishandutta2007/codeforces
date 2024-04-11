#include <cstdio>
#include <algorithm>
using namespace std;

int sum(int a,int b,int c) {
    int ret1=a-b;
    int ret2=a-c;
    int ret3=b-c;
    if (ret1<0) {
        ret1*=-1;
    }
    if (ret2<0) {
        ret2*=-1;
    }
    if (ret3<0) {
        ret3*=-1;
    }
    return ret1+ret2+ret3;
}

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int a[3];
        for(int i=0;i<3;i++) {
            scanf("%d ",&a[i]);
        }
        scanf("\n");
        int mini=2147483647;
        for(int i=-1;i<=1;i++) {
            for(int j=-1;j<=1;j++) {
                for(int k=-1;k<=1;k++) {
                    mini=min(mini,sum(a[0]+i,a[1]+j,a[2]+k));
                }
            }
        }
        printf("%d\n",mini);
    }
    return 0;
}