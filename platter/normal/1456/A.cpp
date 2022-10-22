#include <bits/stdc++.h>
using namespace std;

int val[100005];
int arr[100005];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,p,k;
        scanf("%d %d %d",&n,&p,&k);
        p--;
        for(int i=0;i<n;i++) {
            scanf("%1d",&arr[i]);
        }
        int x,y;
        scanf("%d %d",&x,&y);
        for(int i=0;i<n;i++) {
            val[i%k]+=1-arr[i];
        }
        int ret=2e9;
        for(int i=0;i<n;i++) {
            if (i>=p) {
                ret=min(ret,val[i%k]*x+(i-p)*y);
            }
            if (arr[i]==0) {
                val[i%k]--;
            }
        }
        printf("%d\n",ret);
    }
}