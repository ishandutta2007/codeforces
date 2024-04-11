#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
unordered_map<int,int>mp;
const int N=210001;
int a[N];
int dist[2][N];
vector<int>g[N];
bool used[N];
int n,m,k;
void bfs(int s,int j){
    for (int i=1;i<=n;i++) used[i]=false;
    queue<int>q;
    q.push(s);
    dist[j][s]=0;
    used[s]=true;
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (auto to:g[v]){
            if (!used[to]){
                dist[j][to]=dist[j][v]+1;
                q.push(to);
                used[to]=true;
            }
        }
    }
}
int x[N];
int y[N];
int mx[N];
int suf[N];
int suf1[N];
int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++) cin>>a[i];
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(1,0);
    bfs(n,1);
    for (int i=0;i<=n;i++) mx[i]=-1000000001;
    int res=0;
    for (int i=1;i<=k;i++){
        x[i]=dist[0][a[i]];
        y[i]=dist[1][a[i]];
//        cout<<i<<" "<<a[i]<<" "<<x[i]<<" "<<y[i]<<endl;
        if (mx[x[i]]){
            res=max(res,x[i]+min(y[i],mx[x[i]]));
        }
        mx[x[i]]=max(mx[x[i]],y[i]);
    }
    suf[n+1]=-1000000001;
    suf1[n+1]=-1000000001;
    for (int i=n;i>=0;i--){
        suf[i]=suf[i+1];
        suf1[i]=suf1[i+1];
        if (mx[i]>=suf[i]){
            suf1[i]=suf[i];
            suf[i]=mx[i];
        } else if (mx[i]>suf1[i]){
            suf1[i]=mx[i];
        }
//        cout<<i<<" "<<suf[i]<<" "<<suf1[i]<<endl;
    }
    int cur=0;
    for (int i=18;i>=0;i--){
        if (cur+(1<<i)>n) continue;
        cur+=(1<<i);
        bool ok=false;
        for (int j=0;j<=n;j++){
            if (mx[j]<0) continue;
            int l=max(cur-mx[j]-1,0);
            int ch=suf[l];
            if (l<=j && suf[l]==mx[j]) ch=suf1[l];
            if (ch>=cur-j-1){
                ok=true;
                break;
            }
        }
        if (!ok) cur-=(1<<i);
    }
    res=max(res,cur);
    res=min(res,dist[1][1]);
    cout<<res;
    return 0;
}
/*
5 5 2
1 5
1 2
2 3
3 4
3 5
2 4
*/