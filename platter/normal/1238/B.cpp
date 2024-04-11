#include <stdio.h>
#include <algorithm>

using namespace std;

int a[300000];

int candoink(int arr[], long long k, long long r, int size) {
    int ret=0;
    for(int i=0;i<size;i++) {
        if (arr[i]>k*r)
        ret+=1;
    }
    if (ret<=k)
    return 1;
    if (ret>k)
    return 0;
}

void erase(int a[], int n) {
    for(int i=1;i<n;i++) {
        if (a[i-1]==a[i]) {
            a[i-1]=0;
        }
    }
}

long long search(int a[], int n, long long r) {
    long long low=0;
    long long high=n;
    long long mid=(low+high)/2;
    while(low<=high) {
    	mid=(low+high)/2;
        if (candoink(a,mid,r,n)==1&&candoink(a,mid-1,r,n)==0)
        break;
        if (candoink(a,mid,r,n)==0)
        low=mid+1;
        else if (candoink(a,mid-1,r,n)==1)
        high=mid-1;
    }
    return mid;
}

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
    	int n;
        long long r;
        scanf("%d %lld\n", &n, &r);
        for(int i=0;i<n;i++) {
            scanf("%d ", &a[i]);
        }
        scanf("\n");
        sort(a,a+n);
        erase(a,n);
        int ans=search(a,n,r);
        printf("%d\n", ans);
    }
    return 0;
}