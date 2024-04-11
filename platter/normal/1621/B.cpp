#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        priority_queue<P,vector<P>,greater<P>> pq1;
        map<P,int> mp;
        priority_queue<P> pq2;
        int mn=1e9+7;
        int mx=-mn;
        for(int i=0;i<n;i++) {
            int l,r,c;
            scanf("%d %d %d",&l,&r,&c);
            mn=min(mn,l);
            mx=max(mx,r);
            pq1.push(P(l,c));
            pq2.push(P(r,-c));
            if (mp.find(P(l,r))==mp.end()||mp[P(l,r)]>c) {
                mp[P(l,r)]=c;
            }
            int ret=pq1.top().second-pq2.top().second;
            if (mp.find(P(mn,mx))!=mp.end()) {
                ret=min(ret,mp[P(mn,mx)]);
            }
            printf("%d\n",ret);
        }
    }
    return 0;
}