#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
///#define int long long
using namespace std;
int a[1000001];
int b[1000001];
vector<int>g[1000001];
int t[3000001];
void built(int v,int l,int r){
     if (l==r){
         if (g[l].empty())
            t[v]=10000000;
         else
            t[v]=
            g[l].back();

         return;
     }
     int m=(l+r)/2;
     built(v+v,l,m);
     built(v+v+1,m+1,r);
     t[v]=min(t[v+v],t[v+v+1]);
}
void upd(int v,int l,int r,int pos){
     if (l>pos || r<pos) return;
     if (l==r){
        if (g[l].empty()) t[v]=10000000;
        else t[v]=g[l].back();
        return;
     }
     int m=(l+r)/2;
     upd(v+v,l,m,pos);
     upd(v+v+1,m+1,r,pos);
     t[v]=min(t[v+v],t[v+v+1]);
}
int get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 10000000;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return min(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
     int n;cin>>n;
     for (int i=1;i<=n;i++) cin>>a[i];
     for (int i=1;i<=n;i++) cin>>b[i];
     for (int i=1;i<=n;i++) g[i].clear();
     for (int i=n;i>=1;i--) g[a[i]].push_back(i);
     built(1,1,n);
     for (int i=1;i<=n;i++){
         if (g[b[i]].empty()){
            cout<<"NO";
            return;
         }
         int cur=g[b[i]].back();
         if (get(1,1,n,1,b[i])<cur){
             cout<<"NO";
             return;
         }
         g[b[i]].pop_back();
         upd(1,1,n,b[i]);

     }
     cout<<"YES";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
          solve();
          cout<<endl;
    }
    return 0;
}