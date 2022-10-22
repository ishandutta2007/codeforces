#include <bits/stdc++.h>
using namespace std;

int arr[100];
int cnt[101];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            cnt[abs(arr[i])]++;
        }
        int ret=0;
        for(int i=0;i<=100;i++) {
            if (cnt[i]>=2) {
                if (i==0) {
                    ret++;
                }
                else {
                    ret+=2;
                }
            }
            else if (cnt[i]==1) {
                ret++;
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}