#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(time(NULL));
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N=500010;
const ll mod=32768;
int d[N];
vector<int>g[mod];

void solve(){
    int n;cin>>n;
    cout<<d[n]<<" ";
}
int main() {

    for (int i=0;i<mod;i++){
        g[(i+1)%mod].push_back(i);
        g[(i*2)%mod].push_back(i);
    }
    for (int i=0;i<mod;i++) d[i]=-1;
    d[0]=0;
    queue<int>q;
    q.push(0);
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (int to:g[v]){
            if (d[to]==-1){
                d[to]=d[v]+1;
                q.push(to);
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
1000000000

3 4 8


3 12 24

19

**/