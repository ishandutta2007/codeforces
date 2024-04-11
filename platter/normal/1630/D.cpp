#include <bits/stdc++.h>
using namespace std;

int n,m;
long long arr[1000000];
long long even[1000000];
long long odd[1000000];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) {
            scanf("%lld",&arr[i]);
        }
        priority_queue<int> pq;
        for(int i=0;i<m;i++) {
            int x;
            scanf("%d",&x);
            pq.push(x);
        }
        while (pq.size()>1) {
            int now=pq.top();
            pq.pop();
            int now2=pq.top();
            if (now==now2) {
                continue;
            }
            if (now%now2!=0)
                pq.push(now%now2);
        }
        int k=pq.top();
        long long e=0;
        long long o=0;
        for(int i=0;i<k;i++) {
            long long sum=0;
            long long mx=-2e9;
            long long mn=2e9;
            int cnt=0;
            for(int j=i;j<n;j+=k) {
                if (arr[j]<=0) {
                    cnt++;
                    mx=max(mx,arr[j]);
                    sum+=-arr[j];
                }
                else {
                    mn=min(mn,arr[j]);
                    sum+=arr[j];
                }
            }
            if (cnt%2==0) {
                even[i]=sum;
                odd[i]=sum+2*max(mx,-mn);
            }
            else {
                odd[i]=sum;
                even[i]=sum+2*max(mx,-mn);
            }
            e+=even[i];
            o+=odd[i];
        }
        printf("%lld\n",max(e,o));
    }
}