#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int dsu[2000001];
int dsu_find(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=dsu_find(dsu[x]);
}
void dsu_unite(int x,int y){
     if (dsu_find(x)!=dsu_find(y)){
         dsu[dsu_find(x)]=dsu_find(y);
     }
}
int32_t main() {
    int n,m;cin>>n>>m;
    int a,b,c;cin>>a>>b>>c;
    vector<pair<int,pair<int,int> > >v;
    for (int i=2;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        v.push_back({c,{a,b}});
    }
    sort(v.begin(),v.end());
    int res=1000000000;
    for (int i=1;i<=n;i++) dsu[i]=i;
    for (int i=0;i<m-1;i++){
        dsu_unite(v[i].second.first,v[i].second.second);
        if (dsu_find(a)==dsu_find(b)){
            res=v[i].first;
            break;
        }
    }
    cout<<res;
    return 0;
}
//20000000000000