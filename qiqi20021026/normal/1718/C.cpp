#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 300000

LL n,m,a[N];
bool vis[N];
vector<LL> f[N];

struct node{
    LL x,y,z;
    node(LL x=0,LL y=0,LL z=0):x(x),y(y),z(z){}
    bool operator < (const node &p) const{
        return x<p.x;
    }
};
priority_queue<node> pq;

void ins(LL i,LL j){
    pq.push(node(f[i][j]*(n/i),i,j));
}

void qry(){
    while (!pq.empty()){
        auto [x,i,j]=pq.top();
        if (f[i][j]*(n/i)!=x){
            pq.pop();
            continue;
        }
        cout<<x<<'\n';
        break;
    }
}

void solve(){
    while (!pq.empty()) pq.pop();
    cin>>n>>m;
    for (LL i=0;i<n;++i) cin>>a[i];
    vector<LL> len;
    for (LL i=2;i<=n;++i){
        f[i].clear();
        if (vis[i]) continue;
        if (n%i!=0) continue;
        len.push_back(i);
        LL s=n/i;
        f[i]=vector<LL>(s);
        for (LL j=0;j<n;++j){
            f[i][j%s]+=a[j];
            ins(i,j%s);
        }
    }
    qry();
    while (m--){
        LL x,y; cin>>x>>y; --x;
        for (LL i:len){
            LL s=n/i;
            f[i][x%s]-=a[x];
        }
        for (LL i:len){
            LL s=n/i;
            a[x]=y;
            f[i][x%s]+=a[x];
            ins(i,x%s);
        }
        qry();
    }
}

void getpr(LL n){
    vector<LL> pr;
    for (LL i=2;i<=n;++i){
        if (!vis[i]){
            pr.push_back(i);
        }
        for (LL j:pr){
            if (i*j>n) break;
            vis[i*j]=1;
            if (i%j==0) continue;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    LL T; cin>>T;
    getpr(200000);
    while (T--) solve();
}