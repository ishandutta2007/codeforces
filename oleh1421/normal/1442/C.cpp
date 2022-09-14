#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll mod=998244353;
const int L=21;
int dist[N][L];
vector<int>g[N];
vector<int>rg[N];
pair<int,int>d[N][2];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;++i){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<L;j++){
            dist[i][j]=-1;
        }
    }
    dist[1][0]=0;
    deque<pair<int,int> >q;
    q.push_back({1,0});
    while (!q.empty()){
        int v=q.back().first;
        int t=q.back().second;
        q.pop_back();
        if (t+1<L && dist[v][t+1]==-1){
            dist[v][t+1]=dist[v][t];
            q.push_back({v,t+1});
        }
        if (t%2){
            for (int to:rg[v]){
                if (dist[to][t]==-1){
                    dist[to][t]=dist[v][t]+1;
                    q.push_front({to,t});
                }
            }
        } else {
            for (int to:g[v]){
                if (dist[to][t]==-1){
                    dist[to][t]=dist[v][t]+1;
                    q.push_front({to,t});
                }
            }
        }
    }
    ll res=-1;
    for (int i=0;i<L;i++){
        if (dist[n][i]!=-1){
            ll cur=(1ll<<i)-1ll+dist[n][i];
            if (res==-1 || res>cur) res=cur;
        }
    }
    if (res!=-1) cout<<res<<endl;
    else {
        set<pair<pair<int,int>,pair<int,int> > >st;
        for (int i=1;i<=n;i++){
            d[i][0]={mod,mod};
            d[i][1]={mod,mod};
        }
        d[1][0]={0,0};
        d[1][1]={1,0};
        for (int i=1;i<=n;i++){
            st.insert({d[i][0],{i,0}});
            st.insert({d[i][1],{i,1}});
        }
        while (!st.empty()){
            auto cur=(*st.begin()).second;
            st.erase(st.begin());
            int v=cur.first;
            int t=cur.second;
            pair<int,int>Cur=d[v][t];
            Cur.first++;
            if (d[v][t^1]>Cur){
                st.erase({d[v][t^1],{v,t^1}});
                d[v][t^1]=Cur;
                st.insert({d[v][t^1],{v,t^1}});
            }
            if (t){
                for (int to:rg[v]){
                    pair<int,int>cur=d[v][t];
                    cur.second++;
                    if (d[to][t]>cur){
                        st.erase({d[to][t],{to,t}});
                        d[to][t]=cur;
                        st.insert({d[to][t],{to,t}});
                    }
                }

            } else {
                for (int to:g[v]){
                    pair<int,int>cur=d[v][t];
                    cur.second++;
                    if (d[to][t]>cur){
                        st.erase({d[to][t],{to,t}});
                        d[to][t]=cur;
                        st.insert({d[to][t],{to,t}});
                    }
                }
            }

        }
        ll res=1ll;
        pair<int,int> cur=min(d[n][0],d[n][1]);
        for (int i=0;i<cur.first;i++){
            res*=2ll;
            res%=mod;
        }
        res--;
        res+=cur.second;
        res%=mod;
        cout<<res<<endl;

    }

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
7 4
1 4 7 3 6 2 5
3 2 4 5
*/