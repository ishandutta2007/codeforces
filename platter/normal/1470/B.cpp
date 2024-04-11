#include <bits/stdc++.h>
using namespace std;

long long arr[300000];
int cnt[1000001];
int save[1000001];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int i=1;i<=1000000;i++) {
        for(int j=1;i*j*j<=1000000;j++) {
            if (save[i*j*j]==0)
                save[i*j*j]=i;
        }
    }
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%lld",&arr[i]);
        }
        int ret0=0;
        int ret1=0;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int val=save[arr[i]];
            cnt[val]++;
            if (val==1) {
                ret1++;
            }
            else if (cnt[val]%2==1) {
                ret1-=cnt[val]-1;
            }
            else {
                ret1+=cnt[val];
            }
            ret0=max(ret0,cnt[val]);
            v.push_back(val);
        }
        for(int i=0;i<v.size();i++) {
            cnt[v[i]]--;
        }
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++) {
            long long w;
            scanf("%lld",&w);
            if (w==0) {
                printf("%d\n",ret0);
            }
            else {
                printf("%d\n",max(ret0,ret1));
            }
        }
    }
}