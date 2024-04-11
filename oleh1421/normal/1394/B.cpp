//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int ban1[10][10][10][10];
vector<pair<int,int> >g[N];
vector<pair<int,int> >rg[N];
int cnt[10];
int get(int v,int u){
    pair<int,int>fnd={u,1000000001};
    return upper_bound(g[v].begin(),g[v].end(),fnd)-g[v].begin();
}
int res=0;
int c[10];
void F(int pos,int k){
    if (pos==k+1){
        for (int i=1;i<=k;i++){
            for (int j=1;j<=k;j++){
                if (ban1[i][j][c[i]][c[j]]) return;
            }
        }
        res++;
//        cout<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
        return;
    }
    for (int i=1;i<=pos;i++){
        c[pos]=i;
        F(pos+1,k);
        c[pos]=0;
    }
}
bool used[10][10];
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({c,b});
        rg[b].push_back({c,a});
    }
    for (int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
        sort(rg[i].begin(),rg[i].end());
    }
    for (int i=1;i<=n;i++){
        vector<pair<int,int> >u;
        for (int j=0;j<rg[i].size();j++){
            int A=g[rg[i][j].second].size();
            int B=get(rg[i][j].second,rg[i][j].first);
            for (int t=1;t<=k;t++){
                for (int g=1;g<=k;g++){
                    if (used[t][g]){
                        ban1[A][t][B][g]=true;
                    }
                }
            }
            used[A][B]=true;
        }

        for (int j=0;j<=k;j++){
            for (int t=0;t<=k;t++){
                used[j][t]=false;
            }
        }
    }
    F(1,k);
    cout<<res<<endl;
    return 0;
}