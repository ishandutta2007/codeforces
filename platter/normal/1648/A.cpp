#include <bits/stdc++.h>
using namespace std;

long long cnt[317];
vector<int> arr[317];
long long total[317];
typedef pair<int,int> P;
vector<P> v[100001];

int main(void) {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        arr[i].resize(m);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
            v[arr[i][j]].push_back(P(j,i));
        }
    }
    long long ret=0;
    for(int i=1;i<=100000;i++) {
        sort(v[i].begin(),v[i].end());
        memset(total,0,sizeof(total));
        memset(cnt,0,sizeof(cnt));
        for(int j=0;j<v[i].size();j++) {
            int x=v[i][j].second;
            int y=v[i][j].first;
            for(int k=0;k<n;k++) {
                ret+=(x-k>0?x-k:k-x)*cnt[k]+cnt[k]*y-total[k];
            }
            total[x]+=y;
            cnt[x]++;
        }
    }
    printf("%lld",ret);
}