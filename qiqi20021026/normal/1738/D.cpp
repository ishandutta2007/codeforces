#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int mod=998244353;
#define N 120'000

int n;
bool vis[N];
vector<int> vec[N],ans;
void work(int t,int o){
    int lst=0;
    for (int i:vec[t]){
        if (vec[i].empty()){
            ans.push_back(i);
            vis[i]=o;
        }
        else lst=i;
    }
    if (lst){
        ans.push_back(lst);
        vis[lst]=o;
        work(lst,!o);
    }
}

void solve(){
    cin>>n;
    for (int i=1;i<=n;++i){
        int x; cin>>x;
        vec[x].push_back(i);
    }
    work(n+1,1);
    work(0,0);
    int k=0; for (;vis[k+1];++k);
    cout<<k<<'\n';
    for (int i:ans) cout<<i<<' '; cout<<'\n';
    ans.clear();
    for (int i=0;i<=n+1;++i){
        vec[i].clear();
        vis[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}