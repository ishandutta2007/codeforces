#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=5010;
vector<int>g[N];
int used[N];
vector<int>L;
vector<int>R;
void dfs(int v){
    if (used[v]==1) L.push_back(v);
    else R.push_back(v);
    for (auto to:g[v]){
        if (used[to] && used[to]!=used[v]) continue;
        if (used[to]){
            cout<<"NO\n";
            exit(0);
        }
        used[to]=used[v]%2+1;
        dfs(to);
    }
}
int dp[N][N];
int col[N];
void solve(){
    int n,m;cin>>n>>m;
    int n1,n2,n3;cin>>n1>>n2>>n3;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<pair<vector<int>,vector<int> > >B;
    for (int i=1;i<=n;i++){
        if (!used[i]){
            used[i]=1;
            L.clear();
            R.clear();
            dfs(i);
            if (L.size()>R.size()) swap(L,R);
            B.push_back({L,R});
        }
    }
    int sum=0;
    for (auto cur:B) sum+=cur.first.size();
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            dp[i][j]=-1;

        }
    }
    dp[0][sum]=0;
    for (int i=0;i<B.size();i++){
        int x=(int)B[i].second.size()-(int)B[i].first.size();
//        cout<<i<<" "<<x<<endl;
        for (int j=0;j<=n;j++){
//            cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            if (dp[i][j]!=-1){
                dp[i+1][j]=0;
            }
        }
        for (int j=0;j+x<=n;j++){
            if (dp[i][j]!=-1){
                dp[i+1][j+x]=1;
            }
        }
    }
    if (dp[B.size()][n2]==-1){
        cout<<"NO\n";
        return;
    }
    vector<int>a;
    vector<int>b;
    int last=n2;
    for (int i=B.size();i>=1;i--){
//        cout<<"OK "<<i<<" "<<n2<<" "<<dp[i][n2]<<endl;
        if (dp[i][n2]==0){
            for (auto x:B[i-1].first) a.push_back(x);
            for (auto x:B[i-1].second) b.push_back(x);
        } else {
            n2-=(int)B[i-1].second.size()-(int)B[i-1].first.size();
//            cout<<i<<" "<<n2<<endl;
            for (auto x:B[i-1].first) b.push_back(x);
            for (auto x:B[i-1].second) a.push_back(x);
        }
    }
    for (int i=0;i<b.size();i++){
        col[b[i]]=(i<n3)*2+1;
    }
    for (auto i:a) {
//        if (col[i]) exit(1);
        col[i]=2;

    }
    n2=last;
    for (int i=1;i<=n;i++){
        if (col[i]==1) n1--;
        else if (col[i]==2) n2--;
        else n3--;
        if (col[i]<1 || col[i]>3){
            exit(1);
        }
        for (auto to:g[i]){
            if (abs(col[to]-col[i])!=1){
                exit(1);
            }
        }
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++) cout<<col[i];
    cout<<endl;



}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
5 4
1 3 1
1 3
1 4
1 5
2 5
*/