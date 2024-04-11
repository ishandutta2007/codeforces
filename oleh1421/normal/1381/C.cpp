//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
pair<int,int> b[N];
int c[N];
int a[N];
int cnt[N];
vector<int>g[N];
int n,x,y;
void cls(){
    for (int i=0;i<=n+1;i++) a[i]=c[i]=cnt[i]=0,g[i].clear();
}
void solve(){
    cin>>n>>x>>y;
    y-=x;
    for (int i=1;i<=n;i++) cin>>c[i],cnt[c[i]]++,g[c[i]].push_back(i);
    set<pair<int,int> >st;
    for (int i=1;i<=n+1;i++){
        st.insert({-(int)g[i].size(),i});
    }
    for (int i=0;i<x;i++){
        int cur=(*st.begin()).second;
        a[g[cur].back()]=c[g[cur].back()];
        g[cur].pop_back();
        st.erase(st.begin());
        st.insert({-(int)g[cur].size(),cur});
    }
    vector<pair<int,int> >u;
    for (int i=1;i<=n;i++){
        if (!a[i]){
            u.push_back({c[i],i});
        }
    }
    sort(u.begin(),u.end());
    int add=((int)u.size()+1)/2;
    for (int i=0;i<u.size() && y;i++){
        int nxt=(i+add)%u.size();
        if (u[i].first!=u[nxt].first){
            a[u[i].second]=u[nxt].first;
            y--;
        }
    }
    if (y){
        cls();
        cout<<"NO\n";
        return;
    }
//    if (x) exit(1);
    int A=1;
    while (cnt[A]) A++;
    for (int i=1;i<=n;i++){
        if (!a[i]) a[i]=A;
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    cls();

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
4 0 4
1 2 2 3
*/