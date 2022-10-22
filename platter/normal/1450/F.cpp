#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
int n;
int arr[100000];
int cnt[100001];
int cnt1[100001];
int cnt2[100001];

void clean() {
    for(int i=1;i<=n;i++) {
        cnt[i]=0;
        cnt1[i]=0;
        cnt2[i]=0;
    }
}

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            cnt[arr[i]]++;
        }
        bool flag=true;
        for(int i=1;i<=n;i++) {
            if (cnt[i]>(n+1)/2) {
                printf("-1\n");
                flag=false;
                break;
            }
        }
        if (!flag) {
            clean();
            continue;
        }
        int prev=-1;
        int ret=0;
        for(int i=0;i<n;i++) {
            if (i==n-1||arr[i]==arr[i+1]) {
                if (arr[prev+1]==arr[i]) {
                    cnt1[arr[i]]++;
                }
                else {
                    cnt2[arr[prev+1]]++;
                    cnt2[arr[i]]++;
                }
                ret++;
                prev=i;
            }
        }
        ret--;
        int sum1=0;
        for(int i=1;i<=n;i++) {
            sum1+=cnt1[i];
        }
        flag=false;
        int mx=-1;
        int mp=-1;
        for(int i=1;i<=n;i++) {
            if (cnt1[i]>mx) {
                mx=cnt1[i];
                mp=i;
            }
        }
        int cn=mx;
        prev=-1;
        for(int i=0;i<n;i++) {
            if (i==n-1||arr[i]==arr[i+1]) {
                if (arr[prev+1]==arr[i]) {
                    if (arr[i]!=mp) {
                        cn--;
                    }
                }
                else {
                    if (arr[prev+1]!=mp&&arr[i]!=mp) {
                        cn--;
                    }
                }
                prev=i;
            }
        }
        if (cn<=0) {
            printf("%d\n",ret);
        }
        else {
            printf("%d\n",ret+cn-1);
        }
        clean();
    }
}