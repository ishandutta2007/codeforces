//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=85;
int a[N][N];
vector<pair<int,int> >g[N][N];
vector<int>order={1};
int used[N];
int res=2000000001;
int n,k;
void F(int need){
    if (!need){
        order.push_back(1);
        int sum=0;
        bool OK=true;
        for (int i=0;i+1<order.size();i++){
            bool ok=false;
            for (auto cur:g[order[i]][order[i+1]]){
                if (used[cur.second]) continue;
                sum+=cur.first;
                ok=true;
                break;
            }
            OK&=ok;
        }
        if (OK) res=min(res,sum);
        order.pop_back();
        return;
    }

    for (int i=1;i<=n;i++){
        used[i]++;
        order.push_back(i);
        F(need-1);
        order.pop_back();
        used[i]--;
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        vector<pair<int,int> >v;
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
            if (i!=j) v.push_back({a[i][j],j});
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int t=1;t<=n;t++){
                if (t==i || t==j) continue;
                g[i][j].push_back({a[i][t]+a[t][j],t});
            }
            sort(g[i][j].begin(),g[i][j].end());

        }
    }
    used[1]=1;
    F(k/2-1);
    cout<<res<<endl;
    return 0;
}