#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=764983111ll;
const long long mod2=764983113ll;
int dsu[200001];
int get(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=get(dsu[x]);
}
int res=0;
void unite(int a,int b){
    a=get(a);
    b=get(b);
    if (a!=b){
        dsu[a]=b;
        res++;
    }
}
set<int>st;
map<pair<int,int>,bool>mp;
int fi=0;
void bfs(int s){
    queue<int>q;
    q.push(s);
    st.erase(s);
    while (!q.empty()){
        int v=q.front();
        dsu[v]=fi;
        q.pop();
        vector<int>cur;
        for (auto to:st){
            if (mp[{v,to}]) continue;
            q.push(to);
            cur.push_back(to);
        }
        for (auto to:cur) st.erase(to);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    vector<pair<int,int> >u;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        u.push_back({a,b});
        mp[{a,b}]=true;
        mp[{b,a}]=true;
    }
    for (int i=1;i<=n;i++) st.insert(i);
    for (int i=1;i<=n;i++){
        if (!dsu[i]){
            fi=i;
           // st.erase(fi);
            bfs(i);

        }
    }
    for (auto cur:u){
        unite(cur.first,cur.second);
    }
    cout<<res;
    return 0;
}