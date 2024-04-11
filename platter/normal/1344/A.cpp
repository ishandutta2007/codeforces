#include <bits/stdc++.h>
using namespace std;

long long arr[200005];
bool cnt[500000];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            scanf("%lld",&arr[i]);
            arr[i]%=n;
            arr[i]+=n;
            arr[i]%=n;
        }
        for(int i=0;i<n;i++) {
            cnt[i]=false;
        }
        bool flag=true;
        for(int i=0;i<n;i++) {
            if (cnt[(i+arr[i])%n]) {
                flag=false;
                break;
            }
            cnt[(i+arr[i])%n]=true;
        }
        printf("%s\n",flag?"YES":"NO");
    }
}