//#pragma GCC opitmize ("Ofast")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200050;
const ll mod=998244353ll;
int p[N];
int c[N];
vector<int>d[N];
bool used[N];
int res=1000000001;
void relax(vector<int>v){
    int k=v.size();
    for (auto x:d[k]){
        vector<char>ok;
        ok.resize(x);
        for (int j=0;j<x;j++) ok[j]=true;
        for (int j=0;j<k;j++){
            if (v[j]!=v[j%x]) ok[j%x]=false;
        }
        for (int j=0;j<x;j++){
            if (ok[j]) res=min(res,x);
        }
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i],used[i]=false;
    for (int i=1;i<=n;i++) cin>>c[i];
    res=1000000001;
    for (int i=1;i<=n;i++){
        if (used[i]) continue;
        vector<int>v;
        v.push_back(c[i]);
        int cur=i;
        used[i]=true;
        while (p[cur]!=i){
            cur=p[cur];
            v.push_back(c[cur]);
            used[cur]=true;
        }
        relax(v);
    }
    cout<<res<<endl;
}
int32_t main()
{
    for (int i=1;i<N-10;i++){
        for (int j=i;j<N-10;j+=i) d[j].push_back(i);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//2 3 4 5 1
//3 4 5 1 2
//4 5 1 2 3

/*
1
8889
3
333 998 1
*/