#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n",&n);
        int cnt[10001];
        for(int i=0;i<=10000;i++) {
            cnt[i]=0;
        }
        for(int i=0;i<4*n;i++) {
            int x;
            scanf("%d ",&x);
            cnt[x]++;
        }
        vector<int> arr;
        bool flag=true;
        for(int i=0;i<=10000;i++) {
            if (cnt[i]%2==1) {
                flag=false;
                break;
            }
            for(int j=0;j<cnt[i]/2;j++) {
                arr.push_back(i);
            }
        }
        if (!flag) {
            printf("NO\n");
            continue;
        }
        int val=arr[0]*arr[n*2-1];
        for(int i=0;i<n;i++) {
            if (arr[n+i]*arr[n-1-i]!=val) {
                flag=false;
            }
        }
        if (flag) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}