#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=100010;
set<int>E[N];
vector<int>g[N];
bool del[N];
int cnt[N];
int a[N/100+10][N/100+10];
int ind[N];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=n;i++) g[i].clear(),del[i]=false,E[i].clear(),ind[i]=0;
    vector<pair<int,int> >VV;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        E[a].insert(b);
        E[b].insert(a);
        g[a].push_back(b);
        g[b].push_back(a);
        VV.push_back({a,b});
    }
    if (k<=100){
        set<pair<int,int> >st;
        for (int i=1;i<=n;i++){
            cnt[i]=g[i].size();
            st.insert({cnt[i],i});
        }
        while (!st.empty()){
            int v=(*st.begin()).second;
            if (cnt[v]>=k) break;
            st.erase(st.begin());
            del[v]=true;
            vector<int>C;
            for (int to:g[v]){
                if (!del[to]){
                    st.erase({cnt[to],to});
                    cnt[to]--;
                    st.insert({cnt[to],to});
                    C.push_back(to);
                }
            }
            if (cnt[v]<k-1 || (k+0ll)*(k-1ll)>2ll*m) continue;
            random_shuffle(C.begin(),C.end());
            bool ok=true;
            for (int i=0;i<C.size() && ok;i++){
                for (int j=i+1;j<C.size() && ok;j++){
                    if (E[C[i]].find(C[j])==E[C[i]].end()){
                        ok=false;
                    }
                }
            }
            if (ok){
                C.push_back(v);
                cout<<2<<endl;
                for (int i:C) cout<<i<<" ";
                cout<<endl;
                return;
            }
        }
        if (st.empty()) cout<<-1<<endl;
        else{
            cout<<1<<" "<<st.size()<<endl;
            for (auto i:st) cout<<i.second<<" ";
            cout<<endl;
        }
    } else {
        int cn=0;
        for (int i=1;i<=n;i++){
            if (g[i].size()>=k-1){
                ind[i]=++cn;
            }
        }
        for (int i=0;i<=cn;i++){
            for (int j=0;j<=cn;j++){
                a[i][j]=0;
            }
        }
        for (auto cur:VV){
            if (ind[cur.first] && ind[cur.second]){
                a[ind[cur.first]][ind[cur.second]]=1;
                a[ind[cur.second]][ind[cur.first]]=1;
            }
        }
        set<pair<int,int> >st;
        for (int i=1;i<=n;i++){
            cnt[i]=g[i].size();
            st.insert({cnt[i],i});
        }

        while (!st.empty()){
            int v=(*st.begin()).second;
            if (cnt[v]>=k) break;
    //        cout<<"OK\n"<<v<<endl;
            st.erase(st.begin());
            del[v]=true;
            vector<int>C;
            for (int to:g[v]){
                if (!del[to]){
                    st.erase({cnt[to],to});
                    cnt[to]--;
                    st.insert({cnt[to],to});
                    C.push_back(to);
                }
            }
            if (cnt[v]<k-1 || (k+0ll)*(k-1ll)>2ll*m) continue;
            random_shuffle(C.begin(),C.end());
            bool ok=true;
            for (int i=0;i<C.size() && ok;i++){
                for (int j=i+1;j<C.size() && ok;j++){
                    if (!a[ind[C[i]]][ind[C[j]]]){
                        ok=false;
                    }
                }
            }
            if (ok){
                C.push_back(v);
                cout<<2<<endl;
                for (int i:C) cout<<i<<" ";
                cout<<endl;
                return;
            }
        }
        if (st.empty()) cout<<-1<<endl;
        else{
            cout<<1<<" "<<st.size()<<endl;
            for (auto i:st) cout<<i.second<<" ";
            cout<<endl;
        }
    }

}
int32_t main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}