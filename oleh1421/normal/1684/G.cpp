//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
#define int ll
const int N=500105;
const ll inf=1e9;
const ll mod=1000000007;
const int L=20;
int t[N];
vector<int>x;
void Euclid(int a,int b,int &cnt){
    if (a<b) swap(a,b);
    if (b==0) return;
    a%=b;
    if (a) cnt++;
    Euclid(a,b,cnt);
}
bool used[N];
int mt[N];
vector<int>g[N];
bool dfs(int v){
    if (used[v]) return false;
    used[v]=true;
    for (int to:g[v]){
        if (mt[to]==-1 || dfs(mt[to])){
            mt[to]=v;
            return true;
        }
    }
    return false;
}
void solve(int Case){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>t[i];
    sort(t+1,t+n+1);
    vector<int>u,v;
    for (int i=1;i<=n;i++){
        if (2*t[i]>=m){
//            if (n>2) exit(1);
            cout<<-1<<endl;
            return;
        }
        if (3*t[i]>m){
            u.push_back(t[i]);
        } else {
            v.push_back(t[i]);
        }
    }
    if (u.size()>v.size()){
        cout<<-1<<endl;
        return;
    }
    sort(u.begin(),u.end());
    reverse(u.begin(),u.end());
    sort(v.begin(),v.end());
    for (int i=0;i<u.size();i++){
        if (u[i]*2+v[i]>m){
            cout<<-1<<endl;
            return;
        }
    }
    vector<pair<int,int> >X;
    for (int i=0;i<u.size();i++){
        for (int j=0;j<v.size();j++){
            if (u[i]%v[j]==0 && 2*u[i]+v[j]<=m){
                g[i].push_back(j);
            }
        }
    }
    for (int i=0;i<v.size();i++) mt[i]=-1;
    int cnt=0;
    for (int i=0;i<u.size();i++){
        for (int j=0;j<v.size();j++) used[j]=false;
        cnt+=dfs(i);
    }
    if (cnt!=u.size()){
        cout<<-1<<endl;
        return;
    }

//    for (int i=0;i<n;i++){
//        if (x[i]!=t[i+1]) exit(2);
//    }
    cout<<v.size()<<endl;
    for (int i=0;i<v.size();i++){
        if (mt[i]!=-1) {
            cout<<u[mt[i]]*2+v[i]<<" "<<u[mt[i]]+v[i]<<endl;
        } else {
            cout<<2*v[i]<<" "<<3*v[i]<<endl;
        }

    }

}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
1
7 3
1 1 2 1 3 3 5
1 4
4 5
2 4



**/