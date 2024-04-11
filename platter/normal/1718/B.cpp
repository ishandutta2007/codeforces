#include <bits/stdc++.h>
using namespace std;

long long fib[61];
long long arr[100];
int cnt[61];
long long save[61];

int main() {
    int tc;
    scanf("%d",&tc);
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<=60;i++) {
        fib[i]=fib[i-1]+fib[i-2];
    }
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%lld",&arr[i]);
        }
        bool f=false;
        memset(cnt,0,sizeof(cnt));
        int sum=0;
        for(int i=0;i<n;i++) {
            long long x=arr[i];
            for(int j=60;j>0;j--) {
                if (x>=fib[j]) {
                    cnt[j]++;
                    x-=fib[j];
                    sum++;
                }
            }
        }
for(int i=1;i<=60;i++) save[i]=cnt[i];
        for(int ind=0;ind<n;ind++) {
for(int i=1;i<=60;i++) cnt[i]=save[i];
sum=0;
for(int i=1;i<=60;i++) sum+=cnt[i];
            long long x=arr[ind];
            for(int j=60;j>0;j--) {
                if (x>=fib[j]) {
                    cnt[j]--;
                    x-=fib[j];
                    sum--;
                }
            }
            arr[ind]--;
            x=arr[ind];
            bool save=true;
            for(int j=60;j>0;j--) {
                if (x>=fib[j]) {
                    cnt[j]++;
                    x-=fib[j];
                    sum++;
                    if (j==1) {
                        save=false;
                    }
                }
            }
            arr[ind]++;
            if (!save) {
                continue;
            }
            if (sum==0) {
                f=true;
                break;
            }
            bool flag=true;
            for(int i=1;i<=sum;i++) {
                if (cnt[i]!=1) {
                    flag=false;
                    break;
                }
            }
            if (flag) {
                f=true;
                break;
            }
        }
        printf("%s\n",f?"YES":"NO");
    }
}