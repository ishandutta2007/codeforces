#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100000];

long long ans(int l,int r,int bit) {
    if (bit==-1) {
        return 0;
    }
    int cut;
    bool flag=false;
    int prev=(arr[l]>>bit)%2;
    if ((arr[l]>>bit)%2==1||(arr[r]>>bit)%2==0) {
        return ans(l,r,bit-1);
    }
    for(int i=l;i<=r;i++) {
        if ((arr[i]>>bit)%2==1) {
            cut=i;
            break;
        }
    }
    return (1<<bit)+min(ans(l,cut-1,bit-1),ans(cut,r,bit-1));
}

int main(void) {
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++) {
        scanf("%d ",&arr[i]);
    }
    sort(arr,arr+n);
    printf("%lld",ans(0,n-1,29));
    return 0;
}