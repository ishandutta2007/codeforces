#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[100000];
int cnt[100000];

long long cost(long long x,int k) {
    return (x/k)*(x/k)*(k-x%k)+(x/k+1)*(x/k+1)*(x%k);
}

typedef pair<long long,int> P;
priority_queue<P> pq;

int main(void) {
    int k;
    scanf("%d %d",&n,&k);
    long long ret=0;
    for(int i=0;i<n;i++) {
        scanf("%lld",&arr[i]);
        ret+=arr[i]*arr[i];
        cnt[i]=1;
    }
    for(int i=0;i<n;i++) {
        pq.push(P(cost(arr[i],1)-cost(arr[i],2),i));
    }
    for(int i=0;i<k-n;i++) {
        ret-=pq.top().first;
        int now=pq.top().second;
        cnt[now]++;
        pq.pop();
        pq.push(P(cost(arr[now],cnt[now])-cost(arr[now],cnt[now]+1),now));
    }
    printf("%lld",ret);
}