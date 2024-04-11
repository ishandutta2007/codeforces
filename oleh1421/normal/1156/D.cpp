#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
typedef long long ll;
using namespace std;
vector<pair<int,int> >g[300001];
int sz[200001];
int maxsz[200001];
bool used[200001];
vector<int>u;
void dfs(int v,int pr){
     sz[v]=1;
     u.push_back(v);
     maxsz[v]=0;
     for (auto x:g[v]){
         int to=x.first;
         if (to!=pr && !used[to]){
             dfs(to,v);
             sz[v]+=sz[to];
             maxsz[v]=max(maxsz[v],sz[to]);
         }
     }
}
ll cnt0=0;
ll cnt1=0;
void dfs1(int v,int pr,int ok,int last){
     if (last) cnt1++;
     else cnt0++;
     for (auto x:g[v]){
         int to=x.first;
         int c=x.second;
         if (to!=pr && !used[to]){
             if (!ok || last==c) dfs1(to,v,(ok || last!=c),c);
         }
     }
}
ll res=0;
ll res1=0;
int maxx=0;
int x=1;
void rec(int root,int deep){

     maxx=max(maxx,deep);
     u.clear();
     dfs(root,0);
     if (u.size()==1) return;
     int center=root;
     int minx=10000001;
     for (auto v:u){
        if (minx>max(maxsz[v],(int)u.size()-sz[v])){
            minx=max(maxsz[v],(int)u.size()-sz[v]);
            center=v;
        }
     }
    // cout<<res<<endl;
     int cn00=0;
     int cn01=0;
     int cn10=0;
     int cn11=0;
     used[center]=true;
     /*if (deep==x){
         cout<<center<<endl;
         x++;
     }*/
    // cout<<center<<endl;
     for (auto to:g[center]){
        if (used[to.first]) continue;
        cnt0=0;
        cnt1=0;
        dfs1(to.first,0,0,to.second);
        if (to.second){
            res+=cnt0;
            res1+=cnt1;
            res+=cnt1*(cn00+cn10)+cnt0*cn11;
            res1+=cnt1*cn11;
            cn10+=cnt0;
            cn11+=cnt1;
        }
        else {
           // cout<<"|| "<<cnt0*(cn00+cn11+cn01)+cnt1*cn00<<endl;
            res+=cnt1;
            res1+=cnt0;
            res+=cnt0*(cn11+cn01)+cnt1*cn00;
            res1+=cnt0*cn00;
            cn00+=cnt0;
            cn01+=cnt1;
        }
     }
     for (auto to:g[center]){
         if (!used[to.first]) rec(to.first,deep+1);
     }
}
int32_t main() {
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        /*int a=i;
        int b=i+1;
        int c=0;*/
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    rec(1,1);
    cout<<res+res1+res1<<endl;

    return 0;
}