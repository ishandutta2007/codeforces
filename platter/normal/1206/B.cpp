#include <stdio.h>
#include <math.h>
 
int mop(int arr[], int size) {
    int count=0;
    for(int i=0;i<size;i++) {
        if (arr[i]<0)
        count+=1;
    }
    if (count%2==0)
    return 1;
    else
    return -1;
}
 
long long ans(int arr[], int size) {
    long long total=0;
    int zeroexist=0;
    for(int i=0;i<size;i++) {
        if (arr[i]==0) {
            total+=1;
            zeroexist=1;
        }
        else
        total+=fabs(arr[i])-1;
    }
    if (zeroexist==0) {
        if (mop(arr,size)==-1)
        return total+2;
        else
        return total;
    }
    else
    return total;
}
 
int main(void) {
    int n;
    scanf("%d\n", &n);
    int arr[100000];
    for(int i=0;i<n;i++) {
        scanf("%d ", &arr[i]);
    }
    printf("%lld", ans(arr,n));
    return 0;
}