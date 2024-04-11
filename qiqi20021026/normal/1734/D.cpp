#include"bits/stdc++.h"

using namespace std;

typedef long long LL;

LL n,m,a[220000];

LL solve(){
    cin>>n>>m;
    for (LL i=1;i<=n;++i){
        cin>>a[i];
    }
    LL x=0,y=0;
    vector<pair<LL,LL>> p1,p2;
    for (LL i=m+1;i<=n;++i){
        x+=a[i];
        y=min(x,y);
        if (x>0){
            p1.push_back({x,y});
            x=y=0;
        }
    }
    p1.push_back({x,y});
    x=0,y=0;
    for (LL i=m-1;i;--i){
        x+=a[i];
        y=min(x,y);
        if (x>0){
            p2.push_back({x,y});
            x=y=0;
        }
    }
    p2.push_back({x,y});
    LL i=0,j=0;
    LL s=a[m];
    for (;i<p1.size()&&j<p2.size();){
        if (s+p1[i].second>=0){
            s+=p1[i].first;
            ++i;
            continue;
        }
        if (s+p2[j].second>=0){
            s+=p2[j].first;
            ++j;
            continue;
        }
        return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    LL T; cin>>T;
    while (T--) cout<<(solve()?"YES":"NO")<<'\n';

    return 0;
}