//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define random vector_of_random_numbers
#define y1 y_1
typedef long long ll;
using namespace std;
int a[300001];
int b[300001];
int c[300001];
vector<int>gr[300001];
vector<int>g[300001];
bool ok(int i,int j){
    set<int>st;
    st.insert(a[i]);
    st.insert(b[i]);
    st.insert(c[i]);
    st.insert(a[j]);
    st.insert(b[j]);
    st.insert(c[j]);
    return (st.size()<=4);
}
vector<int>p;
bool used[300001];
void dfs(int v){
    if (used[v]) return;
    used[v]=true;
    p.push_back(v);
    for (auto to:g[v]) dfs(to);
}
bool used1[300001];
int cnt[300001];
int nxt(int i,int j){
    used1[a[i]]=true;
    used1[b[i]]=true;
    used1[c[i]]=true;
    int res=0;
    if (!used1[a[j]]) res=a[j];
    else if (!used1[b[j]]) res=b[j];
    else res=c[j];
    used1[a[i]]=used1[b[i]]=used1[c[i]]=false;
    return res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n-2;i++){
        cin>>a[i]>>b[i]>>c[i];
        gr[a[i]].push_back(i);
        gr[b[i]].push_back(i);
        gr[c[i]].push_back(i);
    }
    for (int i=1;i<=n-2;i++){
        set<int>v;
        for (auto x:gr[a[i]]) v.insert(x);
        for (auto x:gr[b[i]]) v.insert(x);
        for (auto x:gr[c[i]]) v.insert(x);
        for (auto x:v){
            if (x==i) continue;
            if (ok(i,x)) g[i].push_back(x);
        }
    }
    int start=0;
    for (int i=1;i<=n-2;i++){
        if (g[i].size()==1) start=i;
    }
    dfs(start);
    vector<int>ans;
    vector<pair<int,int> >f;
    f.push_back({gr[a[p[0]]].size(),a[p[0]]});
    f.push_back({gr[b[p[0]]].size(),b[p[0]]});
    f.push_back({gr[c[p[0]]].size(),c[p[0]]});
    sort(f.begin(),f.end());
    for (auto i:f) ans.push_back(i.second);
    for (int i=1;i<p.size();i++){
        ans.push_back(nxt(p[i-1],p[i]));
    }
    for (auto i:ans) cout<<i<<" ";
    return 0;
}