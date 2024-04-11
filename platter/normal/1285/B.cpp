#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        long long total=0;
        long long ret=0;
        long long maxi=-1e9;
        int n;
        scanf("%d\n",&n);
        int st=0;
        for(int i=0;i<n;i++) {
            if (ret<=0) {
                ret=0;
                st=i;
            }
            long long x;
            scanf("%lld ",&x);
            ret+=x;
            total+=x;
            if (st!=0||i!=n-1) {
                maxi=max(maxi,ret);
            }
        }
        scanf("\n");
        if (total>maxi) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}