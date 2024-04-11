#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=210;
vector<int>g[N];
int a[N][N];
int p[N];
int l[N];
int r[N];
int K[N];
int n;
bool solved=false;
bool used[N];
int open[N];
int cnt[N];
void F(int pos){
    if (solved) return;
    if (pos==n+1){
        for (int i=1;i<=n;i++) cout<<p[i]<<" ";
        cout<<endl;
        solved=true;
        return;
    }
    for (int i=1;i<=n;i++){
        if (used[i]) continue;
        bool ok=true;
        int cn=0;
        for (auto j:g[i]){
            if (cnt[j]+1==K[j]) cn++;
            if (open[j] && open[j]+K[j]<=pos){
                ok=false;
                break;
            }
        }
        if (pos>1 && cn!=1) ok=false;
        if (!ok) continue;
        p[pos]=i;
        used[i]=true;
        for (auto j:g[i]) cnt[j]++;
        vector<int>v;
        for (auto j:g[i]){
            if (open[j]) continue;
            v.push_back(j);
            open[j]=pos;
        }
        F(pos+1);
        for (auto j:v){
            open[j]=0;
        }
        for (auto j:g[i]) cnt[j]--;

        used[i]=false;
        p[pos]=0;
    }
}

void solve(){
    cin>>n;
    for (int i=1;i<=n;i++){
        l[i]=1;
        r[i]=n;
        p[i]=0;
        open[i]=0;
        used[i]=false;
        g[i].clear();
        for (int j=1;j<=n;j++){
            a[i][j]=0;
        }
    }
    for (int i=1;i<n;i++){
        int k;cin>>k;
        K[i]=k;
        for (int j=1;j<=k;j++){
            int x;cin>>x;
            a[i][x]=1;
            g[x].push_back(i);
        }
    }
    solved=false;
    F(1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
2
2 1 2
*/