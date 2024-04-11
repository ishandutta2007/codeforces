//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long ll;
typedef long double ld;
///#define int ll
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
const int N=1000010;
int a[N];
int c[N];
int r[N];
int last[N];

void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],c[i]=0;
    for (int i=1;i<=n;i++) last[a[i]]=i;
    r[0]=0;
    for (int i=1;i<=n;i++) r[i]=last[a[i]];
    for (int i=1;i<=n;i++) r[i]=max(r[i-1],r[i]);
    int pos=1;
    vector<pair<int,int> >v;
    int R=0;
    while (pos<=n){
        if (last[a[pos]]==pos){
            pos++;
            continue;
        }
        v.push_back({pos,last[a[pos]]});
        int mx=pos+1;
        for (int i=max(pos+1,R);i<=last[a[pos]];i++){
            if (last[a[i]]>last[a[mx]]) mx=i;
        }
        R=last[a[pos]];
        if (last[a[mx]]<=last[a[pos]]){
            pos=last[a[pos]]+1;
            continue;
        }
        pos=mx;
    }
    int res=0;
    for (int i=1;i<=n;i++){
        if (r[i-1]>i) res++;
    }
//    for (auto cur:v) cout<<cur.first<<" "<<cur.second<<endl;
    vector<int>u;
    int cnt=1;
    for (int i=1;i<v.size();i++){

        if (v[i].first<v[i-1].second) cnt++;
        else {
            u.push_back(cnt);
            cnt=1;
        }
    }
    u.push_back(cnt);
    for (int i:u){
        res-=i-1;
    }
    cout<<res<<endl;



}
int32_t  main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
6
1 2 3 1 2 3

**/
/**
13
1 2 3 2 1 3 3 4 5 5 5 4 7
0 1 1 1 1 1 0 0 1 1 1 0 0
**/