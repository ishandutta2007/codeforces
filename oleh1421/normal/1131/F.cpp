//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
vector<int>v[200001];
int component[200001];
void unite(int x,int y){
     ///x->y
     if (v[component[x]].size()>v[component[y]].size()) swap(x,y);
     int componentX=component[x];
     for (auto i:v[componentX]){
        v[component[y]].push_back(i);
        component[i]=component[y];
     }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) component[i]=i,v[i]={i};

    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        unite(a,b);
    }
    for (auto i:v[component[1]]) cout<<i<<" ";
    return 0;
}