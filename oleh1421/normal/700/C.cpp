//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=500010;
vector<pair<int,int> >g[N];
int c[N];
bool used[N];
pair<int,int>pr[N];
void dfs1(int v){
    used[v]=true;
    for (auto cur:g[v]){
        int to=cur.first;
        int ind=cur.second;
        if (!used[to]){
            pr[to]={v,ind};
            dfs1(to);
        }
    }
}
int res=-1;
vector<int>ans;
void upd(vector<int>v){
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    if (!v.empty() && v.back()==-1) v.pop_back();
    reverse(v.begin(),v.end());
    int sum=0;
    for (int i:v) {
        sum+=c[i];
    }
    if (res==-1 || sum<res){
        res=sum;
        ans=v;
    }
}
int n,m,s,t;
int tin[N];
int fup[N];
int timer=0;
bool B[N];
void dfs(int v,int last,int ban){
    tin[v]=fup[v]=++timer;
    for (auto cur:g[v]){
        int to=cur.first;
        int ind=cur.second;
        if (ind==ban) continue;
        if (!tin[to]){

            dfs(to,ind,ban);
            pr[to]={v,ind};
            fup[v]=min(fup[v],fup[to]);
//            cout<<"OOOK "<<v<<" "<<to<<" "<<fup[to]<<" "<<tin[v]<<endl;

            if (fup[to]>tin[v]) B[ind]=true;
        } else if (ind!=last && tin[to]<tin[v]){
            fup[v]=min(fup[v],tin[to]);
        }

    }

}

void check(int ban){
    for (int i=1;i<=n;i++) tin[i]=fup[i]=0,pr[i]={0,0};
    for (int i=1;i<=m;i++) B[i]=false;
    dfs(s,0,ban);
    if (!pr[t].first){
        upd({ban});
        return;
    }
    int last=t;
    while (last!=s){
        if (B[pr[last].second]) upd({ban,pr[last].second});
        last=pr[last].first;
    }
}
void solve(){
    cin>>n>>m;
    cin>>s>>t;

    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        cin>>c[i];
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    dfs1(s);
    if (!pr[t].first){
        cout<<0<<endl<<0<<endl;
        return;
    }
    vector<int>order;
    int last=t;
    while (last!=s){
        order.push_back(pr[last].second);
        last=pr[last].first;
    }
    check(-1);
//    cout<<res<<endl;
    for (int a:order){
        check(a);
    }
    cout<<res<<endl;
    if (ans.empty()) return;
    cout<<ans.size()<<endl;
    for (int i:ans) cout<<i<<" ";
    cout<<endl;

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/**
8
9 7 1 3 4 5 2 8

**/