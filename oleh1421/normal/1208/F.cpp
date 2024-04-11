//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
const int L=20;
int a[1000001];
vector<int>g[3000001];
int cnt[3000010];
//set<int>st;
bool used[3000010];
vector<int>u;
void dfs(int mask){
    if (used[mask]) return;
    used[mask]=true;
    u.push_back(mask);
    if (cnt[mask]>=2) return;
    cnt[mask]++;
    for (int i=0;i<=L;i++){
        if (mask&(1<<i)){
            dfs(mask^(1<<i));
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxx=0;

    for (int i=n;i>=1;i--){
        if (i+2<=n){
            int mask=0;
            for (int j=L;j>=0;j--){
                if (a[i]&(1<<j)) continue;
                if (cnt[mask^(1<<j)]>=2) mask^=(1<<j);
            }
            maxx=max(maxx,(mask^a[i]));
        }
        dfs(a[i]);
        for (auto j:u) used[j]=false;
        u.clear();
    }
    cout<<maxx;
    return 0;
}