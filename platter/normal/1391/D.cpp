#include <bits/stdc++.h>
using namespace std;

int arr[3][1000000];

int main(void) {
    int n,m;
    scanf("%d %d\n",&n,&m);
    if (n>=4) {
        printf("-1");
        return 0;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%1d",&arr[i][j]);
        }
    }
    if (n==1) {
        printf("0");
        return 0;
    }
    if (n==2) {
        int ret1=0;
        int ret2=0;
        int zero=0;
        int one=0;
        for(int i=0;i<m;i+=2) {
            if (arr[0][i]==arr[1][i]) {
                zero++;
            }
            else {
                one++;
            }
        }
        ret1+=zero;
        ret2+=one;
        zero=0;
        one=0;
        for(int i=1;i<m;i+=2) {
            if (arr[0][i]==arr[1][i]) {
                zero++;
            }
            else {
                one++;
            }
        }
        ret1+=one;
        ret2+=zero;
        printf("%d",min(ret1,ret2));
        return 0;
    }
    if (n==3) {
        int ret[4]={0,0,0,0};
        for(int i=0;i<m;i+=2) {
            int val=(arr[0][i]!=arr[1][i])*2+(arr[1][i]!=arr[2][i]);
            for(int j=0;j<4;j++) {
                if (val!=j) {
                    ret[j]++;
                }
            }
        }
        for(int i=1;i<m;i+=2) {
            int val=(arr[0][i]!=arr[1][i])*2+(arr[1][i]!=arr[2][i]);
            for(int j=0;j<4;j++) {
                if ((val^3)!=j) {
                    ret[j]++;
                }
            }
        }
        printf("%d",min({ret[0],ret[1],ret[2],ret[3]}));
        return 0;
    }
}