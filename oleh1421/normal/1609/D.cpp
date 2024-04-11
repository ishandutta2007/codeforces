#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=1200010;
const ll inf=1e18;
const ll mod=998244353;
int dsu[N];
int sz[N];
int mx=1;
int add=0;
int get(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=get(dsu[x]);
}
void unite(int a,int b){
    a=get(a);
    b=get(b);
    if (a==b){
        add++;
        return;
    }
    dsu[a]=b;
    sz[b]+=sz[a];
//    cout<<"E "<<a<<" "<<b<<" "<<sz[b]<<endl;
    mx=max(mx,sz[b]);
}
void solve(int Case){
    int n,d;cin>>n>>d;
    for (int i=1;i<=n;i++) dsu[i]=i,sz[i]=1;
    for (int i=1;i<=d;i++){
        int a,b;cin>>a>>b;
        unite(a,b);
        vector<int>v;
        for (int j=1;j<=n;j++){
            if (get(j)==j) v.push_back(sz[j]);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int res=0;
        for (int i=0;i<v.size() && i<=add;i++) {
            res+=v[i];
//            cout<<v[i]<<endl;
        }
        cout<<res-1<<endl;
    }


}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**
problem B with higher constrains


3
1 R
5 R
10 R
100 G
3 G
7 G


1
4
2 3 1 4

8 1
1 3 5 2 4 7 6 8
1 8


1
5 2
-1 1 2 0 0


4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/