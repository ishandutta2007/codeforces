#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000100;
const ll mod=998244353;
int n,m;
vector<vector<int>>p;
bool used[N];
bool ok(int x){
    for (int i=0;i<m;i++) used[i]=false;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (p[i][j]>=x){
                if (used[j]) return true;
                used[j]=true;
            }
        }
    }
    return false;
}
void solve(){
    cin>>m>>n;
    p.clear();
    p.resize(n);
    for (int i=0;i<n;i++){
        p[i].resize(m,0);
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++) cin>>p[j][i];
    }
    int L=0,R=1000000001;
    for (int i=0;i<n;i++){
        int mx=0;
        for (int j:p[i]) mx=max(mx,j);
        R=min(R,mx+1);
    }
    while (R-L>1){
        int mid=(L+R)/2;
        if (ok(mid)) L=mid;
        else R=mid;
    }
    cout<<L<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//A[j] - >
//(a+b1)%M+(b2+c)%M<(a+c)%M