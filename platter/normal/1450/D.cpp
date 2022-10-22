#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
int n;
int lcnt[300001];
int rcnt[300001];
int arr[300000];
vector<P> vec[300001];
const int INF=1e9;
vector<P> v;

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        stack<P> s;
        s.push(P(-1,0));
        for(int i=0;i<n;i++) {
            while (!s.empty()&&s.top().first>=arr[i]) {
                lcnt[i]+=s.top().second;
                s.pop();
            }
            s.push(P(arr[i],lcnt[i]+1));
        }
        while (!s.empty()) {
            s.pop();
        }
        s.push(P(-1,0));
        for(int i=n-1;i>=0;i--) {
            while (!s.empty()&&s.top().first>arr[i]) {
                rcnt[i]+=s.top().second;
                s.pop();
            }
            s.push(P(arr[i],rcnt[i]+1));
        }
        for(int i=0;i<n;i++) {
            vec[arr[i]].push_back(P(0,1));
            vec[arr[i]].push_back(P(lcnt[i]+1,-1));
            vec[arr[i]].push_back(P(rcnt[i]+1,-1));
            vec[arr[i]].push_back(P(lcnt[i]+rcnt[i]+2,1));
            //printf("%d %d\n",lcnt[i],rcnt[i]);
        }
        for(int i=1;i<=n;i++) {
            sort(vec[i].begin(),vec[i].end());
            int prev=-1;
            int axis=0;
            int val=0;
            int ind=0;
            while (ind<vec[i].size()) {
                int now=vec[i][ind].first;
                if (now>n-i+1) {
                    now=n-i+1;
                }
                if (axis==0) {
                    if (val==1) {
                        v.push_back(P(prev+1,1));
                        v.push_back(P(now+1,-1));
                    }
                }
                if (axis>0) {
                    if (val==0&&axis==1) {
                        v.push_back(P(prev+1,1));
                        v.push_back(P(prev+2,-1));
                    }
                }
                if (axis<0) {
                    if (val%(-axis)==1%(-axis)) {
                        int tm=(val-1)/(-axis)+prev;
                        if (prev<tm&&tm<=now) {
                            v.push_back(P(tm,1));
                            v.push_back(P(tm+1,-1));
                        }
                    }
                }
                if (now>=n-i+1) {
                    break;
                }
                val+=(now-prev)*axis;
                while (vec[i][ind].first==now) {
                    axis+=vec[i][ind].second;
                    ind++;
                }
                prev=now;
            }
        }
        sort(v.begin(),v.end());
        int ret=0;
        int ind=0;
        while (ind<v.size()&&v[ind].first==0) {
            ret+=v[ind].second;
            ind++;
        }
        for(int i=1;i<=n;i++) {
            while (ind<v.size()&&v[ind].first==i) {
                ret+=v[ind].second;
                ind++;
            }
            if (ret==n-i+1) {
                printf("1");
            }
            else {
                printf("0");
            }
        }
        printf("\n");
        v.clear();
        for(int i=1;i<=n;i++) {
            vec[i].clear();
        }
        for(int i=0;i<n;i++) {
            lcnt[i]=0;
            rcnt[i]=0;
        }
    }
}