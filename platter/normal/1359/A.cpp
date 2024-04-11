#include <bits/stdc++.h>
using namespace std;

int arr[50];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,m,k;
        scanf("%d %d %d\n",&n,&m,&k);
        arr[0]=min(m,n/k);
        m-=arr[0];
        printf("%d\n",arr[0]-(m+k-2)/(k-1));
    }
}