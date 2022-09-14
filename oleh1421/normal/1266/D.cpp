#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll sum[300001];
int main()
{
    //freopen("meetings.in","r",stdin);
    //freopen("meetings.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        ll a,b,c;cin>>a>>b>>c;
        sum[a]-=c;
        sum[b]+=c;
    }
    vector<int>v;
    for (int i=1;i<=n;i++){
        if (sum[i]<0) v.push_back(i);
    }
    vector<pair<pair<int,int>,ll> >ans;
    for (int i=1;i<=n;i++){
        if (sum[i]<=0) continue;
        while (sum[i]>0){
            int j=v.back();
            ll cur=min(sum[i],-sum[j]);
            sum[i]-=cur;
            sum[j]+=cur;
            ans.push_back({{j,i},cur});
            if (!sum[j]) v.pop_back();
        }
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first.first<<" "<<cur.first.second<<" "<<cur.second<<endl;


    return 0;
}