#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define int long long
const long long mod=764983111ll;
const long long mod2=764983113ll;
vector<int>a[5155];
map<ll,ll>to;
map<int,int>mp;
ll s[5155];
int cycle_mask[200001];
vector<ll> cycle[200001];
int timer=0;
vector<int>u;
int n;
bool used[(1<<15)+10][5050];
void F(int mask,int pos){
    if (used[mask][pos]) return;
    used[mask][pos]=true;
    if (mask+1==(1<<n)){
        vector<pair<int,pair<ll,ll> > >ans;
        for (auto i:u){
            for (int j=0;j+1<cycle[i].size();j++){
                ans.push_back({mp[cycle[i][j]],{cycle[i][j],mp[cycle[i][j+1]]}});
            }
        }
        sort(ans.begin(),ans.end());
        cout<<"Yes\n";
        for (auto i:ans) cout<<i.second.first<<" "<<i.second.second<<endl;
        exit(0);
    }
    if (pos==timer+1) return;
    F(mask,pos+1);
    if ((mask&cycle_mask[pos])==0){
        u.push_back(pos);
        F(mask|cycle_mask[pos],pos+1);
        u.pop_back();
    }
}
bool used_mask[(1<<15)+10];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    ll sum=0ll;
    for (int i=1;i<=n;++i){
        int k;cin>>k;
        for (int j=1;j<=k;j++){
            int x;cin>>x;
            a[i].push_back(x);
            mp[x]=i;
            sum+=x*1ll;
            s[i]+=x*1ll;
        }
    }
    if (sum%n){
        cout<<"No";
        return 0;
    }
    ll c=sum/n;
    vector<ll>num;
    for (int i=1;i<=n;i++){
        for (auto x:a[i]){
            ll y=c-s[i]+x*1ll;
            if (x==y) to[x]=x;
            if (mp[x]==mp[y] && x!=y) continue;
            to[x]=y;
            num.push_back(x*1ll);
        }
    }
    bool out=false;
    for (auto x:num){
        int mask=(1<<(mp[x]-1));
        ll cur=to[x];
        bool ok=true;
        vector<ll>v={x};
        while (cur!=x){
            if (cur==0 || mp[cur]==0){
                ok=false;
                break;
            }
            v.push_back(cur);
            if (mask&(1<<(mp[cur]-1))){
                ok=false;
                break;
            }
            mask|=(1<<(mp[cur]-1));
            cur=to[cur];
        }
        if (used_mask[mask]) continue;
        if (!ok) continue;
        used_mask[mask]=true;
        timer++;
        cycle_mask[timer]=mask;
        cycle[timer]=v;
        cycle[timer].push_back(x);
        reverse(cycle[timer].begin(),cycle[timer].end());
        if (n==15 && x==1000000000) out=true;
    }
   // if (out) cout<<timer<<endl;
    F(0,1);
    cout<<"No";
    return 0;
}