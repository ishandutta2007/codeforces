#include <bits/stdc++.h>
using namespace std;

long long arr[500000];
long long bit[60];
const int mod=1e9+7;

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        memset(bit,0,sizeof(bit));
        for(int i=0;i<n;i++) {
            scanf("%lld",&arr[i]);
            for(int j=0;j<60;j++) {
                bit[j]+=(arr[i]&(1LL<<j));
                bit[j]%=mod;
            }
        }
        long long ret=0;
        for(int i=0;i<n;i++) {
            long long andsum=0;
            long long orsum=0;
            for(int j=0;j<60;j++) {
                if (arr[i]&(1LL<<j)) {
                    orsum+=1LL*n*((1LL<<j)%mod);
                    orsum%=mod;
                    andsum+=bit[j];
                    andsum%=mod;
                }
                else {
                    orsum+=bit[j];
                    orsum%=mod;
                }
            }
            ret+=andsum*orsum;
            ret%=mod;
        }
        printf("%lld\n",ret);
    }
}