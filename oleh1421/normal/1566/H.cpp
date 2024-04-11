//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define endl '\n'
const int N=2000001;
const int MX=101;
const int mod=1000000007;
int rl[N];
int p[N];
int ans[N];
int d[N];
int msk[N];
vector<int>g[N];
vector<pair<int,vector<int> > >can[N];
int ind[N];
void solve(){
    int c,n;cin>>c>>n;
    for (int i=1;i<=c;i++) p[i]=i;
    rl[1]=1;
    g[1].push_back(1);
    for (int i=2;i<=c;i++){
        if (p[i]==i){
            for (int j=i*2;j<=c;j+=i) p[j]=i;
        }
        if ((i/p[i])%p[i]==0) rl[i]=rl[i/p[i]];
        else rl[i]=rl[i/p[i]]*p[i];
        g[rl[i]].push_back(i);
//        cout<<i<<" "<<rl[i]<<endl;
    }
    vector<int>ask;
    for (int i=1;i<=c;i++){
        if (rl[i]==i) ask.push_back(i);

    }
    cout<<ask.size()<<" ";
    for (int i:ask) cout<<i<<" ";
    cout<<endl;
    for (int i:ask){
        int x;cin>>x;
        ans[i]=x;
    }
    for (int i=1;i<=c;i++){
        ans[i]=ans[rl[i]];
//        cout<<i<<" "<<ans[i]<<endl;
    }
    for (int i=2;i<=c;i++){
        if (i==rl[i]) ans[i]^=ans[1];
    }
    d[1]=ans[1];
    for (int i=2;i<=c;i++){
        if (i==rl[i]){
            for (int j=i;j<=c;j+=i){
                if (rl[j]==j) d[j]^=ans[i];
            }
//            cout<<i<<" "<<d[i]<<endl;
        }
    }
    for (int i=c;i>=1;i--){
        if (rl[i]==i){
            msk[i]=d[i];
            for (int j=i*2;j<=c;j+=i){
                if (rl[j]==j) msk[i]^=msk[j];
            }
//            cout<<i<<" "<<msk[i]<<endl;
        }
    }
    vector<int>ans;
    int TOT=0;
    for (int i=1;i<=c;i++){
        if (i==rl[i]){
            vector<pair<int,bitset<260> > >basis;
            vector<int>bad;
            for (int j=0;j<g[i].size();j++){
                int cur=g[i][j];
                for (auto &y:basis) cur=min(cur,(cur^y.first));
                if (cur==0) bad.push_back(j);
                else {
                    bitset<260>bt=0;
                    bt[j]=1;
                    int cur=g[i][j];
                    for (auto &y:basis) {
                        if ((cur^y.first)<cur){
                            cur^=y.first;
                            bt^=y.second;
                        }
                    }
                    basis.push_back({cur,bt});
                }
            }
            if (bad.empty()){
                bitset<260>bt;
                int cur=msk[i];
                for (auto x:basis){
                    if ((x.first^cur)<cur){
                        cur^=x.first;
                        bt^=x.second;
                    }
                }
                for (int j=0;j<g[i].size();j++) {
                    if (bt[j]) ans.push_back(g[i][j]);
                }
                continue;
            }
            for (int it=1;it<=20;it++){
                bitset<260>bt;
                int cur=msk[i];
                for (int j:bad){
                    if (rand()%2){
                        cur^=g[i][j];
                        bt[j]=(!bt[j]);
                    }
                }
                for (auto x:basis){
                    if ((x.first^cur)<cur){
                        cur^=x.first;
                        bt^=x.second;
                    }
                }
                if (cur==0){
                    vector<int>v;
                    for (int j=0;j<g[i].size();j++) {
                        if (bt[j]) v.push_back(g[i][j]);
                    }
                    can[i].push_back({v.size(),v});
                }
            }
            sort(can[i].begin(),can[i].end());
//            cout<<can[i].size()<<endl;
//            for (auto j:can[i]) cout<<j.size()<<" ";
//            cout<<endl;
        }
    }
    n-=ans.size();
    for (int i=1;i<=c;i++) ind[i]=0;
    vector<int>check;
    for (int i=1;i<=c;i++){
        ind[i]=0;
        if (!can[i].empty()){
            check.push_back(i);
            n-=(int)can[i][0].second.size();
        }
    }
    while (n>0){
        for (int i:check){
            if (ind[i]+1<can[i].size() && n>=can[i][ind[i]+1].first-can[i][ind[i]].first){
                n-=can[i][ind[i]+1].first-can[i][ind[i]].first;
                ind[i]++;
            }
        }
    }





    for (int i=1;i<=c;i++){
        if (!can[i].empty()){
            for (int j:can[i][ind[i]].second) ans.push_back(j);
        }
    }

//    cout<<TOT<<endl;
    sort(ans.begin(),ans.end());
    for (int i:ans) cout<<i<<" ";
    cout<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}

/**
4 4 2 11 4 4 1
**/