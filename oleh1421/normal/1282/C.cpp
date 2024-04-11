#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

void solve(){
    ll n,T,a,b;cin>>n>>T>>a>>b;
    vector<pair<int,int> >v(n);
    int sum=0;
    for (int i=0;i<n;i++) cin>>v[i].second,sum+=v[i].second;
    for (int i=0;i<n;i++) cin>>v[i].first;
    ll cntA=n-sum;
    ll cntB=sum;
    sort(v.begin(),v.end());
    v.push_back({T+1,-1});
    ll res=0;
    ll curA=0ll;
    ll curB=0ll;
    for (int i=0;i<=n;i++){
        ll t=v[i].first-1;
        ll cur=0ll;
        cur+=i;
        t-=curA*a+curB*b;
        if (t-cntA*a>=0){
            t-=cntA*a;
            cur+=cntA;
            cur+=min(cntB,(t/b));
            res=max(res,cur);
        } else if (t>=0){
            cur+=(t/a);
            res=max(res,cur);
        }
        if (v[i].second==0) curA++,cntA--;
        else curB++,cntB--;
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}