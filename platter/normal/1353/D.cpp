#include <bits/stdc++.h>
using namespace std;

int n;
typedef pair<int,int> P;
int cnt=0;
int ret[300005];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        cnt=0;
        scanf("%d\n",&n);
        priority_queue<P> pq;
        pq.push(P(n-1,0));
        while (!pq.empty()) {
            int l=-pq.top().second;
            int r=l+pq.top().first;
            int mid=(l+r)/2;
            pq.pop();
            ret[mid]=++cnt;
            if (l<=mid-1) {
                pq.push(P(mid-1-l,-l));
            }
            if (mid+1<=r) {
                pq.push(P(r-mid-1,-mid-1));
            }
        }
        for(int i=0;i<n;i++) {
            printf("%d ",ret[i]);
        }
        printf("\n");
    }
}