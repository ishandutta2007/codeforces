#include <bits/stdc++.h>
using namespace std;

int julde(int x) {
    return x>0?x:-x;
}

int main(void) {
    int tc;
    scanf("%d",&tc);
    int arr[99];
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<n;i++) {
            printf("%d ",i%2==0?julde(arr[i]):-julde(arr[i]));
        }
        printf("\n");
    }
}