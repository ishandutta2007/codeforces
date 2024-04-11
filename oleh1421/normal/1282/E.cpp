#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
map<pair<int,int>,int>mp;
vector<int>g[300001];
vector<int>e[300001];
bool used[300001];
bool used1[300001];
int cnt[300001];
vector<int>u;
void dfs(int v){
    used[v]=true;
    u.push_back(v);
    for (auto to:e[v]){
        if (!used[to]) dfs(to);
    }
}
vector<int>q;
void solve(){
    mp.clear();
    int n;cin>>n;
    u.clear();
    q.clear();
    for (int i=0;i<=n;i++){
        g[i].clear();
        e[i].clear();
        used[i]=false;
        used1[i]=false;
    }
    set<pair<int,int> >st;
    for (int i=1;i<=n-2;i++){
        int a,b,c;cin>>a>>b>>c;
        if (a>b) swap(a,b);
        if (b>c) swap(b,c);
        if (a>b) swap(a,b);
        st.insert({a,b});
        st.insert({b,c});
        st.insert({a,c});
        int x=0;
        x=mp[{a,b}];
        if (x){
            g[i].push_back(x);
            g[x].push_back(i);
            st.erase({a,b});
        } else {
            mp[{a,b}]=i;
        }
        x=mp[{a,c}];
        if (x){
            g[i].push_back(x);
            g[x].push_back(i);
            st.erase({a,c});
        } else {
            mp[{a,c}]=i;
        }
        x=mp[{b,c}];
        if (x){
            g[i].push_back(x);
            g[x].push_back(i);
            st.erase({b,c});
        } else {
            mp[{b,c}]=i;
        }
    }
    if (n==3){
        cout<<"1 2 3\n";
        cout<<1<<endl;
        return;
    }
    for (auto cur:st){
        e[cur.first].push_back(cur.second);
        e[cur.second].push_back(cur.first);
        //cout<<cur.first<<" "<<cur.second<<endl;
    }
    dfs(1);
    for (auto i:u) cout<<i<<" ";
    cout<<endl;
    set<pair<int,int> >cur;
    for (int i=1;i<=n-2;i++){
        cnt[i]=g[i].size();
        cur.insert({(int)g[i].size(),i});
    }
    while (!cur.empty()){
        int v=(*cur.begin()).second;
        cnt[v]=0;
        q.push_back(v);
        cur.erase(cur.begin());
        for (auto to:g[v]){
            if (cnt[to]){
                cur.erase({cnt[to],to});
                cnt[to]--;
                cur.insert({cnt[to],to});
            }
        }
    }
    for (auto i:q) cout<<i<<" ";
    cout<<endl;

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
/*
1
7
1 2 7
2 3 7
3 5 7
3 4 5
5 6 7
*/