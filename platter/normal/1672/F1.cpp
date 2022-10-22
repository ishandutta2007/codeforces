#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

P arr[200000];
int cnt[200001];
int ret[200000];

bool comp(P a,P b) {
if (cnt[a.first]==cnt[b.first]) return a.first<b.first;
    return cnt[a.first]<cnt[b.first];
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i].first);
            arr[i].second=i;
            cnt[arr[i].first]++;
        }
        sort(arr,arr+n,comp);
        int val=n-cnt[arr[n-1].first];
        for(int i=val;i<n+val;i++) {
            ret[arr[i-val].second]=arr[i%n].first;
        }
for(int i=0;i<n;i++) {
printf("%d ",ret[i]);
}
        printf("\n");
        for(int i=1;i<=n;i++) {
            cnt[i]=0;
        }
    }
}