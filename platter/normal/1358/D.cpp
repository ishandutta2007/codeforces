#include <bits/stdc++.h>
using namespace std;

long long arr[200001];
long long psum[400001];
long long xpsum[400001];

int main(void) {
    int n;
    long long x;
    scanf("%d %lld\n",&n,&x);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&arr[i]);
    }
    long long ret=0;
    for(int i=1;i<=2*n;i++) {
        psum[i]=psum[i-1]+arr[(i-1)%n+1];
        xpsum[i]=xpsum[i-1]+(arr[(i-1)%n+1]*(arr[(i-1)%n+1]+1))/2;
    }
    for(int i=0;i<n;i++) {
        long long val=psum[i]+x;
        int ind=upper_bound(psum,psum+2*n+1,val)-psum;
        ind--;
        long long lef=psum[i]+x-psum[ind];
        long long cal=xpsum[ind]-xpsum[i];
        cal+=(lef*(lef+1))/2;
        ret=max(ret,cal);
    }
    reverse(arr+1,arr+n+1);
    for(int i=1;i<=2*n;i++) {
        psum[i]=psum[i-1]+arr[(i-1)%n+1];
        xpsum[i]=xpsum[i-1]+(arr[(i-1)%n+1]*(arr[(i-1)%n+1]+1))/2;
    }
    for(int i=0;i<n;i++) {
        long long val=psum[i]+x;
        int ind=upper_bound(psum,psum+2*n+1,val)-psum;
        ind--;
        long long lef=psum[i]+x-psum[ind];
        lef=arr[ind%n+1]-lef;
        long long cal=xpsum[ind]-xpsum[i];
        cal+=(arr[ind%n+1]*(arr[ind%n+1]+1))/2-(lef*(lef+1))/2;
        ret=max(ret,cal);
    }
    printf("%lld",ret);
}