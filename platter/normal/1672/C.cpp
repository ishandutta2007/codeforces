#include <bits/stdc++.h>
using namespace std;

int arr[200000];
bool chk[200005];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
for(int i=0;i<n+5;i++) {
chk[i]=false;
}
        stack<int> s;
        int cnt=0;
        int ret=0;
        for(int i=n-2;i>=0;i--) {
            if (arr[i]==arr[i+1]) {
                chk[i+1]=true;
                cnt++;
            }
        }
        for(int i=1;i<n;i++) {
            if (cnt<=1) {
                break;
            }
            if (chk[i]) {
                cnt--;
                chk[i]=false;
                if (chk[i+2]) {
                    cnt--;
                }
                chk[i+2]=false;
                if (!chk[i+1]) {
                    cnt++;
                }
                chk[i+1]=true;
                ret++;
            }
        }
        printf("%d\n",ret);
    }
}