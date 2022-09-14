#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
int a[300001];
int d[300001];
vector<int>g[300001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=-1;
    }
    queue<int>q;
    for (int i=1;i<=n;i++){
        int l=i-a[i];
        int r=i+a[i];
        int sum=0;
        if (l>0){
            g[l].push_back(i);
            sum+=(a[l]+a[i])%2;
        }
        if (r<=n){
            g[r].push_back(i);
            sum+=(a[r]+a[i])%2;
        }
        if (sum){
            q.push(i);
            d[i]=1;
        }
    }
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (auto to:g[v]){
            if (d[to]==-1){
                d[to]=d[v]+1;
                q.push(to);
            }
        }
    }
    for (int i=1;i<=n;i++) cout<<d[i]<<" ";
    return 0;
}