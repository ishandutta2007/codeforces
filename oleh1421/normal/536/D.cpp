//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=4010;
const ll inf=1'000'000'000'000'000'001ll;
int n,m,s,t;
ll p[N];
vector<pair<int,ll> >g[N];
ll d[2][N];
int cnt[2];
void dij(int s,int j){
    for (int i=1;i<=n;i++) d[j][i]=inf;
    d[j][s]=0;
    set<pair<ll,int> >st;
    for (int i=1;i<=n;i++) st.insert({d[j][i],i});
    while (!st.empty()){
        int v=(*st.begin()).second;
        st.erase(st.begin());
        for (auto cur:g[v]){
            int to=cur.first;
            ll val=d[j][v]+cur.second;
            if (val<d[j][to]){
                st.erase({d[j][to],to});
                d[j][to]=val;
                st.insert({d[j][to],to});
            }
        }
    }
    set<ll>cord;
    for (int i=1;i<=n;i++) cord.insert(d[j][i]);
//    for (auto x:cord) cout<<x<<" ";
//    cout<<endl;
    map<ll,int>mp;
    cnt[j]=0;
    for (ll x:cord){
        mp[x]=cnt[j]++;
    }
    for (int i=1;i<=n;i++) d[j][i]=mp[d[j][i]];
}
vector<int>V[2][N];
ll dp[N][N][2];
void solve(){
    cin>>n>>m>>s>>t;
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dij(s,0);
    dij(t,1);
//    for (int i=1;i<=n;i++) cout<<"D "<<d[0][i]<<" "<<d[1][i]<<endl;
    for (int j=0;j<2;j++){
        for (int i=1;i<=n;i++) V[j][d[j][i]].push_back(i);
    }
    for (int i=cnt[0];i>=0;i--){
        for (int j=cnt[1];j>=0;j--){
            {
                dp[i][j][0]=-inf;
                bool can=false;
                ll sum=0ll;
                for (int t:V[0][i]){
                    if (d[1][t]>=j){
                        can=true;
                        sum+=p[t];
                    }
                }
                dp[i][j][0]=dp[i+1][j][0]+sum;
                if (can) dp[i][j][0]=max(dp[i][j][0],dp[i+1][j][1]+sum);
            }
            {
                dp[i][j][1]=inf;
                bool can=false;
                ll sum=0ll;
                for (int t:V[1][j]){
                    if (d[0][t]>=i){
                        can=true;
                        sum+=p[t];
                    }
                }
                dp[i][j][1]=dp[i][j+1][1]-sum;
                if (can) dp[i][j][1]=min(dp[i][j][1],dp[i][j+1][0]-sum);
            }
//            cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
        }
    }
    if (dp[0][0][0]>0){
        cout<<"Break a heart"<<endl;
    } else if (dp[0][0][0]<0){
        cout<<"Cry"<<endl;
    } else {
        cout<<"Flowers"<<endl;
    }
//    cout<<dp[0][0][0]<<endl;
}

int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}