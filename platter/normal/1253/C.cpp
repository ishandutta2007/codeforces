#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int n,m;
    scanf("%d %d\n", &n, &m);
    long long arr[300000];
    for(int i=0;i<n;i++) {
        scanf("%lld ", &arr[i]);
    }
    sort(arr,arr+n);
    long long sum[300001];
    for(int i=0;i<m;i++) {
        sum[i]=0;
    }
    long long ret=0;
    for(int i=0;i<n;i++) {
        sum[i%m]+=arr[i];
        ret+=sum[i%m];
        printf("%lld ",ret);
    }
    return 0;
}