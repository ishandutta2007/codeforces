#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int n,q;
int cnt=0;

int main(void) {
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        if (arr[i]==1) {
            cnt++;
        }
    }
    for(int i=0;i<q;i++) {
        int t,x;
        scanf("%d %d",&t,&x);
        if (t==1) {
            x--;
            if (arr[x]==0) {
                cnt++;
            }
            else {
                cnt--;
            }
            arr[x]^=1;
        }
        else {
            if (x<=cnt) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
    }
}