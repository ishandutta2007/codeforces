#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
int l[maxn];
int r[maxn];
int q;
int w[maxn];
int ans[30];
vector<pair<int,int> > event;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d %d",&l[i],&r[i]);
    }
    scanf("%d",&q);
    for(int j=0;j<30;j++) {
        int len=1<<j;
        event.clear();
        for(int i=0;i<n;i++) {
            if(r[i]-l[i]+1>=len) ans[j]++;
            else {
                int x=l[i]%len;
                int y=r[i]%len;
                if(y<x) {
                    event.push_back({0,-1});
                    event.push_back({y,1});
                    event.push_back({x,-1});
                    event.push_back({len-1,1});
                }
                else {
                    event.push_back({x,-1});
                    event.push_back({y,1});
                }
            }
        }
        sort(event.begin(),event.end());
        int mx=0;
        int cur=0;
        for(auto ev:event) {
            cur-=ev.second;
            mx=max(mx,cur);
        }
        ans[j]+=mx;
    }
    for(int i=0;i<q;i++) {
        scanf("%d",&w[i]);
        int j=0;
        while((w[i]&(1<<j))==0) {
            j++;
        }
        printf("%d\n",ans[j]);
    }
    return 0;
}