//#pragma GCC opitmize ("Ofast")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100050;
vector<int>g[N];
bool used[N];
int mt[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        used[i]=false;
        int k;cin>>k;
        g[i].clear();
        g[i].resize(k);
        for (int j=0;j<k;j++) cin>>g[i][j];
    }
    for (int i=1;i<=n;i++){
        mt[i]=-1;
        for (auto to:g[i]){
            if (!used[to]){
                mt[i]=to;
                used[to]=true;
                break;
            }
        }
    }
    int a=-1;
    int b=-1;
    for (int i=1;i<=n;i++){
        if (!used[i]){
            b=i;
            break;
        }
    }
    for (int i=1;i<=n;i++){
        if (mt[i]==-1) a=i;
    }
    if (a==-1 && b==-1) cout<<"OPTIMAL\n";
    else {
        cout<<"IMPROVE\n";
        cout<<a<<" "<<b<<endl;
    }
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
8889
3
333 998 1
*/