#include<bits/stdc++.h>
using namespace std;

char str[100001];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d",&n,&k);
        scanf("%s",str);
        int cntl=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++) {
            if (str[i]=='L') {
                cntl++;
            }
        }
        if (cntl==n) {
            printf("%d\n",max(0,2*min(n,k)-1));
            continue;
        }
        int ret=0;
        for(int i=0;i<n;i++) {
            if (str[i]=='W') {
                if (i&&str[i-1]=='W') {
                    ret+=2;
                }
                else {
                    ret++;
                }
            }
        }
        int prev=-1;
        for(int i=0;i<n;i++) {
            if (str[i]=='W') {
                if (prev!=-1&&prev+1!=i) {
                    pq.push(i-prev-1);
                }
                prev=i;
            }
        }
        k=min(k,cntl);
        while (!pq.empty()&&k>=pq.top()) {
            k-=pq.top();
            ret+=2*pq.top()+1;
            pq.pop();
        }
        ret+=2*k;
        printf("%d\n",ret);
    }
}