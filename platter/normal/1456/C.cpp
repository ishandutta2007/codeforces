#include <bits/stdc++.h>
using namespace std;

int n,k;
long long arr[500000];

int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        scanf("%lld",&arr[i]);
    }
    sort(arr,arr+n);
    int pos=n;
    long long sum=0;
    for(int i=n-1;i>=0;i--) {
        sum+=arr[i];
        if (sum>=0) {
            pos--;
        }
        else {
            break;
        }
    }
    long long ret=0;
    for(int i=0;i<pos;i++) {
        ret+=arr[i]*(i/(k+1));
    }
    long long val=(pos+k)/(k+1);
    for(int i=pos;i<n;i++) {
        ret+=val*arr[i];
        val++;
    }
    printf("%lld",ret);
}