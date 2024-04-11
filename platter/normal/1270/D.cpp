#include <cstdio>
#include <algorithm>
using namespace std;

int n,k;
int arr[500];
int cnt[500];
int p,val;

int main(void) {
    scanf("%d %d",&n,&k);
    for(int i=0;i<=k;i++) {
        printf("?");
        for(int j=0;j<=k;j++) {
            if (j!=i) {
                printf(" %d",j+1);
            }
        }
        printf("\n");
        fflush(stdout);
        fflush(stdin);
        scanf("%d %d",&p,&val);
        cnt[p-1]+=1;
        arr[p-1]=val;
    }
    int small=0;
    int big=0;
    int a=0;
    int b=0;
    for(int i=0;i<n;i++) {
        if (cnt[i]!=0) {
            a=i;
            for(int j=i+1;j<n;j++) {
                if (cnt[j]!=0) {
                    b=j;
                    break;
                }
            }
            break;
        }
    }
    if (arr[a]>arr[b]) {
        small=cnt[b];
        big=cnt[a];
    }
    else {
        small=cnt[a];
        big=cnt[b];
    }
    printf("! %d\n",big);
    return 0;
}